#include <iostream>
#include <stack>

using namespace std;

void pushToBottom(stack<int> &st, int t) {
  int m = st.top();
  st.pop();

  if (st.empty())
    st.push(t);
  else
    pushToBottom(st, t);
  st.push(m);
}

void reverseStack(stack<int> &st) {
  int t = st.top();
  st.pop();

  if (st.size() > 1) {
    reverseStack(st);
  }
  pushToBottom(st, t);
}

void printStack(stack<int> st) {
  while(!st.empty()) {
    int t = st.top();
    cout<<t<<endl;
    st.pop();
  }
  cout<<endl;
}

int main() {
  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);
  printStack(st);
  reverseStack(st);
  printStack(st);

  return 1;
}
