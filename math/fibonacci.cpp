#include <iostream>

using namespace std;

int fibRecursive(int n) {
  if (n < 0) return 0;
  else if (n == 1) return 1;
  else return fibRecursive(n-1) + fibRecursive(n-2);
}

int fibNonRecursive(int n) {
  if (n < 0) return -1;
  if (n == 0) return 0;
  int a, b, c;
  a = b = 1;
  for (int i=3; i<=n; ++i) {
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}

int main() {
  int t = 4;
  cout<<fibRecursive(t)<<endl;
  cout<<fibNonRecursive(t)<<endl;
}
