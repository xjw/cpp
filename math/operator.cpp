/**
 * Simulate -, *, / using + only  
 */

#include <iostream>

using namespace std;

int neg(int n) {
  int r = 0;
  int d = (n>0)? -1 : 1;
  while(n!=0) {
    r += d;
    n += d;
  }
  return r;
}

int minus(int n, int m) {
  return n + neg(m); 
}

int abs(int n) {
  return (n>0)? n : neg(n);
}

int multiply(int n, int m) {
  // save some computation time
  if (m > n) return multiply(m, n);

  int abs_m = abs(m);
  int sum = 0;
  while(abs_m--) {
    sum+=n;
  }
  return (m>0)? sum : neg(sum);
}

int divide(int n, int m) {
  if (m == 0) throw 20;

  int abs_n = abs(n);
  int abs_m = abs(m);

  int r = 0;
  while(abs_n >= abs_m) {
    abs_n -= abs_m;
    r++;
  }

  return ((n>0 && m<0) || (n<0 && m>0))? neg(r) : r;
}

int main() {
  cout<<divide(6,-1)<<endl;
  return 1;
}
