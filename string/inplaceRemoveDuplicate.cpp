#include <iostream>
#include <set>
#include <string.h>

using namespace std;

int inplaceRemoveDuplicate(char s[]) {
  char *start, *c;
  start = c = s;
  int len_before = strlen(s);

  while(*s != '\0') {
    if (*s != *c) {
      *++c = *s;
    }
    s++;
  }
  *++c = '\0';
  return len_before-strlen(start);
}

int main() {
  char s[20];
  cin>>s;
  cout<<inplaceRemoveDuplicate(s)<<endl;
  cout<<s<<endl;
  return 1;
}
