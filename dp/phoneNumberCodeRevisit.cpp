#include <iostream>
#include <map>

using namespace std;

#define SIZEOF(x) (sizeof(a)/sizeof(a[0]))

int count = 0;

void printAllPhoneNumberCode(int a[], map<int, string> m, string s, int start, int n) {
  if (start>=n) {
    cout<<s<<endl;
    count++;
    return;
  }
  string t = m[a[start]];
  for (int i=0; i<t.size(); ++i) {
    printAllPhoneNumberCode(a, m, s+t[i], start+1, n);
  }
}

int main() {
  int a[] = {2,6,3,9};
  int n = SIZEOF(a);
  map<int, string> m;

  m[0] = "0";
  m[1] = "1";
  m[2] = "abc";
  m[3] = "def";
  m[4] = "ghi";
  m[5] = "jkl";
  m[6] = "mno";
  m[7] = "pqrs";
  m[8] = "tuv";
  m[9] = "wxyz";

  string s;
  printAllPhoneNumberCode(a, m, s, 0, n);
  cout<<count<<endl;
}
