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
 * http://www.algorithmist.com/index.php/UVa_108 
 *
 * First, calculate the vertical prefix sum for all columns (an O(n2) algorithm).
Second, assume that the maximum sub-array will be between row a and row b, inclusive. There are only O(n2) a, b pairs such that a < b. Try each of them.
Since we already have the vertical prefix sum for all columns, the sum of elements in arr[a..b][c] for column c can be computed in O(1) time. This allows us to imagine each column sum as if it is a single element of a one-dimensional array across all columns (one dimensional array with one row and n columns).
There's an O(n) algorithm to compute the maximum sub-array for a one-dimensional array, known as Kadane's Algorithm.
Applying the Kadane's algorithm inside each a and b combination gives the total complexity of O(n3).
 *
 * Time Complexity for code below O(M^2 * N)
 */
int sub(int a[M][N]) {
  //precompute caching
  int c[M][N];
  for (int j=0; j<N; ++j) {
    c[0][j] = a[0][j];
  }
  for (int i=1; i<M; ++i) {
    for (int j=0; j<N; ++j) {
      c[i][j] = c[i-1][j]+a[i][j];
    }
  }

  // for (int i=0; i<M; ++i) {
    // for (int j=0; j<N; ++j) {
      // cout << c[i][j] << " ";
    // }
    // cout<<endl;
  // }

  int max_sum=0;
  for (int t=0; t<M-1; ++t) {
    for (int b=t+1; b<M; ++b) {
      int cur_max, max_ending_here;
      cur_max = max_ending_here = 0;

      for (int j=0; j<N; j++) {
        int v = t? (c[b][j]-c[t-1][j]): c[b][j];
        max_ending_here = (max_ending_here>0)? max_ending_here+v : v;
        if (max_ending_here>cur_max) cur_max = max_ending_here;
      }

      if (cur_max>max_sum) max_sum = cur_max;
    }
  }
  return max_sum;
}


int main() {
  int a[M][N] = {
    1,  2, -1,
    -3, 1, 4 ,
    1, -5, -2,
  };
  cout<< bruteForce(a) <<endl;
  cout<< sub(a) <<endl;
  return 1;
}
