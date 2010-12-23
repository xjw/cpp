#include <iostream>

using namespace std;

void swap(int a[], int i, int j) {
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

void bubbleSort(int a[], int n) {
  for (int i=0; i<n; ++i) {
    for (int j=1; j<n-i; ++j) {
      if (a[j-1] > a[j]) {
        swap(a[j-1], a[j]);
      }
    }
  }
}

void print(int a[], int n) {
  for (int i=0; i<n; ++i) {
    cout<<a[i]<<endl;
  }
}

int main() {
  int a[] = {5,4,1,2,9,6,7,8};
  int n = sizeof(a)/sizeof(a[0]);
  bubbleSort(a, n);
  print(a, n);
  return 1;
}
