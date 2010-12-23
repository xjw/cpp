#include <iostream>
using namespace std;

class treeNode {
 public:
  treeNode *left;
  treeNode *right;
  int data;
};

bool treeMatch(treeNode *tn1, treeNode *tn2) {
  if (tn1 == NULL && tn2 == NULL) return true;
  if (tn1 == NULL || tn2 == NULL) return false;
  if (tn1->data != tn2->data) return false;
  return treeMatch(tn1->left, tn2->left) && treeMatch(tn1->right, tn2->right);
}

bool subtree(treeNode *t1, treeNode *t2) {
  if (t1== NULL || t2 == NULL)
    return false;
  if (t1->data == t2->data)
    return treeMatch(t1, t2);
  else
    return subtree(t1, t2->left) || subtree(t1, t2->right);
}

int main() {
}
