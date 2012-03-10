#include <iostream>

using namespace std;


int maxSubTree(Node<int> *root, int max) {
    if (root == NULL) return 0;
    int cur_max = maxSubTree(root->left) + maxSubTree(root->right) + root->data;
    if (cur_max > max) return cur_max;
}

int main() {
    return 1;
}
