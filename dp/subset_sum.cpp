/**
 * http://en.wikipedia.org/wiki/Subset_sum_problem 
 */

#include <iostream>
using namespace std;

bool subsetSumDP(int a[], int n) {
  int P, N;
  P = N = 0;
  for (int i=0; i<n; ++i) {
    if (a[i]>0) P+=a[i];
    else N+=a[i];
  }
  int m = P-N+1;
  int **q = new int*[n];
  for (int i=0; i<n; ++i) {
    q[i] = new int[m];
  }

  int *s = new int[m];
  for (int i=0; i<m; ++i) {
    s[i] = N+i;
  }

  for (int i=0; i<m; ++i) {
    q[0][i] = (a[0] == s[i]);
  }

  for (int i=1; i<n; i++) {
    for (int j=0; j<m; j++) {
      int idx = s[j]-a[i]-N;
      q[i][j] = q[i-1][j] || (a[i]==s[j]) || (idx>=0 && idx<m && q[i-1][idx]);
    }
  }

  for (int i=0; i<n; ++i) {
    for (int j=0; j<m; ++j) {
      cout<<q[i][j]<< " ";
    }
    cout << endl;
  }
  cout << endl;

  int r = q[n-1][-N];

  for (int i=0; i<n; ++i) {
    delete [] q[i];
  }
  delete [] q;

  // cout<<r<<endl;
  return r;
}

int main() {
  // int a[] = {-3, -1, 2, 4};
  int a[] = {-3, 1, 2};
  int n = sizeof(a)/sizeof(a[0]);
  cout << subsetSumDP(a, n) << endl;
  return 1;
}
