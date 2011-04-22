/**
 * find LCA of two tree nodes
 * http://stackoverflow.com/questions/1484473/how-can-i-find-the-common-ancestor-of-two-nodes-in-a-binary-tree
 *
 *        1
 *      /   \
 *     2    3 
 *    / \  / \ 
 *   4  5 6  7
 *  / \ 
 * 8   9
 *
 * find LCA or 8 & 5
 *
 * inorder:   849251637
 * postorder: 894526731
 *
 * inorder between 8 & 5 (492)
 * then check which node in this list appears last in the postorder traversal
 * out of 492, in postorder, the last one after 5 is 2
 * then the LCA is 2
 */

#include <iostream>

using namespace std;

class treeNode {
 public:
  treeNode *left;
  treeNode *right;
  int data;
  treeNode(int item) {left=NULL; right=NULL;data = item;};
};

class tree {
 public:
  treeNode *root;
  treeNode *LCA(treeNode *root, treeNode *a, treeNode *b);
};

treeNode *LCA(treeNode *root, treeNode *a, treeNode *b) {
  vector<treeNode *> inorder;
  vector<treeNode *> postorder;
}

int main() {
  tree *tree1 = new tree;
  treeNode *t1 = new treeNode(1);
  treeNode *t2 = new treeNode(2);
  treeNode *t3 = new treeNode(3);
  treeNode *t4 = new treeNode(4);
  treeNode *t5 = new treeNode(5);
  treeNode *t6 = new treeNode(6);
  tree1->root = t1;
  t1->left = t2;
  t1->right = t3;
  t2->left = t4;
  t4->left = t5;
  t2->right = t6;
  treeNode *t0 = tree1->LCA(t1, t2, t6);
  cout<<t0->data<<endl;
}
