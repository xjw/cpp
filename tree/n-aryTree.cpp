/**
 * http://hi.baidu.com/huifeng00/blog/item/63a4a4564db33d54d00906f7.html 
 */

#include <iostream>
#include <list>

using namespace std;

typedef int T;

struct treeNode {
    T data;
    list<treeNode *> children;
    treeNode(T d) : data(d) {}; 
};

treeNode* insert(treeNode *root, T d) {
    treeNode *newnode = new treeNode(d);
    root->children.push_back(newnode);
    return newnode;
}

void inorder(treeNode *root) {
}

int main() {
    return 1;
}
