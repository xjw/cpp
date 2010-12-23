#include <iostream>
#include <string.h>

using namespace std;

string findRemoveAppend(string s, char c) {
  int count=0;
  int n = s.size();
  for (int i=0, p=0; i<n; ++i) {
    if (s[i]!=c) {
      if (p != i) {
        s[p] = s[i];
      }
      p++;
    }
    else {
      count++;
    }
  }
  for (int i=n-count; i<n; ++i) {
    s[i] = c;
  }
  return s;
}

int main() {
  string s;
  cin>>s;
  char c;
  cin>>c;
  cout<<findRemoveAppend(s, c)<<endl;
  return 1;
}
