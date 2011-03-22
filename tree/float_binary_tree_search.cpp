#include <iostream>
#include <math.h>
#include "bst.h"

using namespace std;

/**
 * do not need to compare each time
 * only those turns matter
 */
float search_float(BSTNode<float> *root, float x) {
    float p, l, r;
    l = r = p = root->data;
    while(root != NULL) {
        p = root->data;
        if (x<p) {
            root = root->left;
            l = p;
        }
        else {
            root = root->right;
            r = p;
        }
    }
    return fabs(l-x) > fabs(r-x) ? r : l;
}

int main() {
    BST<float> bst;
    bst.insert_item(1.1);
    bst.insert_item(1.8);
    bst.insert_item(1.3);
    bst.insert_item(2.1);
    bst.insert_item(0.4);
    bst.insert_item(0.1);
    bst.insert_item(0.7);
    bst.printByLevelQueueNewLine();
    float f;
    while(cin>>f && f>0) {
        cout << search_float(bst.root,f) << endl;
    }
    return 1;
}
