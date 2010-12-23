#include <iostream>

using namespace std;


void swap(int a[], int i, int j) {
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

void print(int a[], int n) {
  for (int i=0; i<n; ++i) {
    cout<<a[i]<<"-";
  }
  cout<<endl;
}

void insertionSortNoSwap(int a[], int n) {
  for (int i=1; i<n; ++i) {
    int j, temp;
    j = i;
    temp = a[i];
    while (j>0 && a[j-1]>temp) j--;
    for (int k=i; k>j; k--) {
      a[k] = a[k-1];
    }
    a[j] = temp;
  }
}

void insertionSortSwap(int a[], int n) {
  for (int i=1; i<n; ++i) {
    for (int j=i; j>0 && (a[j]<a[j-1]); --j) {
      swap(a[j], a[j-1]);
    }
  }
}

int main() {
  int a[] = {5,4,1,2,9,6,7,8};
  int b[] = {5,4,1,2,9,6,7,8};
  int n = sizeof(a)/sizeof(a[0]);
  insertionSortSwap(a, n);
  print(a, n);
  insertionSortNoSwap(b, n);
  print(b, n);
  return 1;
}
