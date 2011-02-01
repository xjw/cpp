/**
 *  Reference: http://en.literateprograms.org/Binary_search_tree_(C_Plus_Plus)
 *  Also refer to http://cslibrary.stanford.edu/110/BinaryTrees.html
 */

#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <string.h>

using namespace std;

template <class T>
class BSTNode{
 public:
  BSTNode(T item);

 // private:
  T data;
  BSTNode *left;
  BSTNode *right;
  // make BSTNode a friend class so that the tree can access its internal child pointers but no one else can: 
  template<class> friend class BST;

  BSTNode *parent;
};

template <class T>
class BST {
 public:
  BST();
  ~BST();
  void print() const;
  void check() const;
  int height() const;
  void clear(BSTNode<T> *&node);
  BSTNode<T>** search_node(T item);
  void insert_item(T item);
  void delete_item(T item);
  void printByLevel() const;
  void printByLevelQueue() const;
  void printByLevelQueueNewLine() const;
  void printByLevelQueueNewLineNoToken() const;

  bool isBalanced() const;
  int maxDepth(BSTNode<T> *root) const;
  int minDepth(BSTNode<T> *root) const;

  bool isBinarySearchTree() const;

  void buildTreeFromPreInOrder(char *pre, char *in);

  BSTNode<T>* insertFromArray(T[], int start, int end);
  BSTNode<T>* inorderSuccessor(BSTNode<T>* root);

  BSTNode<T> *root;

 private:

  int height(BSTNode<T> *root) const;
  void print(BSTNode<T> *root) const;
  void insert_recursive(BSTNode<T> *&root, T item);
  void delete_node(BSTNode<T> **node);

  BSTNode<T>* buildTreeFromPreInOrder(char *pre, char *in, int n);

  bool isBinarySearchTree(BSTNode<T> *root, T min, T max) const;
};

template <class T>
BSTNode<T>::BSTNode(T item) {
  data = item;
  left = right = NULL;
}

template <class T>
BST<T>::BST() {
  root = NULL;
}

template <class T>
BST<T>::~BST() {
  clear(root);
}

template <class T>
void BST<T>::clear(BSTNode<T> *&ptr) {
  if (ptr != NULL) {
    clear(ptr->left);
    clear(ptr->right);
    delete ptr;
  }
}

template <class T>
int BST<T>::height() const {
  return height(root);
}

template <class T> 
int BST<T>::height(BSTNode<T> * root) const {
  if (root == NULL) {
    return 0;
  }
  return 1 + max(height(root->left), height(root->right));
}

template <class T>
void BST<T>::print() const {
  print(root);
}

template <class T>
void BST<T>::print(BSTNode<T> *root) const {
  if(root != NULL) {
    cout<<root->data;
    print(root->left);
    print(root->right);
  }
}

template <class T>
BSTNode<T>** BST<T>::search_node(T item) {
  BSTNode<T> **node = &root;

  while (*node != NULL) {
    if ((*node)->data > item) {
      node = &(*node)->left;
    }
    else if ((*node)->data < item) {
      node = &(*node)->right;
    }
    else {
      break;
    }
  }

  return node;
}

template <class T>
void BST<T>::insert_item(T item) {
  BSTNode<T> **node = search_node(item);
  if (*node == NULL) {
    *node = new BSTNode<T>(item);
  }
}

/**
 * recursive inserting node 
 */
template <class T>
void BST<T>::insert_recursive(BSTNode<T> *&ptr, T item) {
  if (NULL == ptr) {
    ptr = new BSTNode<T>(item);
  }
  else {
    if (ptr->data > item) {
      insert(ptr->left, item);
    }
    else {
      insert(ptr->right, item);
    }
  }
}

template <class T>
void BST<T>::delete_item(T item) {
  BSTNode<T> **node = search_node(item);
  if (NULL != *node) {
    delete_node(node);
  }
}


template <class T>
void BST<T>::delete_node(BSTNode<T> **node) {
  BSTNode<T> *old_node = *node;

  if (NULL == (*node)->left) {
    *node = (*node)->right;
    delete old_node;
  }
  else if (NULL == (*node)->right) {
    *node = (*node)->left;
    delete old_node;
  }
  else {
    BSTNode<T> **pred = &(*node)->left;
    while(NULL != (*pred)->right) {
      pred = &(*pred)->right;
    }
    (*node)->data = (*pred)->data;
    delete_node(pred);
  }
}

template <class T>
void BST<T>::check() const {
  print();
  cout<<endl<<"height-"<<height()<<endl;
}

/**
 * print by level and new line after each level
 * using 2 vectors instead of queue
 * more efficient
 * refer to http://stackoverflow.com/questions/1894846/printing-bfs-binary-tree-in-level-order-with-specific-formatting
 */

template <class T>
void BST<T>::printByLevel() const {
  vector<BSTNode<T> *> this_level, next_level;
  if (!root) return;

  this_level.push_back(root);

  while(!this_level.empty()) {
    for (typename vector<BSTNode<T> *>::iterator it = this_level.begin(); it != this_level.end(); ++it) {
      cout<<(*it)->data;
      if ((*it)->left != NULL) {
        next_level.push_back((*it)->left);
      }
      if ((*it)->right != NULL) {
        next_level.push_back((*it)->right);
      }
    }
    cout<<endl;
    this_level = next_level;
    next_level.clear();
  }
}


