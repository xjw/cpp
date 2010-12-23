/**
 * convert sorted list to bst
 * using bottom up approach
 * tricker recursion than the array to bst implementation
 *
 * Reference
 * http://www.ihas1337code.com/2010/11/convert-sorted-list-to-balanced-binary.html
 */

#include <iostream>
#include "bst.h"

using namespace std;

class listNode {
 public:
  listNode *next;
  int data;
  listNode(int d) : data(d) {next=NULL;}
};

BSTNode<int> * list2BST(listNode *&node, int l, int r) {
  // cout<<"l-"<<l<<" r-"<<r<<" node-"<<node->data<<endl;
  if (l>r) return NULL;
  BSTNode<int> *root, *left, *right;
  int m = l + (r-l)/2;
  left = list2BST(node, l, m-1);
  root = new BSTNode<int>(node->data);
  root->left = left;
  node = node->next;
  right = list2BST(node, m+1, r);
  root->right = right;
  return root;
}

int main() {
  listNode *head, *node;
  node = head = NULL;
  int n = 6;
  for (int i=n; i>0; i--) {
    node = new listNode(i);
    node->next = head;
    head = node;
  }
  BST<int> bst;
  bst.root = list2BST(head, 0, n-1);
  bst.printByLevel();
  return 1;
}
