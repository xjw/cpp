#include <iostream>
using namespace std;

/**
 * regular binary search 
 */

int binarysearch(int a[], int n, int t) {
  int l = 0, r = n -1, m;

  while(l <= r) {
    m = (l + r) / 2;
    if (a[m] == t) {
      return m ;
    }
    else if (a[m] < t) {
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return -1;
}

/**
 * binary search variation 1
 * find first of the element if array containing ordered duplicates 
 *
 * this is bad code!!!!
 * use lower_upper_bound function instead
 */

int binarysearch_find_first_in_duplicate_array(int a[], int n, int t) {
  int l=0, r=n-1, m;
  while(l <= r) {
    m = (l + r)/2;
    if (a[m] == t) {
      if (l == r) return m;
      r = m;
    }
    else if (a[m] < t) {
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return -1;
}

int main() {
  //         0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
  // int a[] = {1,1,2,2,2,3,3,3,3,3,3, 3, 4, 4, 5, 6, 6};
  // int a[] = {1,2,3};
  int a[] = {1,2};
  int n = sizeof(a)/sizeof(int);
  int t;
  while (cin>>t && (t != 'z')) {
    int found = binarysearch(a, n, t);
    // int found = binarysearch_find_first_in_duplicate_array(a, n, t);
    cout<<found<<endl;
  }
}
