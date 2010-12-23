#include <iostream>
#include <vector>
#include "bst.h"

using namespace std;

/**
 * solution 1:
 * convert bst to array
 * merge array
 * convert array back to bst
 * time complexity: O(m+n)
 * pro: keep bst balanced
 */
void mergeBST1(BST<int> &bst1, BST<int> &bst2) {
  vector<int> v1, v2, v3;
  bstToVector(bst1.root, v1);
  bstToVector(bst2.root, v2);

  mergeVector(v1, v2, v3);
  BST<int> bst3;
  bst3.root = arrayToBST(v3, 0, v3.size()-1);
  bst3.printByLevel();
}

void bstToVector(BSTNode<int>* root, vector<int> &v) {
  if (root != NULL) {
    bstToVector(root->left, v);
    v.push_back(root->data);
    bstToVector(root->right,v);
  }
}

BSTNode<int>* arrayToBST(vector<int> &v, int l, int r) {
  if (l>r) return NULL;

  int m = (l + r)/2;
  BSTNode<int> *root = new BSTNode<int>(v[m]);
  root->left = arrayToBST(v, l, m-1);
  root->right = arrayToBST(v, m+1, r);
  return root;
}

void mergeVector(vector<int>& v1, vector<int>& v2, vector<int>& v3) {
  vector<int>::iterator it1, it2;
  it1 = v1.begin();
  it2 = v2.begin();

  while(it1 != v1.end() && it2 != v2.end()) {
    if (*it1 <= *it2) {
      v3.push_back(*it1);
      it1++;
    }
    else if (*it2 < *it1) {
      v3.push_back(*it2);
      it2++;
    }
  }
  while(it1 != v1.end()) {
    v3.push_back(*it1);
    it1++;
  }
  while(it2 != v2.end()) {
    v3.push_back(*it2);
    it2++;
  }
}
// end of solution 1



int main() {
  BST<int> bst1;
  bst1.insert_item(5);
  bst1.insert_item(3);
  bst1.insert_item(7);
  bst1.printByLevel();
  cout<<endl;

  BST<int> bst2;
  bst2.insert_item(4);
  bst2.insert_item(2);
  bst2.insert_item(6);
  bst2.printByLevel();
  cout<<endl;

  mergeBST1(bst1, bst2);

  return 1;
}
