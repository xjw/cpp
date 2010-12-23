#include <stack>
#include <iostream>

using namespace std;

stack<int> sortStack(stack<int> s1) {
  stack<int> s2;
  while(!s1.empty()) {
    int top_s1 = s1.top();
    s1.pop();
    while (!s2.empty() && top_s1 > s2.top()) {
      s1.push(s2.top());
      s2.pop();
    }
    s2.push(top_s1);
  }
  return s2;
}

int main() {
  stack<int> s1, s2;
  s1.push(2);
  s1.push(3);
  s1.push(4);
  s1.push(1);
  s1.push(5);
  s2 = sortStack(s1);
  while(!s2.empty()) {
    cout<<s2.top()<<endl;
    s2.pop();
  }
}
