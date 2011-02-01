/**
 * http://sourcemaking.com/design_patterns/iterator/cpp/1  
 * http://www.uow.edu.au/~nabg/ABC/treeiter.txt
 */

const int MAX_DEPTH=100;

template <class T>
class TreeIter {
 private:
    BST<T>* bst;
    BSTNode<T> *tStack[MAX_DEPTH];
    int depth;
 public:
    TreeIter(BST<T> *bst);
    void first();
    void InOrderNext();
    bool isDone();
    T current();
};

template <class T>
TreeIter<T>::TreeIter(BST<T> *b) {
    bst = b;
    depth = -1;
}

template <class T>
void TreeIter<T>::first() {
    BSTNode<T> *root = bst->root;
    while(root!=NULL) {
        tStack[++depth] = root;
        root = root->left;
    }
}

template <class T>
void TreeIter<T>::InOrderNext() {
    if (depth<0) return;
    BSTNode<T> *root = tStack[depth--];
    root = root->right;
    while(root != NULL) {
        tStack[++depth] = root;
        root = root->left;
    }
}

template <class T> 
void TreeIter<T>::preOrderNext() {
    if (depth<0) return;
    
}

template <class T>
T TreeIter<T>::current() {
    return (depth>=0)? tStack[depth]->data : NULL;
}

template <class T>
bool TreeIter<T>::isDone() {
    return depth<0;
}
