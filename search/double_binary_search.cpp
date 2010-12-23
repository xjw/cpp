#include <iostream>
// #include <math.h>
#include <cmath>

/**
 * be careful with abs!!!!!!!!
 * the abs in <cmath> is overloaded for different type int, double
 * however, NOT FOR the one in <stdlib.h> 
 *
 * so better use fabs which works for all the cases
 */

using namespace std;

const double DBL_EPSILON = 0.02;

int lower_bound(double a[], int n, double x) {
  int l, r, m, count;
  l = 0;
  r = n-1;
  while(r>=l) {
    m = l+(r-l)/2;
    if (a[m]+DBL_EPSILON<x) l=m+1;
    else r=m-1;
  }
  return l;
}

int count_using_binary_search(double a[], int n, double x) {
  int count = 0;
  int l = lower_bound(a, n, x);
  cout<<"l is "<<l<<" and count is ";
  while(l<n && (fabs(a[l]-x)<DBL_EPSILON)) {count++; l++;}
  return count;
}

int main() {
  double a[] = {1.01, 1.02, 1.03, 1.1, 2.2};
  int n = sizeof(a)/sizeof(a[0]);
  double x;
  while(cin>>x && x!=-1) {
    cout<< count_using_binary_search(a, n, x) << endl;
  }

  return 1;
}
