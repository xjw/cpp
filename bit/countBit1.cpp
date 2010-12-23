/**
 * http://everything2.com/title/Counting+1+bits 
 */

#include <iostream>

using namespace std;

// naive approach
// O(lgn) linear to number of bits
int countBitOne1(int x) {
  int r = 0;
  while (x) {
    r += (x&1);
    x >>= 1;
  }
  return r;
}

// smart = number of 1 bit
int countBitOne2(int x) {
  int r=0;

  // special handling for negative
  // interestingly this actually works even without this special handling
  // but it overflows with unexpected behavior, not reliable
  if (x<0) {
    r = 1;
    x &= ~(1<<31);
  }
  ////////////////////////////

  while(x) {
    cout<<x<<endl;
    x &= x-1;
    r++;
  }
  return r;
}

// extend from first method
// lg4(x)
int countBitOne3(int x) {
  int lookup[] = {0,1,1,2};
  unsigned int r = 0;
  while(x) {
    r += lookup[x&3];
    x >>= 2;
  }
  return r;
}

int main() {
  int x;
  cin>>x;
  // cout<<countBitOne1(x)<<endl;
  cout<<countBitOne2(x)<<endl;
  // cout<<countBitOne3(x)<<endl;
  return 1;
}
