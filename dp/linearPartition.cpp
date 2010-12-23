#include <iostream>

using namespace std;

int getPartition(int a[], int n, int k, int start, int count) {
  if (count == k) return;
  for (int i=start, i<n; ++i) {
    sum = getPartition(a, n, k, i, k-1)
  }

}

int main() {
  int k = 3;
  int a[] = {1,2,3,4,5,6,7,8,9};
  int n = sizeof(a)/sizeof(a[0]);
  getPartition(a, n, 0, k);
  return 1;
}
