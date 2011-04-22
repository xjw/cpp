#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

using namespace std;

/**
 * this is not the same behavior with atoi 
 */
int atoi_1(char *str) {
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

int atoi_2(char *str) {
  if (!str) return 0;

  int r=0;
  bool neg = false;
  if (*str == '-') {
    neg = true;
    str++;
  }
  while(*str && *str>='0' && *str<='9') {
    int newnum = 10*r + *str - '0';
    if (r != (newnum-*str+'0')/10) r=INT_MAX;;
    else r = newnum;
    str++;
  }
  return neg? -r : r;
}

int main() {
  char str[50];
  cin>>str;
  cout<<atoi(str)<<endl;
  cout<<atoi_2(str)<<endl;
  return 1;
}
