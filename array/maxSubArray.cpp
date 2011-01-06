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
    //1. choose whether to include the previous result for max_ending_here
    //option 1: adding to previous max_so_far
    //option 2: starting from current as max_so_far (if previous<0)
    max_ending_here = (max_ending_here>0)? max_ending_here+a[i] : a[i];
    if (max_ending_here>max_so_far) max_so_far = max_ending_here;
  }
  return max_sofar;
}

/**
 * this return 0 for all negative array 
 */
int maxsubsumQuiz(int a[], int n) {
  int max_sum, max_cur;
  max_sum = max_cur = 0;
  for (int i=0; i<n; ++i) {
    max_cur += a[i];
    if (max_cur>max_sum) max_sum=max_cur;
    if (max_cur<0) max_cur=0;
  }
  return max_sum;
}

int main() {
  int a[] = {2,-6,7,-3,9,4};
  // int a[] = {-4,-6,-2,-3,-9,-4};
  cout<<maxSubArray(a, sizeof(a)/sizeof(a[0]))<<endl;
  cout<<maxsubsumQuiz(a, sizeof(a)/sizeof(a[0]))<<endl;
  return 1;
}
