#include <iostream>
#include <string.h>

using namespace std;

void multiDPrint(int **a, int m, int n) {
  for (int i=0; i<m; ++i) {
    for (int j=0; j<n; ++j) {
      cout<<a[i][j];
    }
    cout<<endl;
  }
  cout<<endl;
}

int editDistance(char a[], char b[]) {
  int m = strlen(a);
  int n = strlen(b);
  int i, j;
  int M=m+1;
  int N=n+1;

  int **d = new int*[M];
  for (int i=0; i<M; ++i) {
    d[i] = new int[N];
  }

  for (int i=0; i<M; ++i) {
    d[i][0] = i;
  }
  for (j=0; j<N; ++j) {
    d[0][j] = j;
  }

  for (i=1; i<M; ++i) {
    for (j=1; j<N; ++j) {
      if (a[i-1] == b[j-1]) {
        d[i][j] = d[i-1][j-1];
      }
      else {
        d[i][j] = min(min(d[i-1][j-1], d[i-1][j]), d[i][j-1])+1;
      }
    }
  }
  multiDPrint(d, M, N);
  int r = d[m][n];

  for (int i=0; i<m; ++i) {
    delete [] d[i];
  }
  delete [] d;

  return r;
}

int main() {
  char a[50];
  char b[50];
  cin>>a;
  cin>>b;
  cout<<editDistance(a, b)<<endl;
  return 1;
}
