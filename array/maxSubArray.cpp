#include <iostream>
#include <limits.h>

using namespace std;

/**
 * different from the algorithm sample on wikipedia
 * this deals with all negative cases 
 */
int maxSubArray(int a[], int n) {
  int max_ending_here, max_sofar;
  max_ending_here = max_sofar = INT_MIN;
  for (int i=0; i<n; ++i) {
    max_ending_here = (max_ending_here>0)? max_ending_here+a[i] : a[i];
    max_sofar = max(max_sofar, max_ending_here);
    cout<<max_sofar<<endl;
  }
  return max_sofar;
}

int main() {
  int a[] = {2,-6,7,-3,9,4};
  // int a[] = {-2,-6,-7,-3,-9,-4};
  cout<<maxSubArray(a, sizeof(a)/sizeof(a[0]))<<endl;
  return 1;
}
