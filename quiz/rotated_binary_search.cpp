/*
 * CUP P181
 * 9.3 Given a sorted array of n integers that has been rotated an unknown number of times, 
 * give an O(log n) algorithm that finds an element in the array. 
 * You may assume that the array was originally sorted in increasing order.
 * EXAMPLE:
 * Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)
 * Output: 8 (the index of 5 in the array)
*/

#include <iostream>

using namespace std;

/**
 *  be very careful about boundary conditions !!!!!!
 *
 */
int rotated_binary_search(int *a, int x, int l, int u) {
  while(l<=u) {
    int m = l+(u-l)/2;
    if (a[m] == x) return m;
    else if (a[m]<x) {
      if (a[l]>a[u] && x>a[u]) u=m-1;
      else l=m+1;
    }
    else {
      if (a[l]>a[u] && x<a[u]) l=m+1;
      else u=m-1;
    }
  }
  return -1;
}

int main() {
  //         0 1 2 3 4 5 6 7
  int a[] = {6,7,8,1,2,3,4,5};
  // this is the catch for duplicate
  // int a[] = {2,2,2,2,2,3,2,2};
  int x;
  while(cin>>x && x != 'z') {
    cout << rotated_binary_search(a, x, 0, sizeof(a)/sizeof(a[0]) -1) << endl;
  }
}
