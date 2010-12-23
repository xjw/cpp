#include <iostream>

using namespace std;

/**
 * Given an array A, output another array B such that B[k]=product of all 
 * elements in A but A[k]. You are not allowed to use division。
 */

void getArrayProducts(int a[], int n) {
  int *left = new int[n];
  int *right = new int[n];
  int *result = new int[n];
  left[0] = 1;
  right[n-1] = 1;

  for (int i=1; i<n; ++i) {
    left[i] = a[i-1] * left[i-1];
  }
  for (int i=n-2; i>=0; --i) {
    right[i] = a[i+1] * right[i+1];
  }
  for (int i=0; i<n; ++i) {
    result[i] = left[i]*right[i];
    cout<<result[i]<<endl;
  }

  delete [] left;
  delete [] right;
  delete [] result;
}

int main() {
  int a[] = {1,2,3,4};
  getArrayProducts(a, sizeof(a)/sizeof(a[0]));

  return 1;
}
