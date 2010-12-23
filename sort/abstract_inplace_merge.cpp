#include <iostream>

using namespace std;

const int N=8;

void abstract_in_place_merge(int a[], int l, int m, int u) {
  static int aux[N];
  int i, j, k;

  for (i=m+1; i>l; --i) aux[i-1]  = a[i-1];
  for (j=m; j<u; ++j) aux[u+m-j] = a[j+1];

  for (k=l; k<=u;k++) {
    if (aux[i]<aux[j])
      a[k] = aux[i++];
    else
      a[k] = aux[j--];
  }
}

int main() {
  int a[] = {1,2,5,8,2,4,5,7};
  int n = sizeof(a)/sizeof(a[0]);
  abstract_in_place_merge(a, 0, 3, n-1);
  for (int i=0; i<N; ++i) {
    cout<<a[i]<<endl;
  }
  return 1;
}
