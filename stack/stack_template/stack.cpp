/**
 *  http://www.cs.bu.edu/teaching/cs112/spring-2000/stack/
 */

#include <iostream>
#include <stdlib.h>
#include "stack.h"

using namespace std;

Stack::Stack(int size) {
  contents = new StackElementT[size]; 

  if (contents == NULL) {
    cout<<"insufficent memory to initialize stack\n";
    exit(1);
  }

  maxSize = size;
  top_idx = -1;
}

Stack::~Stack() {
  delete [] contents;
  contents = NULL;

  maxSize = 0;
  top_idx = -1;
}

bool Stack::isFull() const {
  return (top_idx + 1 == maxSize);
}

bool Stack::isEmpty() const {
  return top_idx<0;
}

void Stack::push(StackElementT element) {
  if (isFull()) {
    cout<<"stack is full\n";
    exit(1);
  }

  contents[++top_idx] = element;
}

StackElementT Stack::pop() {
  if (!isEmpty()) {
    return contents[top_idx--];
  }
}

StackElementT Stack::top() {
  if (!isEmpty()) {
    return contents[top_idx];
  }
}
