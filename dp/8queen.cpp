/**
 * classic eight queen problem  
 * using backtracking
 */

#include <iostream>
#include <stdlib.h>
#define M 8
#define N 8
using namespace std;

int col[N];
int count;

void print() {
  for (int j=0; j<N; ++j) {
    cout << j << "-" << col[j] << endl;
  }
  count++;
  cout << endl;
}

/**
 * backtracking check function 
 */

bool canPlace(int i) {
  for (int k=0; k<i; ++k) {
    if (col[k] == col[i] || abs(col[k]-col[i]) == abs(k-i)) 
      return false;
  }
  return true;
}

void queen(int i) {
  if (i >= N) {
    print();
    return;
  }
  for (int j=0; j<N; ++j) {
    col[i] = j;
    if (canPlace(i)) queen(i+1);
  }
}


int main() {
  int col[N];
  count = 0;

  for (int j=0; j<N; ++j) {
    col[j] = 0;
  }

  queen(0);
  cout<<endl<<count<<endl;

  return 1;
}
