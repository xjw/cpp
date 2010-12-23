#include <iostream>
#include <vector>
#include <stack>
#include "bst.h"

using namespace std;

vector<int> findLongestPath(BSTNode<int> *root) {
  vector<int> path;
  if (root==NULL) return path;

  vector<int> left, right;
  left = findLongestPath(root->left);
  right = findLongestPath(root->right);
  path = left.size()>right.size()? left : right;
  path.push_back(root->data);
  return path;
}


vector<int> findLongestPathStack(BSTNode<int> *root) {
  vector<int> path;
  if (root=NULL) return path;

  stack<BSTNode<int> *> st;
  st.push(root);

  while(!st.empty()) {
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
  vector<int> path = findLongestPath(bt.root);
  for (vector<int>::reverse_iterator it=path.rbegin(); it!=path.rend(); ++it) {
    cout<<*it<<endl;
  }
  return 1;
}
