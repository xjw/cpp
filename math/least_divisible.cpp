#include <iostream>

using namespace std;

int getLeastDivisible(int m, int n) {
  int max = 1;
  for (int i=max; i<=m && i<=n; ++i) {
    if (m%i==0 && n%i==0) {
      max = i;
    }
  }
  cout<<max<<endl;
  cout<<max * (m/max) * (n/max)<<endl;
}

int main() {
  getLeastDivisible(30,35);
  return 1;
}
