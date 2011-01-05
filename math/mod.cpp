#include <iostream>

using namespace std;

unsigned int mod(int x, int n) {
  return x & (n - 1); 
}

int main() {
  int x, n;
  cin>>x;
  cin>>n;
  cout << mod(x, n) << endl;;
  cout << x%n << endl;;
  return 1;
}
