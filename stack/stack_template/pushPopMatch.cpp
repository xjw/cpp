/**
 *  
 *  输入两个整数序列。其中一个序列表示栈的push顺序，判断另一个序列有没有可能是对应的pop顺序。
 *  为了简单起见，我们假设push序列的任意两个整数都是不相等的。
 *  比如输入的push序列是1、2、3、4、5，那么4、5、3、2、1就有可能是一个pop系列。
 *  因为可以有如下的push和pop序列：push 1，push 2，push 3，push 4，pop，push 5，pop，pop，pop，pop，
 *  这样得到的pop序列就是4、5、3、2、1。但序列4、3、5、1、2就不可能是push序列1、2、3、4、5 的pop序列
 *
 */

#include <iostream>
#include <stack>

using namespace std;

bool pushPopMatch(int *a, int *b, int n) {
  stack<int> st;

  for (int i=0, j=0; i<n; i++) {
    st.push(a[i]);
    while (!st.empty() && st.top() == b[j]) {
      st.pop();
      j++;
    }
  }
  return st.empty()? true : false;
}

int main() {
  int a[] = {1,2,3,4,5};
  int b[] = {4,5,3,2,1};
  if (pushPopMatch(a, b, sizeof(a)/sizeof(a[0]))) {
    cout << "Match" << endl;
  }
  else {
    cout << "NONONO" << endl;
  }
  return 1;
}
