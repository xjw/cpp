#include <iostream>

using namespace std;

int v[] = {1, 2, 4};
int w[] = {2, 3, 5};
int W = 10;
int N = 3;

/**
 * unbounded knapsack 
 */
int k_unbounded_dp() {
  int m[W];
  m[0] = 0;
  for (int i=1; i<=W; ++i) {
    int local_max = 0;

    for (int j=0; j<N; ++j) {
      if (w[j]<=i) {
        int max_j = v[j]+m[i-w[j]];
        if (max_j>local_max) local_max=max_j;
      }
    }

    m[i] = max(m[i-1], local_max);
  }
  return m[W];
}

/**
 * 0-1 knapsack 
 *
 * (W*N+1) matrix!!!!!!!!
 * 0.............W
 * .
 * .
 * .
 * N
 */
int k_01_dp() {
  int m[N+1][W+1];
  for (int i=0; i<=W; ++i) {
    m[0][i] = 0;
  }
  for (int i=0; i<=N; ++i) {
    m[i][0] = 0;
  }
  for (int i=1; i<=N; ++i) {
    for (int j=1; j<=W; ++j) {
      int k=i-1; //be careful with this
      if (j<w[k]) m[i][j] = m[i-1][j];
      else m[i][j] = max(m[i-1][j], v[k]+m[i-1][j-w[k]]);
    }
  }

  for (int i=0; i<=N; ++i) {
    for (int j=0; j<=W; ++j) {
      cout<<m[i][j]<<" ";
    }
    cout<<endl;
  }
  return m[N][W];
}

// int k_1(int cap) {
  // if (cap <= 0) return 0;
  // int max = 0;
  // for (int i=0, t=0; i<N; ++i) {
    // if (w[i]<=cap && (t = v[i]+k_(cap-w[i]))>max) max = t;
  // }
  // return max;
// }

// int k_2(int cap) {
  // static int calculated[100];
  // if (calculated[cap]) return calculated[cap];
  // int max=0;
  // for (int i=0, t=0; i<N; ++i) {
    // if (w[i]<=cap && ((t=v[i]+k01_2(cap-w[i]))>max)){
      // max=t;
    // }
  // }
  // return calculated[cap] = max;
// }

int k(int i, int W) {
  if (i==0 || w==0) return 0;
  return max(k(i-1,W), k(i-1, W-w[i])+v[i]);
}

int main() {
  cout<< k_unbounded_dp() <<endl;
  cout<< k_01_dp() <<endl;
  // cout<< k(W) <<endl;
  // cout<< k01_1(W) <<endl;
  // cout<< k01_2(W) <<endl;
  return 1;
}
