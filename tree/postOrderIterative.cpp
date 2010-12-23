#include <iostream>
#include <stack>

#include "bst.h"

using namespace std;

// first implementation
void postOrderIterative(BSTNode<int> *root) {
  stack<BSTNode<int> *> st;
  BSTNode<int> *top, *prev;
  prev = root;
  st.push(root);
  while(!st.empty()) {
    top = st.top();
    if (!top || top->right == prev) {
      if (top) cout<<top->data<<endl;
      prev = top;
      st.pop();
    }
    else {
      st.push(top->right);
      st.push(top->left);
    }
  }
}

/**
 * learn from inorder iterative
 * http://web.cs.wpi.edu/~cs2005/common/iterative.inorder
 */
void postOrderIterative2(BSTNode<int> *root) {
  BSTNode<int> *top, *prev;
  stack<BSTNode<int> *> st;
  bool done = false;
  prev = root;
  while(!done) {
    if (root) {
      st.push(root);
      prev = root;
      root = root->left;
    }
    else {
      if (st.empty()) done = true;
      else {
        top = st.top();
        if (prev == top->left)
          root = top->right;
        else {
          cout<< top->data <<endl;
          st.pop();
        }
        prev = top;
      }
    }
  }
}

int main() {
  BST<int> bt;
  bt.insert_item(5);
  bt.insert_item(3);
  bt.insert_item(6);
  bt.insert_item(2);
  bt.insert_item(4);
  bt.insert_item(1);

  bt.printByLevel();
  cout<<endl;
  postOrderIterative(bt.root);
  cout<<endl;
  postOrderIterative2(bt.root);

  return 1;
}
