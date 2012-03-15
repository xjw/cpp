#include "bst.h"
#include <iostream>

using namespace std;

void find_kth_in_bst(BSTNode<int>* root, int k, int &i) {
    if (root) {
        find_kth_in_bst(root->left, k, i);
        i++;
        if (i==k) cout << root->data << endl;
        if (i>=k) return;
        find_kth_in_bst(root->right, k, i);
    }
}


int main() {
    BST<int> *bst = new BST<int>;
    bst->insert_item(6);
    bst->insert_item(9);
    bst->insert_item(8);
    bst->insert_item(10);
    bst->insert_item(2);
    bst->insert_item(3);
    bst->insert_item(4);
    bst->insert_item(5);
    bst->printByLevel();
    cout << endl;
    int k;
    while ((cin>>k) && (k!='z')) {
        int i=0;
        find_kth_in_bst(bst->root, k, i);
    }
    return 1;
}
