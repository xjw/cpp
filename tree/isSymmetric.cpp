#include <iostream>

using namespace std;

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int data;
    TreeNode(int d) {data=d; left=NULL; right=NULL;};
};

/**
 * ORDER is important!!!!!!!!!!!!!!!!!!!
 * this has to be put at first place to make it work
 * 
 */
bool isSymmetric(TreeNode *left, TreeNode *right) {
    // if ((left == NULL)^(right == NULL)) return false;
    if (left == NULL && right == NULL) return true;
    if (left == NULL || right == NULL) return false;
    return (left->data == right->data)
        && isSymmetric(left->left, right->right)
        && isSymmetric(left->right, right->left);
}

bool isSymmetric(TreeNode *root) {
    if (!root) return true;
    return isSymmetric(root->left, root->right);
}


int main() {
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(2);
    TreeNode *t4 = new TreeNode(3);
    t1->left = t2;
    t1->right = t3;
    t2->right = t4;
    cout << isSymmetric(t1) << endl;
    delete t1;
    delete t2;
    delete t3;
    delete t4;
    return 1;
}
