/*
 * http://drdobbs.com/database/184410528
 * http://www.ahhf45.com/info/data_structures_and_algorithms/resources/technical_artile/ternary_search_tree/terstree.htm
 */

#include <iostream>
#include <string>

using namespace std;

struct Node {
    Node * left;
    Node * middle;
    Node * right;
    char val;
    Node(char c) : left(0), middle(0), right(0), val(c) {
    }
};

class TernTree {
    public:
        Node * root;
        TernTree();
        ~TernTree();
        Node* insert(Node* p, const char *s);
        void insert(const char *s);
        void delete_node(Node *p);
        bool search(Node *p, const char *s);
        bool search(const char *s);
        void traverse(Node *p);
        void traverse();
        void partialMatch(Node*,  const char *, string);
        void partialMatch(const char *);
        void nearstNeighborMatch(Node *, const char *, string, int );
        void nearstNeighborMatch(const char *, int distance);
};

TernTree::TernTree() {
    root = NULL;
}

TernTree::~TernTree() {
    delete_node(root);
}

void TernTree::delete_node(Node *p) {
    if (p) {
        delete_node(p->left);
        delete_node(p->middle);
        delete_node(p->right);
        delete p; 
    }
}

void TernTree::insert(const char *s) {
    root = insert(root, s);
}

Node* TernTree::insert(Node* p, const char *s) {
    if (!s) return 0;
    if (!p) {
        //cout << *s << endl;
        p = new Node(*s);
    }
    if (*s < p->val) {
        p->left = insert(p->left, s);
    }
    else if (*s == p->val) {
        if (*s) { 
            p->middle = insert(p->middle, ++s);
        }
    }
    else {
        p->right = insert(p->right, s);
    }
    return p;
}


void TernTree::traverse() {
    traverse(root);
}

void TernTree::traverse(Node *p) {
    if (p) {
        traverse(p->left);
        //cout << p->val << endl;
        traverse(p->middle);
        traverse(p->right);
    }
}

bool TernTree::search(Node *p, const char *s) {
    if (!s || !p) return false;
            
    cout << "searching:" << s << endl;
    if (*s < p->val) {
        return search(p->left,s);
    }
    else if (*s > p->val) {
        return search(p->right,s);
    }
    else {
        if (!*s) return true;
        return search(p->middle, ++s);
    }
}

bool TernTree::search(const char *s) {
    return search(root, s);
}

void TernTree::partialMatch(const char *s) {
    string st="";
    partialMatch(root, s, st);
}

const char MATCH_ANY = '*';

void TernTree::partialMatch(Node* p, const char *s, string st) {
    if (!s || !p) return;
    if (*s == MATCH_ANY || p->val < *s) {
        partialMatch(p->left, s, st);
    }
    if (*s == MATCH_ANY || p->val == *s) {
        if (!*s) {
            cout << "Match Found:" << st << endl;
        }
        else {
            st += p->val;
            partialMatch(p->middle, s+1, st);
        }
    }
    if (*s == MATCH_ANY || p->val > *s) {
        partialMatch(p->right, s, st);
    }
}

void nearstNeighborMatch(Node *p, const char *s, string st, int distance) {
    if (distance<0 || !p || !s) return;
    if (distance>0 || *s < p->val) {
        nearstNeighborMatch(p->left, s, distance);
    }
    if (distance>0 || *s > p->val) {
        nearstNeighborMatch(p->right, s, distance);
    }
    if (distance>0 || *s == p->val) {
        if (!*s) {
            cout << "Match Found:" << st << endl;
        }
        else if (*s == p->val) {
            nearstNeighborMatch(p->middle, s+1, distance);
        }
        else {
            nearstNeighborMatch(p->middle, s, distance+1);
        }
    }
}

void nearstNeighborMatch(const char * s, int distance) {
    string st;
    nearstNeighborMatch(root, s, st, distance);
}

int main() {
    TernTree t;
    t.insert("test");
    t.insert("tell");
    t.insert("tea");
    t.insert("bea");
    t.traverse();
    string s;
    while (cin >> s) {
        //cout << t.search(s.c_str()) << endl;
        t.partialMatch(s.c_str());
    }
    return 1;
}
