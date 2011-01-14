/**
 * http://mitbbs.com/article_t1/JobHunting/31734753_0_2.html 
 */

#include <iostream>

using namespace std;

bool maze_1d.cpp(int m[], int n) {
  int max=0;
  for(int i=0; i<=max && i<n; ++i) {
    max = max(i+m[i], max);
    if (max>=n-1) return true;
  }
  return false;
}

int main() {
  int m[] = {4, 0, 5, 6, 1, 0};
  int n = sizieof(m)/sizeof(m[0]);
  return 1;
}
