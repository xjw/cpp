#include <iostream>
#include <string.h>

using namespace std;

int atoi(char *str) {
  if (strlen(str)<1) return 0;

  int ret = 0;
  bool neg = false;

  if (*str == '-') {
    neg = true;
    str++;
  }

  while(*str) {
    ret = 10*ret + *str - '0';
    str++;
  }

  if (neg) ret = -ret;

  return ret;
}

int main() {
  char str[50];
  cin>>str;
  cout<<atoi(str)<<endl;
  return 1;
}
