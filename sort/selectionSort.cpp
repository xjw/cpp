#include <iostream>

using namespace std;

void selectionSort(int a[], int n) {
  for (int i=0; i<n; ++i) {
    int min = i;
    for (int j=i+1; j<n; ++j) {
      if (a[j]<a[min]) min = j;
    }
    if (min != i) {
      swap(a[i], a[min]);
    }
  }
}

void swap(int a[], int i, int j) {
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

void print(int a[], int n) {
  for (int i=0; i<n; ++i) {
    cout<<a[i]<<endl;
  }
}

int main() {
  int a[] = {5,4,1,2,9,6,7,8};
  int n = sizeof(a)/sizeof(a[0]);
  insertionSort(a, n);
  print(a, n);
  return 1;
}
