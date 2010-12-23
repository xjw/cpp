#include <iostream>
#include <vector>

using namespace std;

class treeNode {
 public:
  int data;
  treeNode *left;
  treeNode *right;
};

void printSequence(vector<int> buffer, int level, int i) {
  for (; i<=level; ++i) {
    cout<<buffer.at(i)<<endl;
  }
}

void findSum(treeNode *root, vector<int> buffer, int sum, int level) {
  if (root == NULL) return;
  buffer.push_back(root->data);

  int tmp = sum;
  for (int i=level; i>=0; --i) {
    tmp -= buffer.at(i);
    if (tmp == 0) {
      printSequence(buffer, level, i);
    }
  }

  findSum(root->left, buffer, sum, level+1);
  findSum(root->right, buffer, sum, level+1);
}

int main() {
}
