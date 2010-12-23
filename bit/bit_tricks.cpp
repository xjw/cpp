#include <iostream>

using namespace std;

int main() {
  int x;
  int i;
  // set ith bit
  x |= 1<<i;
  // clear ith bit
  x &= ~(1<<i);
  // toggle ith bit
  x ^= 1<<i;
  // check
  return x & (1<<i);
}
