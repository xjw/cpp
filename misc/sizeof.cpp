#include <iostream>

using namespace std;

#define SIZEOFINT() (unsigned int)((int *)0 + 1)
#define SIZEOF(x) ((char *)(x+1)-(char *)x)

int main() {
  cout<< SIZEOFINT() <<endl;
  int *x;
  cout<< SIZEOF(x) <<endl;
  return 1;
}
