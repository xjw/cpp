#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <queue>
#include "bst.h"

using namespace std;

//http://stackoverflow.com/questions/2675756/efficient-array-storage-for-binary-tree
//http://en.wikipedia.org/wiki/Binary_tree


//////////////////////////////////////////////////
// solution 1: 2n+1, 2n+2
// need 2^n space

const int EMPTY = 0;
const int SIZE = 7;
const char EMP = ' ';

void insertBSTToArray1(BSTNode<int> *root, int *a, int idx) {
  if (root == NULL) {
    a[idx] = EMPTY;
    return;
  }
  a[idx] = root->data;
  insertBSTToArray1(root->left, a, idx*2+1);
  insertBSTToArray1(root->right, a, idx*2+2);
}

BSTNode<int> *buildBSTFromArray1(int *a, int idx, int n) {
  if (a[idx] == EMPTY) return NULL;
  else {
    BSTNode<int> *root = new BSTNode<int>(a[idx]);
    root->left  = buildBSTFromArray1(a, idx*2+1, n);
    root->right = buildBSTFromArray1(a, idx*2+2, n);
    return root;
  }
}

void deserialize1(int a[]) {
  BST<int> bst2;
  bst2.root = buildBSTFromArray1(a, 0, SIZE);
  cout<<endl;
  bst2.printByLevel();
  cout<<endl;
}

void serialize1(const BST<int> &bst) {
  int a[100];
  insertBSTToArray1(bst.root, a, 0);
  cout<<endl;
  for(int i=0; i<SIZE; ++i) {
    cout<<a[i];
  }
  cout<<endl;
  deserialize1(a);
}

//////////////////////////////////////////////////
// http://en.wikipedia.org/wiki/Binary_tree
//
void succient_encoding(const BSTNode<int> *root, queue<bool> &v, queue<int> &d) {
  if (!root) {
    v.push(0);
    return;
  }
  v.push(1);
  d.push(root->data);
  succient_encoding(root->left, v, d);
  succient_encoding(root->right, v, d);
}

BSTNode<int>* succient_decoding(queue<bool> &v, queue<int> &d) {
  if (v.empty() || d.empty()) return NULL;
  if (v.front() == 0) {
    v.pop();
    return NULL;
  }
  else {
    BSTNode<int> *root = new BSTNode<int>(d.front());
    v.pop();
    d.pop();
    root->left  = succient_decoding(v, d);
    root->right = succient_decoding(v, d);
    return root;
  }
}

void serialize3(const BST<int> &bst) {
  queue<bool> v;
  queue<int> d;
  succient_encoding(bst.root, v, d);

  BST<int> bst2;
  bst2.root = succient_decoding(v, d);
  bst2.printByLevel();
}



//////////////////////////////////////////////////

int main() {
  BST<int> bst;
  bst.insert_item(4);
  bst.insert_item(3);
  bst.insert_item(1);
  bst.insert_item(2);
  bst.insert_item(5);
  bst.insert_item(6);
  bst.printByLevel();

  // serialize1(bst);
  // serialize2(bst);
  serialize3(bst);

  return 1;
}
