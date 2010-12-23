#include <iostream>

using namespace std;

void swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}

int partition(int *a, int l, int r) {
  int i,m;
  i = m = l;
  while(i<=r) {
    if (a[i] < a[m]) {
      swap(a[i], a[m]);
      m++;
    }
    i++;
  }
  return m;
}

void qsort(int *a, int l, int r) {
  if (r>l) {
    int m = partition(a, l, r);
    qsort(a, l, m-1);
    qsort(a, m+1, r);
  }
}

int main() {
  // int a[] = {5,1,2,6,3,4,8,7};
  int a[] = {4,4,5,5,3,4,8,7};
  int size = sizeof(a)/sizeof(a[0]);
  // partition(a, size);
  qsort(a, 0, size-1);
  for(int i=0; i<size; ++i) {
    cout<<a[i]<<" ";
  }
  cout<<endl;
  return 1;
}
