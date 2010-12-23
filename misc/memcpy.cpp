#include <iostream>
#include <string.h>

using namespace std;

void* _memcpy(void *dst, const void *src, size_t len) {
  char *s = (char *)src;
  char *d = (char *)dst;
  while(len--) {
    *d++ = *s++;
  }
}

int main() {
  char a[3];
  char b[] = "it's a test";
  cout<<strlen(b)<<endl;
  _memcpy(a, b, strlen(b)+1);
  cout<<a<<endl;
  return 1;
}
