#include <iostream>

using namespace std;

const int M=4;
const int N=4;

void printMatrixSpiral(int a[M][N]) {
  int m1,n1,m2,n2;
  for (m1=n1=0, m2=M-1, n2=N-1; m1<=m2 && n1<=n2; m1++, m2--, n1++, n2--) {
    int i, j;
    i = m1;
    j = n1;
    while(j<n2) {
      cout<<a[i][j];
      j++;
    }
    while(i<m2) {
      cout<<a[i][j];
      i++;
    }
    while(j>n1) {
      cout<<a[i][j];
      j--;
    }
    while(i>m1) {
      cout<<a[i][j];
      i--;
    }
  }
}

int main() {
  int a[M][N] = {
    1,2,3,4,
    3,4,5,6,
    4,5,6,7,
    7,8,9,8,
  };
  printMatrixSpiral(a);
  return 1;
}
