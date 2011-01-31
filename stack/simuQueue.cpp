/**
 * simulate queue using two stacks
 */

#include <stack>
#include <iostream>

using namespace std;

typedef int T;

class queue{
 public:
  T front();
  void push(T);
  void pop();
  int size();
  bool empty();
  
 private:
  stack<T> s1, s2;
};

bool queue::empty() {
  return s1.empty() && s2.empty();
}

int queue::size() {
  return s1.size() + s2.size();
}

void queue::push(T element) {
  s1.push(element);
}

T queue::front() {
  if (!s2.empty()) {
    return s2.top();
  }
  while(!s1.empty()) {
    s2.push(s1.top());
    s1.pop();
  }
  return s2.top();
}

void queue::pop() {
  if (!s2.empty()) {
    s2.pop();
    return;
  }
  while(!s1.empty()) {
    s2.push(s1.top());
    s1.pop();
  }
  s2.pop();
}

int main() {
  queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  while(!q.empty()) {
    cout<<q.front()<<endl;
    q.pop();
  }
}
