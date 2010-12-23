#include <iostream>

using namespace std;

bool isPowerofTwo(int n) {
  return n && !(n&n-1);
}

int main() {
  int n;
  cin>>n;
  if (isPowerofTwo(n)) {
    cout<<"yes\n";
  }
  else {
    cout<<"no\n";
  }
  return 1;
}
