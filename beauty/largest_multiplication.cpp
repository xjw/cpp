#include <iostream>

using namespace std;

typedef unsigned long long int ull;

ull find_largest_multiplication(int a[], int n) {
  ull *r = new ull[n];
  ull *l = new ull[n];
  l[0] = r[n-1] = 1;

  ull max;
  ull t, d;
  max = t = 0ULL;
  int i;

  for (i=1; i<n; ++i)
    l[i] = l[i-1] * a[i-1];

  for (i=n-2; i>=0; --i)
    r[i] = r[i+1] * a[i+1];

  for (i=0; i<n; ++i) {
    t = l[i]*r[i];
    cout << t << endl;
    if (t > max) max=t;
  }

  delete [] r;
  delete [] l;

  return max;
}

int main() {
  int a[] = {1,5,3,2,4,6};
  int n = sizeof(a)/sizeof(a[0]);
  cout << find_largest_multiplication(a, n) << endl;

  return 1;
}
