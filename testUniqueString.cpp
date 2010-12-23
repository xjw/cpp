#include <iostream>
#include <string.h>
using namespace std;

bool testUniqueString(char *str) {
  if (!str) return true;

  int result = false;
  for(int i=0; i<strlen(str); i++) {
    int idx = str[i] - 'a';
    if (result & (1<<idx)) return false;
    result |= 1<<idx;
  }

  return true;
}

int main()
{
  char a[] = "abcdef";
  cout << testUniqueString(a);


}
