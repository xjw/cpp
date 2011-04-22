#include "bst.h"
#include <iostream>

using namespace std;

/**
 * 给定一个没有通往父节点的连接的BST, 找到大于x的最小的那个节点 
 * 尾递归
 */
int find_min_bigger_node(BSTNode<int>* root, int upper_bound, int x) {
    if (!root) return upper_bound;
    if (root->data>x) return find_min_bigger_node(root->left, root->data, x);
    else return find_min_bigger_node(root->right, upper_bound, x);
}

/**
 * 尾递归可以改成iterative solution，因为程序只有一条执行路径。 
 */
int find_min_bigger_node_iterative(BSTNode<int>* root, int upper_bound, int x) {
    while(root) {
        if (root->data<x) {
            root = root->right;
        }
        else {
            root = root->left;
            upper_bound = root->data;
        }
    }
    return upper_bound;
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
    cout << find_min_bigger_node(bst->root, INT_MAX, 5) << endl;
    cout << find_min_bigger_node(bst->root, INT_MAX, 4) << endl;
    cout << find_min_bigger_node(bst->root, INT_MAX, 8) << endl;
    return 1;
}
