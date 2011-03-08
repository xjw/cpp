/**
 * maze program, the order of north, south, east, west 
 * changes the path
 * '-' passable
 * '*' not passable
 * '0' path
 */

#include <iostream>
#define M 4
#define N 4

using namespace std;

bool pass(char m[][N], int x, int y) {
  return (x>=0 && y>=0 && x<=M-1 && y<=N-1 && m[x][y] == '-')? true : false;
}

bool findPath(char m[M][N], int x, int y) {
  if (!pass(m, x, y)) return false;

  m[x][y] = '0';
  if (
      (x == M-1 && y == N-1) || 
      findPath(m, x+1, y) || findPath(m, x, y+1) || 
      findPath(m, x-1, y) || findPath(m, x, y-1) 
      ) {
    return true;
  }
  else {
    m[x][y] = '-';
    return false;
  }
}

/*
bool DFS(node current, node dst) {
    if (current == dest) return;

    visited[current] = true;

    foreach node i in current's neighbor {
        if (!visited[i]) {
            DFS(i, dst);
        }
    }

    visited[current] = false;
}
*/

int main() {
  char m[M][N] = {
    '-', '-', '-', '*',
    '-', '-', '-', '*',
    '*', '-', '-', '*',
    '-', '*', '-', '-',
  };
  bool result = findPath(m, 0, 0);
  if (result) {
    for (int i=0; i<4; ++i) {
      for (int j=0; j<4; ++j) {
        cout << m[i][j] << " ";
      }
      cout << endl;
    }
  }
  else {
    cout<<"DEAD MAZE!!!"<<endl;
  }
  
  return 1;
}
