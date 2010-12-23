#include <iostream>

using namespace std;

void testBit(int x) {
  cout << ((((~x)&(x-1))>>31)&1) << endl;
}

int main() {
  int x;
  cin>>x;
  testBit(x);
  return 1;
}
