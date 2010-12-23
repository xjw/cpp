/**
 * http://www.ihas1337code.com/2010/03/first-on-site-technical-interview.html 
 */

#include <iostream>
#include <queue>

using namespace std;

class node {
 public:
  int data;
  node *left;
  node *right;
  node *sibling; //next right sibling
  node(int d) : data(d) {left=NULL; right=NULL; sibling=NULL;}
};

void addSiblingPointerUsingQueue(node *root) {
  queue<node*> q;
  q.push(root);
  q.push(NULL);
  node *front, *prev;
  front = prev = NULL;

  while(!q.empty()) {
    front = q.front();
    q.pop();
    if (front == NULL) {             // BUG 1st time, lead to infinite loop
      if (!q.empty()) q.push(NULL);
    }
    else {
      if (prev) prev->sibling = front;
      if (front->left) q.push(front->left);
      if (front->right) q.push(front->right);
    }
    prev = front;
  }
}

/**
 * recursive approach without using queue 
 * assume a full tree
 */
void addSiblingPointerNoQueue(node *root, node *right) {
  if (!root) return;
  root->sibling = right;
  node *l = root->left;
  node *r = root->right;
  addSiblingPointer(l,r);
  addSiblingPointer(r,right? right->left : NULL);
}

int main() {
  node *n1 = new node(1);
  node *n2 = new node(2);
  node *n3 = new node(3);
  node *n4 = new node(4);
  n2->left  = n1;
  n2->right = n3;
  n3->right = n4;
  addSiblingPointerNoQueue(n2, NULL);

  cout<<n1->sibling->data;

  delete n1;
  delete n2;
  delete n3;
  delete n4;

  return 1;
}
