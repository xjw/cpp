/*
 * Reference
 * http://www.drdobbs.com/184410529
 * http://www.seas.gwu.edu/~simhaweb/cs151/lectures/module6/module6.html
*/

#include <iostream>
#define M 6
#define N 5

using namespace std;

void getMaxMatrix(bool a[M][N]) {
  int s[M][N];
  int i, j, max, max_i, max_j;

  for (i=0; i<M; ++i) {
    s[i][0] = a[i][0];
  }
  for (j=0; j<N; ++j) {
    s[0][j] = a[0][j];
  }

  max = max_i = max_j = 0;
  for (i=1; i<M; ++i) {
    for (j=1; j<N; ++j) {
      if (a[i][j] == 1) {
        s[i][j] = min(s[i-1][j], min(s[i][j-1], s[i-1][j-1]))+1;
        if (s[i][j]>max) {
          max = s[i][j];
          max_i = i;
          max_j = j;
        }
      }
      else {
        s[i][j] = 0;
      }
    }
  }

  for(i=0; i<M; ++i) {
    for(j=0; j<N; ++j) {
      cout << s[i][j] << " ";
    }
    cout << endl;
  }

  if (max>0) {
    for (i=max_i; i>max_i-max; --i) {
      for (j=max_j; j>max_j-max; --j) {
        cout << s[i][j] << " ";
      }
      cout << endl;
    }
  }
}

bool isAllOne(bool a[M][N], int x1, int y1, int x2, int y2) {
  for (int i=x1; i<=x2; ++i) {
    for (int j=y1; j<=y2; ++j) {
      if (!a[i][j]) return false;
    }
  }
  return true;
}

void getMaxMatrixBruteforce(bool a[][N]) {
  int max, max_i, max_j;
  max = max_i = max_j = 0;
  for (int i=0; i<M; ++i) {
    for (int j=0; j<N; ++j) {
      for (int x=i; x<M; ++x) {
        for (int y=j; y<N; ++y) {
          if (isAllOne(a, i, j, x, y)) {
            int cur_max = (x-i) * (y-j);
            if (cur_max>max) {
              max = cur_max;
              max_i = i;
              max_j = j;
              // cout<<max_i<<"-"<<max_j<<"-"<<x<<"-"<<y<<"-"<<max<<endl;
            }
          }
        }
      }
    }
  }
  cout<<max_i<<"-"<<max_j<<"="<<max<<endl;
}

int main() {
  bool a[M][N] = 
   {
    {0, 1, 1, 0, 1},
    {1, 1, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0}
   };
  // getMaxMatrix(a);
  getMaxMatrixBruteforce(a);
  
  return 1;
}
