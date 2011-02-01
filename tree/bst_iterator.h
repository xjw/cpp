/**
 * http://mitbbs.com/article_t1/JobHunting/31779953_0_2.html
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
    void inOrderFirst();
    void inOrderNext();
    void inOrderNextStack();
    void preOrderFirst();
    void preOrderNext();
    bool isDone();
    T current();
};

template <class T>
TreeIter<T>::TreeIter(BST<T> *b) {
    bst = b;
    depth = -1;
}

template <class T>
void TreeIter<T>::inOrderFirst() {
    BSTNode<T> *root = bst->root;
    while(root!=NULL) {
        tStack[++depth] = root;
        root = root->left;
    }
}

template <class T>
void TreeIter<T>::inOrderNext() {
    if (depth<0) return;
    BSTNode<T> *root = tStack[depth--];
    root = root->right;
    while(root != NULL) {
        tStack[++depth] = root;
        root = root->left;
    }
}

template <class T>
void TreeIter<T>::init() {
    BSTNode<T> *root = bst->root;
    stack< BSTNode<T> *> st;
    st.push(root);
    if (root->right) st.push(root->right);
    if (root->left) st.push(root->left);
}

template <class T>
void TreeIter<T>::inOrderNextStack() {
    if (!p) return;
    if 
}


template <class T>
void TreeIter<T>::preOrderFirst() {
    BSTNode<T> *root = bst->root;
    tStack[++depth] = root;
}

template <class T> 
void TreeIter<T>::preOrderNext() {
    if (depth<0) return;
    BSTNode<T> *root = tStack[depth--];
    if (root->right) tStack[++depth] = root->right;
    if (root->left) tStack[++depth] = root->left;
}

template <class T>
T TreeIter<T>::current() {
    return (depth>=0)? tStack[depth]->data : NULL;
}

template <class T>
bool TreeIter<T>::isDone() {
    return depth<0;
}
