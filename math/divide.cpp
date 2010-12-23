/**
 * Simulate -, *, / using + only  
 */

#include <iostream>
// #include <limits>

using namespace std;
const double DBL_EPSILON=0.0001;

/**
 * http://courses.cs.vt.edu/~cs1104/BuildingBlocks/divide.030.html 
 * http://discuss.joelonsoftware.com/default.asp?interview.11.401113.6
 * http://www.bearcave.com/software/divide.htm
 */

int divide_bisection(int x, int y) {
  int l, r;
  l = 1;
  r = x;
  double m = (l+r)/2;
  while(x-m*y>DBL_EPSILON) {
    if (x-m*y == DBL_EPSILON) return m;
    else if (x>m*y) l=m+1;
    else r=m-1;
    m=(l+r)/2;
  }
  return m;
}

int main() {
  cout<<divide_bisection(16,4)<<endl;
  return 1;
}
