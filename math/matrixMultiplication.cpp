#include <iostream>

using namespace std;

const int M = 2;
const int N = 2;
const int K = 3;

void matrixMultiplication(int a[M][N], int b[N][K]) {
  int c[M][K];

  for (int i=0; i<M; ++i) {
    for (int j=0; j<K; ++j) {
      c[i][j] = 0;
      for (int n=0; n<N; ++n) {
        c[i][j] += a[i][n]*b[n][j];
      }
    }
  }

  for (int i=0; i<M; ++i) {
    for (int j=0; j<K; ++j) {
      cout << c[i][j] << " ";
    }
    cout<<endl;
  }
}

int main() {
  // int a[M][N] = {
    // 1,1,1,
    // 2,2,2,
  // };
  // int b[N][K] = {
    // 1,
    // 1,
    // 1,
  // };

  int a[M][N] = {
    1,1,
    2,0,
  };
  int b[N][K] = {
    0,2,3,
    1,1,2,
  };
  matrixMultiplication(a, b);
  return 1;
}
