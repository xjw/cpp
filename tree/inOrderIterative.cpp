/**
 * http://web.cs.wpi.edu/~cs2005/common/iterative.inorder 
 * A very cool and simple iterative implementation
 */

#include <iostream>
#include <stack>

// #include "bst.h"

using namespace std;

void inOrderIterative(BSTNode<int> *root) {
  BSTNode<int> *top;
  stack<BSTNode<int> *> st;
  bool done = false;
  while(!done) {
    if (root) {
      st.push(root);
      root = root->left;
    }
    else {
      if (st.empty()) done = true;
      else {
        top = st.top();
        cout<<top->data<<endl;
        root = top->right;
        st.pop();
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
  inOrderIterative(bt.root);

  return 1;
}
