/**
 * convert sorted array to bst using recursion
 *
 * Reference
 * http://www.ihas1337code.com/2010/11/convert-sorted-array-into-balanced.html
 */

#include <iostream>
#include "bst.h"

using namespace std;

BSTNode<int> * array2BST(int a[], int l, int r) {
  if (l>r) return NULL;
  int m = l+(r-l)/2;
  BSTNode<int> *node = new BSTNode<int>(a[m]);
  node->left = array2BST(a, l, m-1);
  node->right = array2BST(a, m+1, r);
  return node;
}

int main() {
  int a[] = {1,2,3,4,5};
  BST<int> bst;
  bst.root = array2BST(a, 0, sizeof(a)/sizeof(a[0])-1);
  bst.printByLevel();
  return 1;
}
