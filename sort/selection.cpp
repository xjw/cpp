#include <iostream>

using namespace std;

int partition(int a[], int l, int r) {
  int p=l;
  int v=a[r];
  for (int i=l; i<=r; i++) {
    if (a[i]<v) {
      swap(a[i], a[p]);
      p++;
    }
  }
  swap(a[p], a[r]);
  return p;
}

int selection(int a[], int n, int k) {
  int l, r;
  l = 0;
  r = n-1;
  while(r>=l) {
    int idx = partition(a, l, r);
    if (idx == k) return a[k];
    else if (idx>k) r = idx-1;
    else l = idx+1;
  }
  return 0;
}

int main() {
  int k=0;
  int a[] = {1,6,5,4,3,7};
  while (cin>>k && k!= -1) {
    cout << selection(a, sizeof(a)/sizeof(a[0]), k) << endl;
  }
  return 1;
}
