#include <iostream>

using namespace std;
const int N=4;
void rotate(int [][N], int);

int main() {
  int a[4][4] = {
    {1,2,3,4},
    {5,6,7,8},
    {9,0,1,2},
    {3,4,5,6}
  };
  rotate(a,4);
  for (int i=0; i<N; ++i) {
    for (int j=0; j<N; ++j) {
      cout<<a[i][j];
    }
    cout<<endl;
  }
  return 0;
}

void rotate(int matrix[][N], int N) {
  for (int layer = 0; layer < N/2; ++layer) {
    int first = layer;
    int last = N - layer - 1;
    for (int i = first; i<last; ++i) {
      int offset = i - first;
      int top = matrix[first][i];
      // left -> top
      matrix[first][i] = matrix[last-offset][first];
      // bottom -> left
      matrix[last-offset][first] = matrix[last][last-offset];
      // right -> bottom
      matrix[last][last-offset] = matrix[i][last];
      // top -> right
      matrix[i][last] = top; // right <- saved top
    }
  }
}

