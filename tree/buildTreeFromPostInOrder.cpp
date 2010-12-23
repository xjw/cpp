/**
 * http://geeksforgeeks.org/forum/topic/given-inorder-and-postorder-traversals-construct-a-binary-tree 
 */

#include <iostream>
#include "bst.h"

using namespace std;


BSTNode<int> *buildTreeFromPostInOrder(int a[], int b[], int l1, int r1, int l2, int r2) {
  if (l1>r1 || l2>r2) return NULL;
  int m = b[r2];
  int i=l1;
  while(i<=r1 && a[i]!=m) i++;
  BSTNode<int> *root = new BSTNode<int>(m);
  root->left  = buildTreeFromPostInOrder(a, b, l1, i-1, l2, l2+i-1-l1);
  root->right = buildTreeFromPostInOrder(a, b, i+1, r1, l2+i-l1, r2-1);
  return root;
}

int search(int a[], int left, int right, int x) {
  for (int i=left; i<=right; ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

BSTNode<int> *buildTreeFromPostInOrderSmarter(int a[], int b[], int left, int right, int pos) {
  if (left>right) return NULL;
  int x = b[pos];
  int idx = search(a, left, right, x);
  BSTNode<int> *root = new BSTNode<int>(x);
  root->right = buildTreeFromPostInOrderSmarter(a, b, idx+1, right, pos-1);
  root->left  = buildTreeFromPostInOrderSmarter(a, b, left, idx-1, pos-(right-idx)-1);
  return root;
}

int main() {
  // int a[] = {1,2,4,6,7}; // inorder
  // int b[] = {1,2,7,6,4}; // postorder

  int a[] = {1,2,3,4,5,6,7}; // inorder
  int b[] = {1,3,2,5,7,6,4}; // postorder

  int n = sizeof(a)/sizeof(a[0]);
  BST<int> bst1;
  bst1.root = buildTreeFromPostInOrder(a, b, 0, n-1, 0, n-1);
  bst1.printByLevel();

  cout<<endl;

  BST<int> bst2;
  bst2.root = buildTreeFromPostInOrderSmarter(a, b, 0, n-1, n-1);
  bst2.printByLevel();

  return 1;
}
