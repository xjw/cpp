#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;
const double precision = 0.0001;

//First approach -- Newtow-Raphson
double cubicRoot(double x) {
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
double cubicRoot(double x) {
    if(x<0) return 0-cubicRoot(-x);
    double a=0, b=x;
    while(abs(b-a)>precision) {
       double x0=(a+b)/2;
       double val=x0*x0*x0;
       if(val>x) a=x0;
       else b=x0;
    }
    return x0;
}

double sqrt(double n) {
  if (n<0) {
    return -1;
  }

  double high, low;

  // !!!important, different for n>1 or n<1
  if (n>1) {
    high = n;
    low = 0;
  }
  else {
    high = 1;
    low = n;
  }

  double m = (high+low)/2;

  while(fabs(m*m - n) > precision) {
    if (m*m > n) {
      high = m;
    }
    else {
      low = m;
    }
    m = (high+low)/2;
  }
  return m;
}

int main() {
  double a;
  cin>>a;
  cout<<sqrt(a)<<endl;
  cout<<cubicRoot(a)<<endl;
}
