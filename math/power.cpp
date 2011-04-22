/**
 *  http://geeksforgeeks.org/?p=28
 */

#include <iostream>
using namespace std;

double power1 (double x, int y) {
  if (y == 0) return 1;
  if (y < 0) {
    x = 1/x;
    y = -y;
  }
  double r=1;
  while(y>0) {
    r = r*x;
    y--;
  }
  return r;
}

double power2(double x, int y) {
  double r = x;
  int n = 1;
  while(y>0) {
    if (n*2<=y) {
      r = r*r;
      n = n*2;
      y = y-2;
    }
    else {
      r = r*x;
      y --;
    }
  }
  return r;
}

// lgn using recursion
double power3(double x, int y) {
  if (y==0) return 1;
  if (y<0) return power3(1/x, -y);
  double r = power3(x, y/2);
  r = r *r;
  return (y&1)? r*x : r;
}

// lgn different way of handling negative y
double power33(double x, int y) {
  if (y==0) return 1;
  double r = power3(x, y/2);
  r = r *r;
  if (y&1 == 0) {
    return r;
  }
  else {
    if (y>0) return r*x;
    else return r/x;
  }
}

// lgn no recursion
double power4(double x, int y) {
  if (y == 0) return 1;
  else if (y<0) {
    x = 1/x; 
    y = -y;
  }
  double r = 1;
  double m = x;
  while (y>0) {
    if (y & 1) {
      r = r * m;
    }
    y >>= 1;
    m = m * m;
  }
  return r;
}

// the original source
// Similar function, but depends on set bits
// in the exponent (no recursion - logN)
int power44(int x, unsigned n) {
  // Holds next power
  // Will be used if next bit is set (odd)
  int intermediateProduct = x;
  // Final result
  int result = 1;

  // Repeat this till we iterate all the set bits
  while(n)
  {
    // Effectively equvalent to n%2
    if (n & 1)
    {
      // If n is odd
      // power(a, b) = a * power(a, b/2) * power(a, b/2)
      // Note that next two terms are picked in the down statement
      result = intermediateProduct * result;
    }

    // Make up next bit
    n >>= 1;

    // Make the multiplication for next bit
    // Contributes for multiplication when n is even
    // power(a, b) = power(a, b/2) * power(a, b/2)
    intermediateProduct = intermediateProduct * intermediateProduct;
  }

  // Done! Return.
  return result;
}

int pow_i(int x, int y) {
    int r = 1;
    while(y) {
        if (y&1) r *=x;
        x *= x;
        y >>= 1;
    }
    return r;
}

int pow_r(int x, int y) {
    if (y==0) return 1;
    int m = pow(x, y/2);
    return (y&1)? m*m*x : m*m;
}

int main() {
  double x;
  int y;
  cin>>x;
  cin>>y;
  cout<<power1(x,y)<<endl;
  cout<<power2(x,y)<<endl;
  cout<<power3(x,y)<<endl;
  cout<<power33(x,y)<<endl;
  cout<<power4(x,y)<<endl;
  return 1;
}
