#include "stack.h"

int main() {
  Stack<int> st = Stack<int>(0);
  st.push(1);
  // st.push(2);
  // st.push(3);
  // st.push(4);
  // st.push(5);
  // st.push(6);
  while (!st.empty()) {
    cout<<st.top()<<endl;
    st.pop();
  }
}

