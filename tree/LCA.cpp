/**
 * find LCA of two tree nodes
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
  treeNode *LCA(treeNode *a, treeNode *b);
  treeNode *LCA(treeNode *root, treeNode *a, treeNode *b);
  bool isAChildOfB(treeNode *a, treeNode *b);
};

bool tree::isAChildOfB(treeNode *a, treeNode *b) {
  if (b == NULL) return false;
  if (a == b) return true;
  return isAChildOfB(a, b->left) || isAChildOfB(a, b->right);
}

treeNode *tree::LCA(treeNode *a, treeNode *b)  {
  return isAChildOfB(a, b)? b : (isAChildOfB(b, a)? a : LCA(root, a, b));
}

treeNode *tree::LCA(treeNode *root, treeNode *a, treeNode *b)  {
  if (root == NULL) return NULL;

  if (root->left == a || root->right == a || root->left == b || root->right == b)
    return root;

  treeNode *left = LCA(root->left, a, b);
  treeNode *right = LCA(root->right, a, b);

  return (left != NULL && right != NULL)? root : ((left != NULL)? left : right);
}

treeNode *tree::LCA(treeNode *root, treeNode *a, treeNode *b)  {
    if (!root) return NULL;
    if (root == a || root == b) return root;
    treeNode *left = LCA(root->left, a, b);
    treeNode *right = LCA(root->right, a, b);
    return (left && right)? root : (left? left : right);
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
  treeNode *t0 = tree1->LCA(t2, t6);
  cout<<t0->data<<endl;
}
