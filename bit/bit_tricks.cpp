#include <iostream>

using namespace std;

/**
 * returned number has x's lowest bit set to off 
 */
int getLowestBitOff (int x) {
  return x & (x-1);
}

/**
 * returned number is the number coming from the lowest set bit in x
 * which means return is 2^n (n>=0)
 */
int getLowestSetBit (int x) {
  return x ^ (x & (x-1));
}

int setithBit (int x, int i) {
  return x | 1<<i;
}

int clearithBit (int x, int i) {
  return x & ~(1<<i);
}

int toggleithBit (int x, int i) {
  return x ^ (1<<i);
}

bool isithBitSet (int x, int i) {
  return x & (1<<i);
}

int main() {
  int x;
  int i;

  cin>>x;
}
