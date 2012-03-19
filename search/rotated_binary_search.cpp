/**
 * http://www.ihas1337code.com/2010/04/searching-element-in-rotated-array.html 
 * http://geeksforgeeks.org/?p=1068
 */

#include <iostream>

using namespace std;

/**
 *  be very careful about boundary conditions !!!!!!
 *
 */
int rotated_binary_search(int *a, int x, int l, int u) {
  while(u>=l) {
    int m = (u + l)/2;
    if (a[m] == x) return m;

    if (a[l] < a[m]) {
      if (x > a[m])
        l = m+1;
      else if (x < a[l])
        l = m+1;
      else 
        u = m-1;
    }
    else if (x <= a[u])
      l = m + 1;
    else 
      u = m -1;
  }
  return -1;
}


/**
 * second time after failing onsite
 */
int rotatedBinarySearch(int a[], int n, int x) {
  int l, r, m;
  l = 0; r= n-1;
  while (r>=l) {
    m = l + (r-l)/2;
    if (x == a[m]) return m;

    if (a[l]<a[m]) {
      if (x<a[m] && x>=a[l]) r = m-1; // l to m is sorted
      else l=m+1;
    }
    else {
      if (x>a[m] && x<=a[r]) l = m+1; // m to r is sorted
      else r=m-1;
    }
  }
  return -1;
}

/**
 * better to compare with right 
 */

int findPivot(int a[], int n) {
  int l, r, m;
  l = 0;
  r = n-1;
  while(a[l]>a[r]) {
    m = l + (r-l)/2;
    if (a[m]>a[r]) l = m+1;
    else r=m;
  }
  return a[l];
}

int findP(int a[], int n) {
  int l, r, m;
  l = 0;
  r = n-1;
  while(a[l]>a[r]) {
    m = l + (r-l)/2;
    // cout<<a[l]<<"-"<<a[m]<<"-"<<a[r]<<endl;
    
    // v1
    // if (a[m]>=a[l]) l=m+1;
    // else r=m;
   
    // equivalent to 
    // v2
    if (a[m]<a[l]) r=m;
    else l=m+1;
  }
  return a[l];
}

int rotatedBinarySearchBBB(int a[], int n, int x) {
  int l=0;
  int r=n-1;
  while(r>=l) {
    int m = l+(r-l)/2;
    if (a[m] == x) return m;
    if (a[m]>a[l]) {
      if (a[m]>x && x>=a[l]) r=m-1;
      else l=m+1;
    }
    else {
      if (a[m]<x && x<=a[r]) l=m+1;
      else r=m-1;
    }
  }
  return -1;
}

/**
 * better to compare with right, consistent with findPivot
 * benefit of comparing with right is:
 *
 * if m==r, l must == r, because (l+r)/2 = r => l==r => l==r==m;
 *
 */
int rotatedBinarySearchFinal(int a[], int n, int x) {
  int l, r, m;
  l = 0;
  r = n-1;
  while (r>=l) {
    m = l + (r-l)/2;
    if (x == a[m]) return m;
    if (a[m]<a[r]) {
      if (a[m]<x && x<=a[r]) l=m+1;
      else r=m-1;
    }
    else {
      if (a[l]<=x && x<a[m]) r=m-1;
      else l=m+1;
    }
  }
  return -1;
}

int main() {
  //         0 1 2 3 4 5 6 7
  //int a[] = {6,7,8,9,1,2,3,4,5};
  // this is the catch for duplicate
  int a[] = {2,2,2,2,2,3,2,2};

  // int a[] = {0};
  // int a[] = {0,1};
  //int a[] = {1,0};
  // int a[] = {0,1,2};
  // int a[] = {2,0,1};

  // cout<< findPivot(a, sizeof(a)/sizeof(a[0])) <<endl;
  // cout<< findP(a, sizeof(a)/sizeof(a[0])) <<endl;

  int x;
  while(cin>>x && x != 'z') {
    cout << rotated_binary_search(a, x, 0, sizeof(a)/sizeof(a[0]) -1) << endl;
    cout << rotatedBinarySearchBBB(a, sizeof(a)/sizeof(a[0]), x) << endl;
    cout << rotatedBinarySearchFinal(a, sizeof(a)/sizeof(a[0]), x) << endl;
  }
}
