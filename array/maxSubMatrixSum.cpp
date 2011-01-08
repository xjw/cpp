#include <iostream>

using namespace std;

const int M=3;
const int N=3;

/**
 * time complexity O(x^3 * y^3)
 */
int bruteForce(int a[M][N]) {
  int max = 0;
  for (int i=0; i<M; ++i) {
    for (int j=0; j<N; ++j) {
      for (int m=i+1; m<M; ++m) {
        for (int n=j+1; n<N; ++n) {
          int cur=0;
          for (int x=i; x<=m; ++x) {
            for (int y=j; y<=n; ++y) {
              cur += a[x][y];
            }
          }
          if (cur>max) max = cur;
        }
      }
    }
  }
  return max;
}

/**
 *  
 */
int sub(int a[M][N]) {
  int max = 0;
  for (int i=0; i<M; ++i) {
    for (int j=0; j<N; ++j) {
    }
  }
}


int main() {
  int a[M][N] = {
    1,  2, -1,
    -3, 1, 4 ,
    1, 5, -2,
  };
  cout<< bruteForce(a) <<endl;
  return 1;
}
