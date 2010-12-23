//http://stackoverflow.com/questions/856228/how-can-i-improve-this-square-root-method
//

#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

const double precision = 0.000000001;

//First approach -- Newtow-Raphson
double newtowCubicRoot(double x) {
    if(x==0) return 0;
    double x0=1;
    double x1=x0*2/3+x/3/x0/x0;
    while(abs(x1-x0) > precision) {
       x0=x1;
       x1=x0*2/3+x/3/x0/x0;
    }
    return x1;
}

//Second approach -- bisection
double bisecCubicRoot(double x) {
    if(x<0) return 0-bisecCubicRoot(-x);
    double a=0, b=x, x0;
    while(abs(b-a)>precision) {
       x0=(a+b)/2;
       double val=x0*x0;
       if(val>x) a=x0;
       else b=x0;
    }
    return x0;
}

double binarySqrt(double n) {
  if (n<0) return -1;

  double low, high, m;
  if (n>1) {
    low = 0;
    high = n;
  }
  else {
    low = n;
    high = 1;
  }
  m = (low + high)/2;
  int count=0;
  while(fabs(m*m-n)>precision) {
    if (m*m > n) {
      high = m;
    }
    else {
      low = m;
    }
    m = (low + high)/2;
    count++;
  }
  cout<<"binary ran "<<count<<" times"<<endl;
  return m;
}

// guess r by using r = (r+n/r)/2.0
double sqrt(double n) {
  double r=n/2;
  const int max = 100;
  int i=0;
  while(fabs(r*r-n)>=precision) {
  // for (i=0; i<max; ++i) {
    ++i;
    double last = r;
    r = (r + n/r)/2;
    if (fabs(r-last)<=precision) break;
  }
  cout<<"sqrt ran "<<i<<" times"<<endl;
  return r;
}

int main() {
  double n;
  cin>>n;
  cout<<binarySqrt(n)<<endl;
  cout<<sqrt(n)<<endl;
  // cout<<newtowCubicRoot(n)<<endl;
  // cout<<bisecCubicRoot(n)<<endl;
  return 1;
}


