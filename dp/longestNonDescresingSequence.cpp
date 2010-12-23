/**
 *  http://en.wikipedia.org/wiki/Longest_increasing_subsequence
 *  http://www.algorithmist.com/index.php/Longest_Increasing_Subsequence
 *  http://www.algorithmist.com/index.php/Longest_Increasing_Subsequence.cpp
 *
 *  http://fqq11679.blog.hexun.com/21632261_d.html
 */

#include <iostream>

using namespace std;

void getLongestNonDescresingSequence(int a[], int n) {
  int *max = new int[n];

  for (int i=0; i<n; ++i) {
    max[i] = 1;
    for (int j=0; j<i; ++j) {
      if (a[i]>=a[j] && max[j]+1>max[i]) {
        max[i] = max[j]+1;
      }
    }
  }
  for (int i=0; i<n; ++i) {
    cout<<max[i]<<endl;
  }
}

int binarySearch(int a[], int n, int x) {
  int l, r, m;
  l=0;
  r=n-1;

  while(l<=r) {
    m = (l+r)/2;
    cout<<l<<"--"<<m<<"--"<<r<<endl;
    if (m==0) return 0;
    if (a[m] == x) return m;
    if (a[m] > x && a[m-1] <=x) return m-1;
    else if (a[m] < x) l = m+1;
    else r = m-1;
  }

  cout<<a[m]<<endl;
  return m;
}

void getLongestNonDescresingSequenceMoreEfficiently(int a[], int n) {
  int *max = new int[n];
  int *pre = new int[n];
  for (int i=0; i<n; ++i) {
    int j = binarySearch(max, sizeof(max)/sizeof(max[0]), a[i]);
    max[j] = a[i];
  }
}

int main() {
  // int a[] = {1,5,4,6,7,8,2,6,9,7};
  int a[] = {3,4,6,8,9,12};
  int size_a = sizeof(a)/sizeof(a[0]);
  getLongestNonDescresingSequenceMoreEfficiently(a, size_a);
  // int x;
  // cin>>x;
  // cout<<binarySearch(a, size_a,x)<<endl; 
  // getLongestNonDescresingSequence(a, size_a);

  return 1;
}
