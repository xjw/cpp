#include <iostream>
#include <stack>

using namespace std;

bool testBrace(string s, string brace) {
  stack<char> st;
  for(int i=0; i<s.size(); ++i) {
    size_t pos = brace.find(s[i]);
    if (pos != string::npos) {
      if (int(pos) % 2 == 0) {
        st.push(s[i]);
      }
      else {
        if (st.empty()) return false;
        if (st.top() != brace[--pos]) return false;
        st.pop();
      }
    }
  }
  return st.empty()? true : false;
}

int main() {
  string s;
  cin>>s;
  if(testBrace(s, "{}[]()")) {
    cout << "valid" << endl;
  }
  else {
    cout << "invalid" << endl;
  }
  return 1;
}