/**
 * print by level using queue 
 * no new line
 */

template <class T>
void BST<T>::printByLevelQueue() const {
  queue<BSTNode<T> *> nodeQueue;
  nodeQueue.push(root);

  while(!nodeQueue.empty()) {
    BSTNode<T> *node = nodeQueue.front();
    nodeQueue.pop();
    cout<<node->data;
    if (node->left != NULL) {
      nodeQueue.push(node->left);
    }
    if (node->right != NULL) {
      nodeQueue.push(node->right);
    }
  }
  cout<<endl;
}

/**
 * print by level using queue
 * with new line using token
 */

template <class T>
void BST<T>::printByLevelQueueNewLine() const {
  queue<BSTNode<T> *> nodeQueue;
  nodeQueue.push(root);
  nodeQueue.push(NULL);

  while(!nodeQueue.empty()) {
    BSTNode<T> *node = nodeQueue.front();
    nodeQueue.pop();
    if (node == NULL) {
      cout<<endl;
      if (!nodeQueue.empty()) {
        nodeQueue.push(NULL);
      }
    }
    else {
      cout<<node->data;
      if (node->left != NULL) {
        nodeQueue.push(node->left);
      }
      if (node->right != NULL) {
        nodeQueue.push(node->right);
      }
    }
  }
}

/**
 * print by level using queue 
 * with new line not using token
 */

template <class T>
void BST<T>::printByLevelQueueNewLineNoToken() const {
  queue<BSTNode<T> *> nodeQueue;
  nodeQueue.push(root);
  int nodesThisLevel = 1;
  int nodesNextLevel = 0;
  while (!nodeQueue.empty()) {
    BSTNode<T> *node = nodeQueue.front();
    nodeQueue.pop();
    if (node->left != NULL) {
      nodeQueue.push(node->left);
      ++nodesNextLevel;
    }
    if (node->right != NULL) {
      nodeQueue.push(node->right);
      ++nodesNextLevel;
    }
    cout<<node->data;
    if (0 == --nodesThisLevel) {
      cout<<endl;
      nodesThisLevel = nodesNextLevel;
      nodesNextLevel = 0;
    }
  }
}

template <class T>
int BST<T>::maxDepth(BSTNode<T> *root) const {
  if (root == NULL) {
    return 0;
  }
  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

template <class T>
int BST<T>::minDepth(BSTNode<T> *root) const {
  if (root == NULL) {
    return 0;
  }
  return 1 + min(minDepth(root->left), minDepth(root->right));
}

template <class T>
bool BST<T>::isBalanced() const {
  return (maxDepth(root) - minDepth(root) <= 1); 
}

template <class T>
bool BST<T>::isBinarySearchTree() const {
  isBinarySearchTree(root, INT_MIN, INT_MAX);
}

template <class T>
bool BST<T>::isBinarySearchTree(BSTNode<T> *root, T min, T max) const {
  if (root == NULL)  return true;

  return (root->data > min) && (root->data <= max) 
      && isBinarySearchTree(root->left, min, root->data) 
      && isBinarySearchTree(root->right, root->data, max);
}

template <class T>
BSTNode<T>* BST<T>::insertFromArray(T arr[], int start, int end) {
  if (end < start)  return NULL;

  int mid = (start + end)/2;
  BSTNode<T> *node = new BSTNode<T>(arr[mid]);
  node->left = insertFromArray(arr, start, mid-1);
  node->right = insertFromArray(arr, mid+1, end);
  return node;
}

/**
 * find in order successor using parent pointer 
 */
template <class T>
BSTNode<T>* BST<T>::inorderSuccessor(BSTNode<T>* n) {
  if (n == NULL) return NULL;
  BSTNode<T>* p;

  if (n->right != NULL) {
    p = n->right;
    while(p->left != NULL) {
      p = p->left;
    }
  }
  else {
    while ((p = n->parent) != NULL) {
      if (p->left == n) break;
      n = p;
    }
  }
  return p;
}


template <class T>
void BST<T>::buildTreeFromPreInOrder(char *pre, char *in) {
  root = buildTreeFromPreInOrder(pre, in, strlen(pre));
}

/**
 * rebuild binary tree from preorder and inorder sequence 
 */
template <class T>
BSTNode<T>* BST<T>::buildTreeFromPreInOrder(char *pre, char *in, int n) {
  // if (n<1 || !*pre || !*in) return NULL;
  if (n<1) return NULL;

  BSTNode<T> *root = new BSTNode<T>(*pre);

  char *inp = in;
  while(inp<in+n) {
    if (*inp == *pre)
      break;
    inp++;
  }

  // if (!*inp) return NULL;
  int k = inp - in;
  // cout<<n<<"--*pre--"<<*pre<<"--*in--"<<*in<<"--*inp--"<<*inp<<"--k--"<<k<<endl;

  root->left = buildTreeFromPreInOrder(pre+1, in, k);
  root->right = buildTreeFromPreInOrder(pre+k+1, in+k+1, n-k-1);

  return root;
}

#endif
