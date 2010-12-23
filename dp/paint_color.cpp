#include <iostream>

#define M 3
#define N 2

using namespace std;

enum color {blue, yellow, red, white};

void paintColor(color a[M][N], int x, int y, color o, color d) {
  cout << sizeof(a)<<endl;
  cout << sizeof(a)/sizeof(a[0])<<endl;
  cout << sizeof(*a)/sizeof(int)<<endl;
  // if (x<0 || y<0 || x>=M || y>=N) return;

  // if (a[x][y] == o) {
    // a[x][y] = d;
    // paintColor(a, x+1, y, o, d);
    // paintColor(a, x-1, y, o, d);
    // paintColor(a, x, y+1, o, d);
    // paintColor(a, x, y-1, o, d);
  // }
}

int main() {
  color a[3][2];
  a[0][0] = blue;
  a[0][1] = yellow;
  a[1][0] = yellow;
  a[1][1] = yellow;
  a[2][0] = yellow;
  a[2][1] = yellow;
  paintColor(a, 1, 0, a[1][0], red);

  for(int i=0; i<2; ++i) {
    for(int j=0; j<2; ++j) {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }

  return 1;
}
