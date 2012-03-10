/*
 * http://tech-queries.blogspot.com/2011/04/copy-linked-list-with-next-and-random.html
 */
#include <iostream>

using namespace std;

typedef struct Node {
    Node (int d) : next(NULL), random(NULL), data(d) {
    }
    Node *next;
    Node *random;
    int data;
} Node;

void printLinkedList(Node *p) {
    while (p) {
        cout << p->data << endl;
        if (p->random) {
            cout << p->random->data << endl;
        }
        p = p->next;
        cout << "---" << endl;
    }
}

Node* cloneLinkedList(Node *head) {
    Node *p = head;
    Node *new_head;
    // first loop - insert those duplicate nodes;
    while (p) {
        Node *p_new = new Node(p->data);
        p_new->next = p->next;
        p->next = p_new;
        p = p_new->next;
    }
    // second loop - setup next pointer and radom pointer for new list
    p = head;
    while(p && p->next) {
        if (p->next && p->random) {
            p->next->random = p->random->next;
        }
        p = p->next->next;
    }
    // third loop - break up new and old list
    p = head;
    new_head = head->next;
    while (p && p->next) {
        Node * temp = p->next;
        p->next = temp->next;
        p = temp;
    }
    return new_head;
}

Node* setup() {
    Node *p1 = new Node(1);
    Node *p2 = new Node(2);
    Node *p3 = new Node(3);
    p1->next = p2;
    p2->next = p3;
    p1->random = p3;
    p2->random = p3;
    p3->random = p1;
    return p1;
}

int main() {
    Node *head = setup();
    printLinkedList(head);
    Node *newhead = cloneLinkedList(head);
    cout << "**********" << endl;
    printLinkedList(head);
    cout << "**********" << endl;
    printLinkedList(newhead);

    return 1;
}
