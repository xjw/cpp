/**
 * using divide conquer approach to convert a binary search tree to 
 * doubled linked list 
 *
 * Reference (very nice approach)
 * http://cslibrary.stanford.edu/109/TreeListRecursion.html
 */

#include <iostream>
#include "bst.h"

using namespace std;

void BST2DoubleLinkedList(BSTNode<int> *root, BSTNode<int> *prev, BSTNode<int> *head) {
  if (!root) return;
  BSTNode<int> *left, *right;
  left = root->left;
  right = root->right;

  BST2DoubleLinkedList(left, prev, head);
  
  root->left = prev;

  BST2DoubleLinkedList(right, root, head);
}

void printDoubleLinkedList(BSTNode<int> *head) {
  BSTNode<int> *p = head;
  while(p) {
    cout<< p->data; 
    p = p->right;
    if (p == head) break;
  }
    cout << endl;
}

BSTNode<int> *append(BSTNode<int> *a, BSTNode<int> *b) {
  if (!a) return b;
  if (!b) return a;

  BSTNode<int> *a_big = a->left;
  BSTNode<int> *b_big = b->left;

  a->left = b_big;
  b_big->right = a;

  a_big->right = b;
  b->left = a_big;
  return a;
}

BSTNode<int> * BST2DoubleLinkedListDivideAndConquer(BSTNode<int> *root) {
  if (!root) return NULL;

  BSTNode<int> *left, *right;
  left = BST2DoubleLinkedListDivideAndConquer(root->left);
  right = BST2DoubleLinkedListDivideAndConquer(root->right);

  root->left = root;
  root->right = root;

  left = append(left, root);
  left = append(left, right);
  return left;
}

int main() {
  BST<int> bt;
  bt.insert_item(5);
  bt.insert_item(3);
  bt.insert_item(6);
  bt.insert_item(2);
  bt.insert_item(4);
  bt.insert_item(1);
  BSTNode<int> *head = BST2DoubleLinkedListDivideAndConquer(bt.root);
  printDoubleLinkedList(head);
  // Segmentation fault because of destructor for bst class
  return 1;
}
