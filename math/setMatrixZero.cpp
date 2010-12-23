#include <iostream>
using namespace std;

const int N=5;

void setMatrixZero(int matrix[][N], int, int);

int main() {
  int a[][5] = {
    {1,2,3,4,0},
    {5,6,7,8,5},
    {9,0,1,2,0},
    {3,4,5,6,0},
    {3,4,5,6,7},
    {3,4,5,6,0}
  };
  int M = sizeof(a)/sizeof(*a);
  int N = sizeof(a[0])/sizeof(a[0][0]);
  setMatrixZero(a,M,N);
  for (int i=0; i<M; ++i) {
    for (int j=0; j<N; ++j) {
      cout<<a[i][j];
    }
    cout<<endl;
  }

  return 0;
}

void setMatrixZero(int matrix[][N], int M, int N) {
  int *row = new int[M];
  int *column = new int[N];

  for (int i=0; i<M; ++i) {
  }

  for (int i=0; i<M; ++i) {
    for (int j=0; j<N; ++j) {
      if (matrix[i][j] == 0) {
        row[i] = 1;
        column[j] = 1;
      }
    }
  }

  for (int i=0; i<M; ++i) {
    for (int j=0; j<N; ++j) {
      if (row[i] || column[j]) {
        matrix[i][j] = 0;
      }
    }
  }
}
