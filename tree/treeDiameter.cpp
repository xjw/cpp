/**
 * http://www.cnblogs.com/miloyip/archive/2010/02/25/1673114.html 
 *
 * if distance counts edges, then default r=-1, s=0, r.length = max(2+...
 * if distance counts nodes, then default r=0, s=0, r.length = max(1+...
 */

#include <iostream>
#include "bst.h"

using namespace std;

// length only
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

///////////////////////////////////////////////////////////////

// print path
struct RPath {
    int depth;
    int length;
    vector<int> v_d; // save depth path
    vector<int> v_l; // save length path
    RPath(int r=-1, int s=0) : depth(r), length(s) {}
};

RPath diameterPath(BSTNode<int> *root) {
    RPath r;
    if (!root) return r;
    RPath left = diameterPath(root->left); 
    RPath right = diameterPath(root->right);

    if (left.depth>right.depth)
        r.v_d = left.v_d;
    else
        r.v_d = right.v_d;

    r.v_d.push_back(root->data);

    int max_l = max(left.length, right.length);
    if (2+left.depth+right.depth>max_l) {
        r.v_l.insert(r.v_l.end(), left.v_d.begin(), left.v_d.end());
        r.v_l.push_back(root->data);
        r.v_l.insert(r.v_l.end(), right.v_d.rbegin(), right.v_d.rend());
    }
    else if (left.length>right.length) {
        r.v_l = left.v_l;
    }
    else {
        r.v_l = right.v_l;
    }

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

    cout<<endl;
    RPath dpath = diameterPath(bst->root);
    vector<int> v = dpath.v_l;
    for(vector<int>::iterator it=v.begin(); it!=v.end(); ++it) {
        cout<<*it<<endl;
    }
    cout<<endl;


    delete bst;
    return 1;
}
