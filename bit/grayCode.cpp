#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int getLowestBitPos(int n) {
  int pos = 0;
  int i=1;
  while(!(n&i)) {
    i <<= 1;
    pos++;
  }
  return pos;
}

vector<int> getGrayCode(int n) {
  vector<int> v;
  v.push_back(0);
  int steps = pow(n, 2);
  for (int i=1; i<steps; ++i) {
    int pos = getLowestBitPos(i);
    int prev = v.front();
    int code = prev ^ (1<<pos);
    v.push_back(code);
  }
  return v;
}

int main() {
  int n;
  cin>>n;
  cout<<(n&~(n-1))<<endl;
  // vector<int> v;
  // v = getGrayCode(n);
  // for(vector<int>::iterator it=v.begin(); it!=v.end(); ++it) {
    // cout<<*it<<endl;
  // }

  return 1;
}
