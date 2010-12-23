#include <iostream>

using namespace std;

void swap(int &a, int &b) {
  int c = b;
  b =a;
  a = c;
}

int partition(int x[], int l, int r) {
  int p=l;
  int v=x[r];

  for (int i=l; i<r; i++) {
    if (x[i] < v) {
      swap(x[i], x[p++]);
    }
  }
  swap(x[p], x[r]);
  return p;
}

int partitionBetter(int x[], int l, int r) {
  int v=x[r];
  int i=l-1;
  int j=r;
  while(true) {
    while(x[++i]<v && j>i); 
    while(x[--j]>v && j>i);
    if (i>=j) break;
    swap(x[i], x[j]);
  }
  swap(x[i], x[r]);
  return i;
}

int partitionThreeWay(int x[], int l, int r) {
  int i,j,p,q,v;
  v = x[r];
  i = p = l-1;
  j = q = r;
  while (true) {
    while(x[++i]<v && i<j);
    while(x[--j]>v && i<j);
    if (i>=j) break;
    swap(x[i], x[j]);
    if (x[i]==v) swap(x[++p],x[i]);
    if (x[j]==v) swap(x[--q],x[j]);
  }
  for (int k=l; k<p; ++k) swap(x[k],x[i--]);
  for (int k=r-1; k>q; --k) swap(x[k],x[j++]);
}

void qsort(int x[], int l, int r) {
  if (l>=r) return;

  // int m=partition(x, l, r);
  // int m=partitionBetter(x, l, r);
  int m=partitionThreeWay(x, l, r);
  qsort(x, l, m-1);
  qsort(x, m+1, r);
  cout<<"---"<<endl;
}

int main() {
  // int x[] = {6, 5, 4, 3, 1,2,3,4,5};
  int x[] = {8,7,1,3,10,9,4,5,2,15,4};
  // int x[] = {4,4,4,4,4};
  int n = sizeof(x)/sizeof(x[0]);
  qsort(x, 0, n);

  for (int i=0; i<n; i++) {
    cout<<x[i]<<endl;
  }
  return 1;
}

