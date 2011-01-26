#include <iostream>
#include <string.h>

using namespace std;

void reverse(char *str) {
  int start, end;
  char c;
  start = 0;
  end = strlen(str)-1;
  while(end>start) {
    c = str[start];
    str[start++] = str[end];
    str[end--] = c;
  }
}

/**
 * BUG code example!!!! 
 */
void itoa_1 (int value, char *str, int base) {
  do {
    *str++ = value%base + '0';
    value = value/base;
  } while (value);
  *str = '\0';
  reverse(str);
}

void itoa_2 (int value, char *str, int base) {
  if (!str) return;
  int i=0;
  bool neg = false;
  if (value < 0) {
    value = -value;
    neg = true;
  }
  do {
    str[i++] = value%base + '0';
    value = value/base;
  } while (value);
  if (neg) str[i++] = '-';
  str[i] = '\0';
  reverse(str);
}

int main() {
  char str[50];
  char s[50];
  int value;
  cin>>value;
  itoa(value, s, 10);
  itoa_2(value, str, 10);
  cout<<s<<endl;
  cout<<str<<endl;
  return 1;
}
