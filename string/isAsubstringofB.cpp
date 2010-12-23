#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <string.h>


using namespace std;

bool isAsubstringofB(string a, string b) {
  int i, j;
  i = j = 0;
  while(j<b.size()) {
    if (i == a.size()) {
      return true;
    }
    if (b[j]==a[i]) {
      i++;
    }
    else {
      i=0;
    }
    j++;
  }
  return false;
}

bool isAsubstringofBNonContiguous(char *a, char *b) {
  assert(a && b);
  while(*b && *a) {
    if (*b++ == *a) a++;
  }
  return *a == '\0';
}

int main() {
  string a, b;
  char c[50];
  char d[50];
  cin>>a;
  cin>>b;
  strcpy(c, a.c_str());
  strcpy(d, b.c_str());
  cout<<isAsubstringofB(a, b)<<endl;
  cout<<isAsubstringofBNonContiguous(c, d)<<endl;
  return 1;
}
