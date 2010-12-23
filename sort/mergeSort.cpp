#include <iostream>

using namespace std;

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

void merge_array(int *a, int m, int *b, int n) {
  int k = m + n -1;
  int i = m - 1;
  int j = n - 1;
  while(i >=0 && j >=0) {
    if (a[i] >= b[j]) {
      a[k--] = a[i--];
    }
    else {
      a[k--] = b[j--];
    }
  }

  while(j >= 0) {
    a[k--] = b[j--];
  }
}

void mergeArray(int a[], int l1, int r1, int l2, int r2) {
  int *t = new int[r2-l1+1];
  int i, j, k;
  i = l1;
  j = l2;
  k = 0;
  while(i<=r1 && j<=r2) {
    if (a[i]<a[j]) t[k++] = a[i++];
    else t[k++] = a[j++];
  }
  while(i<=r1) t[k++] = a[i++];
  while(j<=r2) t[k++] = a[j++];
  for (i=l1, k=0; i<=r2; i++,k++) {
    a[i] = t[k];
  }
  delete [] t;
}

void mergeSort(int a[], int l, int r) {
  if (l>=r) return;
  int m = l+(r-l)/2;
  mergeSort(a, l, m);
  mergeSort(a, m+1, r);
  mergeArray(a, l, m, m+1, r);
}

void mergeSortIterative(int a[], int n) {
  for (int i=1; i<n; i+=i) {
    for (int j=0; j<n; j+=i)
      mergeArray(a, j, j+i, j+i+1, j+i+1+i>n? n : j+i+1+i);
  }
}


int main() {
  int a[] = {3,4,1,2,6,5,2};
  int n = ARRAY_SIZE(a);
  // mergeSort(a, 0, n-1);
  mergeSortIterative(a, n);
  for (int i=0; i<n; ++i) {
    cout<<a[i];
  }
  cout<<endl;
}
