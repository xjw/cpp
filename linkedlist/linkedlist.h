/*
 * A Complete Set of Linkedlist Problems
 * http://www.cnblogs.com/Jax/archive/2010/04/29/1621504.html
*/

#include <iostream>
#include <stdexcept>

using namespace std;


template <class T>
class Node {
 public:
  T data;
  Node *next;
  Node(T val);
};

template <class T>
Node<T>::Node(T val) {
  data = val;
  next = NULL;
}

template <class T>
class List {
 public:
  Node<T> *head;
  List();
  ~List();
  void insert(T data);
  void print();
  void reverse();
  void reverse_cool();
  // void swap(Node<T> *a, Node<T> *b);
  void reverse_recursive();
  Node<T> *reverse_recursive(Node<T> *h);
  T find_n_to_last_using_two_pointers(int n);
  T find_n_to_last_using_array(int n);
  T find_middle();
  Node<T> *merge(Node<T> *h1, Node<T> *h2);
  bool isCircular();
};

template <class T>
List<T>::List() {
  head = NULL;
}

template <class T> 
List<T>::~List() {
  while(head != NULL) {
    Node<T> *temp = head->next;
    delete head;
    head = temp;
  }
}

template <class T>
void List<T>::insert(T data) {
  Node<T> *newNode = new Node<T>(data);
  newNode->next = head;
  head = newNode;
}

template <class T>
void List<T>::reverse() {
  Node<T> *prev = NULL;
  Node<T> *curr = head;
  Node<T> *next;

  while(curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
}

// template <typename T>
// void swap(Node<T> *a, Node<T> *b) {
  // if (a == b) return;
  // a ^= b;
  // b ^= a;
  // a ^= b;
// }

template <typename T>
void List<T>::reverse_cool() {
  Node<T> *temp=NULL;
  while(head) {
    swap(temp, head->next);
    swap(temp, head);
  }
}


template <class T>
void List<T>::reverse_recursive() {
  head = reverse_recursive(head);
}

template <class T>
Node<T> *List<T>::reverse_recursive(Node<T> *h) {
  if (h == NULL || h->next == NULL) {
    return h;
  }

  Node<T> *rhead = reverse_recursive(h->next);
  h->next->next = h;
  h->next = NULL;

  return rhead;
}

template <class T>
void List<T>::print() {
  Node<T> *temp = head;
  while(temp != NULL) {
    cout << temp->data << endl;
    temp = temp->next;
  }
}

template <class T>
T List<T>::find_n_to_last_using_two_pointers(int n) {
  int i=n;
  Node<T> *first = head;
  while(i--) {
    first = first->next;
    if (first == NULL) {
      throw runtime_error ("less than error");
    }
  }
  Node<T> *second = head;
  while(first->next != NULL) {
    first = first->next;
    second = second->next;
  }
  cout<<second->data<<endl;
  return second->data;
}

template <class T>
T List<T>::find_n_to_last_using_array(int n) {
  T *ta = new T[n];

  int i=0;
  Node<T> *p = head;
  while (p->next != NULL) {
    ta[i++%n] = p->data;
    p = p->next;
  }

  if (n > i) {
    throw runtime_error("less than error");
  }
  cout<<ta[i%n]<<endl;
  return ta[i%n];
}

template <class T>
T List<T>::find_middle() {
  if (head == NULL) return NULL;

  Node<T> *slow, *fast;
  slow = fast = head;
  while(fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }

  cout<<slow->data<<endl;
  return slow->data;
}

template <class T>
Node<T>* List<T>::merge(Node<T> *h1, Node<T> *h2) {
  Node<T> *head = NULL;
  while (h1 != NULL || h2 != NULL) {
    Node<T> *h3 = new Node<T>(0);
    if (h2 == NULL || h1->data < h2->data) {
      h3->data = h1->data;
      h1 = h1->next;
    }
    else if (h1 == NULL || h1->data >= h2->data) {
      h3->data = h2->data;
      h2 = h2->next;
    }
    h3->next = head;
    head = h3;
  }
  Node<T> *p = head;
  while(p != NULL) {
    cout<<p->data<<endl;
    p = p->next;
  }
  return head;
}

template <class T>
bool List<T>::isCircular() {
  Node<T> *p1, *p2;
  p1 = p2 = head;
  while(p2 != NULL && p2->next != NULL) {
    if (p1 == p2) return true;
    p1 = p1->next;
    p2 = p2->next->next;
  }
  return false;
}
