/**
 *  0b-1010010101 works here because of gcc extension
 *  ref 
 *  1. http://stackoverflow.com/questions/746171/best-algorithm-for-bit-reversal-from-msb-lsb-to-lsb-msb-in-c
 *  2. http://graphics.stanford.edu/~seander/bithacks.html#BitReverseObvious
 *
 */
#include <iostream>
#include <limits.h>

using namespace std;

string int2binary(int n) {
  string b;
  while(n>0) {
    b.insert(0,1,n%2+'0');
    n = n/2;
  }
  return b;
}

unsigned int reverseBits001(unsigned int n) {
  unsigned int r = n;
  // int s = sizeof(n)*CHAR_BIT-1;
  int s = CHAR_BIT-1;
  for (n>>=1; n; n>>=1) {
    r <<= 1;
    r |= n&1;
    s--;
    cout<<int2binary(r)<<endl;
  }
  return r<<s;
}

unsigned int reverseBits001ForInt(unsigned int n) {
  unsigned int r = n;
  int s = sizeof(n)*CHAR_BIT-1;
  for (n>>=1; n; n>>=1) {
    r <<= 1;
    r |= n&1;
    s--;
  }
  return r<<s;
}

/**
 * 12345678
 * 56781234 first switch first 4 with last 4
 * 78563412 then switch 12 with 34, 56 with 78
 * 87654321 then swith 1 with 2, 3 with 4, 5 with 6, 7 with 8
 */

unsigned int reverseBits007(unsigned int n) {
  n = ((n & 0xf0) >> 4) | ((n & 0x0f) << 4);

  // n = ((n & 0b11001100) >> 2) | ((n & 0b00110011) << 2);
  n = ((n & 0xcc) >> 2) | ((n & 0x33) << 2);

  // n = ((n & 0b10101010) >> 1) | ((n & 0b01010101) << 1);
  n = ((n & 0xaa) >> 1) | ((n & 0x55) << 1);
  return n;
}

unsigned int reverseBits007For32Bits(unsigned int x) {
  x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
  x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
  x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
  x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
  return((x >> 16) | (x << 16));
}


int main() {
  unsigned int x;
  cin>>x;
  cout<<reverseBits001(x)<<endl;
  // cout<<reverseBits007(x)<<endl;
  // cout<<reverseBits007For32Bits(x)<<endl;

  return 1;
}
