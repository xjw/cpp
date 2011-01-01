/*
 * Reference
 * http://www.drdobbs.com/184410529
 * http://www.seas.gwu.edu/~simhaweb/cs151/lectures/module6/module6.html
*/

#include <iostream>
#define M 6
#define N 5

using namespace std;

void printR(int i, int j, int x, int y, int area) {
  cout<<"("<<i<<","<<j<<")("<<x<<","<<y<<")="<<area<<endl;
}

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

int getArea(int x1, int y1, int x2, int y2) {
  if (x2<=x1 || y2<=y1) return 0;
  else return (x2-x1) * (y2-y1);
}


/////////////////////////////////////////////////////////////////////////
// Solution 1 Brute Force
bool isAllOne(bool a[M][N], int x1, int y1, int x2, int y2) {
  for (int i=x1; i<=x2; ++i) {
    for (int j=y1; j<=y2; ++j) {
      if (!a[i][j]) return false;
    }
  }
  return true;
}

/**
 * time complexity O(m^3*n^3) 
 */
void getMaxMatrixBruteforce(bool a[][N]) {
  int max, max_i, max_j;
  max = max_i = max_j = 0;
  for (int i=0; i<M; ++i) {
    for (int j=0; j<N; ++j) {
      for (int x=i; x<M; ++x) {
        for (int y=j; y<N; ++y) {
          int cur_max = getArea(i, j, x, y);
          if (cur_max>max && isAllOne(a, i, j, x, y)) {
            max = cur_max;
            max_i = i;
            max_j = j;
          }
        }
      }
    }
  }
  cout<<max_i<<"-"<<max_j<<"="<<max<<endl;
}


/////////////////////////////////////////////////////////////////////////
// Solution 2 Improvement to Brute Force
int growOne(bool a[][N], int i, int j, int &x, int &y) {
  int max, mx, my, max_y;
  max = 0;
  mx = x = i;
  my = y = j;
  max_y = N-1;
  while(x<M && a[x][j]) {
    y = j;
    while(y<=max_y && a[x][y]) y++;
    max_y = --y;
    int area = getArea(i, j, x, y);
    if (area > max) {
      mx = x;
      my = y;
      max = area;
    }
    x++;
  }
  x = mx;
  y = my;
  return max;
}

/**
 * Time Complexity O(m^2*n^2) 
 */
void getMaxMatrixBetterThanBrute(bool a[][N]) {
  int max, max_i, max_j, max_x, max_y;
  max = max_i = max_j = 0;
  for (int i=0; i<M; ++i) {
    for (int j=0; j<N; ++j) {
      int x, y, cur_max;
      x = y = cur_max = 0;
      cur_max = growOne(a, i, j, x, y);
      printR(i, j, x, y, cur_max);
      if (cur_max>max) {
        max = cur_max;
        max_i = i; max_j = j; max_x = x; max_y = y;
      }
    }
  }
  printR(max_i, max_j, max_x, max_y, max);
}

/////////////////////////////////////////////////////////////////////////
// Solution 3 Caching Number of 1 on the right
void updateCaching(bool a[][N], int c[][N], int i, int j) {
  if (j < N-1) c[i][j] = c[i][j+1];
  c[i][j] = a[i][j]? c[i][j]+1 : 0; //c[i][j]++ is wrong!!!!!!!!!!!!!!!!!
}

int growOneCaching(bool a[][N], const int c[][N], int i, int j, int &x, int &y) {
  int max, mx, my, max_y;
  max = 0;
  mx = x = i;
  my = y = j;
  max_y = N-1;

  while(x<M && a[x][j]) {
    y = min(max_y, j + c[i][j] -1);
    int area = getArea(i, j, x, y);
    if (area > max) {
      mx = x;
      my = y;
      max = area;
    }
    max_y = y;
    x++;
  }
  x = mx;
  y = my;
  return max;
}

void getMaxMatrixCaching(bool a[][N]) {
  int max, max_i, max_j, max_x, max_y;
  max = max_i = max_j = max_x = max_y = 0;
  int c[M][N];
  for (int i=0; i<M; ++i) {
    for (int j=0; j<N; ++j) {
      c[i][j] = 0;
    }
  }
  for (int i=M-1; i>=0; --i) {
    for (int j=N-1; j>=0; --j) {
      updateCaching(a, c, i, j);
      int x, y, cur_max;
      cur_max = growOneCaching(a, c, i, j, x, y);
      printR(i, j, x, y, cur_max);
      if (cur_max>max) {
        max_i = i; max_j = j; max_x = x; max_y = y; max = cur_max;
      }
    }
  }
  for (int i=0; i<M; ++i) {
    for (int j=0; j<N; ++j) {
      cout<<c[i][j]<<" ";
    }
    cout<<endl;
  }
  printR(max_i, max_j, max_x, max_y, max);
}

#include <stack>
/////////////////////////////////////////////////////////////////////////
// Solution 4 Better Caching
void updateBetterCaching(bool a[][N], int c[][N], int j) {
  c[M-1] = a[M-1][j]? 1 : 0;
  for (int i=M-2; i>=0; --i) {
    if (a[i][j]) c[i] = c[i+1]+1;
    else c[i] = 0;
  }
}

void getMaxMatrixBetterCaching(bool a[][N]) {
  int max, max_i, max_j, max_x, max_y;
  max = max_i = max_j = max_x = max_y = 0;
  int c[M];
  for (int i=0; i<M-1; ++i) c[i]=0;

  stack< pair<int, int> > st;
  for (int j=N-1; j>=0; --j) {
    updateBetterCaching(a, c, i);
    int max_width = 0;
    pair<int, int> p;
    for (int i=M-1; i>=0; --i) {
      int cur_width = c[i];
      if (cur_width>max_width) {
        p = make_pair(i, c[i]);
        st.push(p);
      }
      else {
      }
    }
  }
}

int main() {
  bool a[M][N] = 
   {
    {0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0}
   };
  // getMaxMatrix(a);
  getMaxMatrixCaching(a);
  
  return 1;
}
