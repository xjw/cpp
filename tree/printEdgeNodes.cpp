/**
 * REMEMBER TO CHECKOUT EXAMPLES on the link to understand
 * why is the modification
 * http://www.ihas1337code.com/2010/10/print-edge-nodes-boundary-of-binary.html 
 */

#include <iostream>
#include "bst.h"
using namespace std;

bool isLeafNode(BSTNode<int> *root) {
  return root && !root->left && !root->right;
}

void printNode(BSTNode<int> *root) {
  if (root)
    cout<< root->data << endl;
}

void printLeftEdgeNodes(BSTNode<int> *root, bool flag) {
  if (!root) return;
  if (flag || isLeafNode(root))
    printNode(root);
  printLeftEdgeNodes(root->left, flag);
  // printLeftEdgeNodes(root->right, false);
  printLeftEdgeNodes(root->right, (flag && !root->left)); // this is for certain scenario
}

void printRightEdgeNodes(BSTNode<int> *root, bool flag) {
  if (!root) return;
  printRightEdgeNodes(root->left, (flag && !flag->right)); // this is for certain scenario
  // printRightEdgeNodes(root->left, false);
  printRightEdgeNodes(root->right, flag);
  if (flag || isLeafNode(root)) 
    printNode(root);
}

void printEdgeNodes(BSTNode<int> *root) {
  if (!root) return;
  cout<< root->data << endl;
  printLeftEdgeNodes(root->left, true);
  printRightEdgeNodes(root->right, true);
}

int main() {
  BST<int> bt;
  bt.insert_item(8);
  bt.insert_item(4);
  bt.insert_item(2);
  bt.insert_item(1);
  bt.insert_item(7);
  bt.insert_item(5);
  bt.insert_item(6);
  bt.insert_item(9);
  bt.printByLevel();
  cout<<endl;
  printEdgeNodes(bt.root);
  return 1;
}
