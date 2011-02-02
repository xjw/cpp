/**
 * http://www.cnblogs.com/miloyip/archive/2010/02/25/1673114.html 
 *
 * if distance counts edges, then default r=-1, s=0, r.length = max(2+...
 * if distance counts nodes, then default r=0, s=0, r.length = max(1+...
 */

#include <iostream>
#include "bst.h"

using namespace std;

struct R {
    int depth;
    int length;
    R(int r=-1, int s=0) : depth(r), length(s) {}
};

R diameter(BSTNode<int> *root) {
    R r;
    if (!root) return r;
    R left = diameter(root->left); 
    R right = diameter(root->right);
    r.depth = 1 + max(left.depth, right.depth);
    r.length = max(2+left.depth+right.depth, max(left.length, right.length));
    return r;
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

    R d = diameter(bst->root);
    cout << d.depth << endl;
    cout << d.length << endl;

    delete bst;
    return 1;
}
