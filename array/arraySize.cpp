#include <iostream>
using namespace std;

#if !defined(ARRAY_SIZE)
  #define ARRAY_SIZE(x) sizeof(x) / sizeof(x[0])
#endif

int main() {
  int d[] = {1,2,3,4,5};
  int *ptr = d;
  printf("%u\n", ARRAY_SIZE(d));
  printf("%u\n", sizeof(ptr));

  return 0;
}
