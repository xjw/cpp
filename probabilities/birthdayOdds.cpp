#include <iostream>

using namespace std;

const int days = 365;

int minPeople(int odds) {
  int n=0;
  double target, p;
  target = 1 - (double)odds/100;
  p = 1;
  while (p>target) {
    p = p * ((double)1 - (double)n/days);
    n++;
  }
  return n;
}

int main() {
  int odds;
  cin>>odds;
  cout<<minPeople(odds)<<endl;
  return 1;
}
