/**
 * P66 CUP
 * Given a matrix in which each row and each column is sorted, write a method to find an element in it.
 *
 * Solution: starting from top right and eliminate along the way
 */

#include <iostream>
using namespace std;

#define M 3
#define N 2

bool search_in_sorted_matrix(int (*a)[N], int d) {
  int x=0;
  int y=N-1;
  while(y>=0 && x<M) {
    int c = a[x][y];
    if (c==d) {
      cout<<x<<"-"<<y<<endl;
      return true;
    }
    else if (c>d)
      y--;
    else
      x++;
  }
  return false;
}

int main() {
  int a[][N] = {
    1,2,
    3,4,
    5,6
  };
  search_in_sorted_matrix(a, 5);
  return 1;
}
