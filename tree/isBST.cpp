#include <iostream>
#include <limit.h>

using namespace std;

template <class T>
class TreeNode {
  TreeNode *left;
  TreeNode *right;
  T data;
  TreeNode(T value) {left=NULL; right=NULL; data=value;}
};

template <class T>
bool isBST(TreeNode<T> *root, T max, T min) {
  if (root == NULL) return true;
  return (root->data>=min && root->data<=max && 
          isBST(root->left, root->data, min) && 
          isBST(root->right, max, root->data));
}

int main() {
  TreeNode<T> *root = new TreeNode<int>(1);
  isBST(root, INT_MAX, INT_MIN);
  return 1;
}
