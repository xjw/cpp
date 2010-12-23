#include <iostream>
using namespace std;
const int N=5;

void setMatrixZero(int matrix[][N], int M, int N) {
  for (int i=0; i<M; ++i) {
    for (int j=0; j<N; ++j) {
      cout<<matrix[i][j]<<endl;
      if (matrix[i][j] == 0) {
        cout<<i<<"-"<<j<<endl;
        row[i] = 0;
        column[j] = 0;
      }
    }
  }

  for (int i=0; i<width; ++i) {
    for (int j=0; j<N; ++j) {
      if (row[i] == 0 || column[j] == 0) {
        matrix[i][j] = 0;
      }
    }
  }

}

int main() {
  int a[][5] = {
    {1,2,3,4,0},
    {5,6,7,8,0},
    {9,0,1,2,0},
    {3,4,5,6,0},
    {3,4,5,6,0},
    {3,4,5,6,0}
  };
  int M = sizeof(a)/sizeof(*a);
  int N = sizeof(a[0])/sizeof(a[0][0]);
  cout<<M<<"-"<<N<<endl;
  cout<<sizeof(a[0])<<endl;
  cout<<sizeof(a[0][0])<<endl;
  setMatrixZero(a,M,N);
  // for (int i=0; i<width; ++i) {
    // for (int j=0; j<N; ++j) {
      // cout<<a[i][j];
    // }
    // cout<<endl;
  // }
}
