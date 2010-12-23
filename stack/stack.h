/**
 *  http://www.cs.bu.edu/teaching/cs112/spring-2000/stack/
 */
#include <iostream>
#include <exception>

using namespace std;

template <class T>
class Stack {
 public:
  Stack(int size);
  ~Stack();
  void pop();
  void push(T data);
  T top();
  bool empty();
  bool full();
 private:
  T *contents;
  int maxSize;
  int top_idx;
};

template <class T>
Stack<T>::Stack(int size) {
  try {
    contents = new int[size];
    maxSize = size;
    top_idx = -1;
  }
  catch (exception &e) {
    cout << "stack initialization exception "<< e.what()<< endl;
  }
}

template <class T>
Stack<T>::~Stack() {
  delete[] contents;
  contents = NULL;
  maxSize = 0;
  top_idx = -1;
}

template <class T>
bool Stack<T>::empty() {
  return top_idx < 0;
}

template <class T>
bool Stack<T>::full() {
  return top_idx+1 >= maxSize;
}

template <class T>
void Stack<T>::push(T data) {
  try {
    if (full()) {
      throw "Stack full";
    }
  }
  catch (char * str) {
    cout << "Exception raised " << str << endl;
  }

  contents[++top_idx] = data;
}

template <class T>
void Stack<T>::pop() {
  if (!empty()) {
    --top_idx;
  }
}

template <class T>
T Stack<T>::top() {
  if (!empty()) {
    return contents[top_idx];
  }
}
