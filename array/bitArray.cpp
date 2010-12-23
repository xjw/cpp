#include <iostream>
#define NUM_BITS  8*sizeof(char)

using namespace std;

int main() {
  int a[] = {1,5,9,3,4,8,10,13,2,6,12,15};
  unsigned char *chp = new unsigned char[15/(NUM_BITS)+1];
  for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i) {
    chp[a[i]/NUM_BITS] |= 1 << a[i]%NUM_BITS;
  }
  for(int i=0; i<sizeof(chp)/sizeof(chp[0]); ++i) {
    for(int j=0; j<NUM_BITS; j++) {
      if (chp[i] & (1<<j)) cout<<NUM_BITS*i+j<<endl;
    }
  }
  delete[] chp;
}

