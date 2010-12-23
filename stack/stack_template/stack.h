#ifndef _STACK_H
#define _STACK_H

typedef int StackElementT;

class Stack{
  public:
    Stack(int);
    ~Stack();
    void push(StackElementT element);
    StackElementT pop();
    StackElementT top();
    bool isEmpty() const;
    bool isFull() const;

 private:
    StackElementT *contents;
    int top_idx;
    int maxSize;
};

#endif
