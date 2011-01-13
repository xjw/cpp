#include <iostream>

using namespace std;

int a, b, c, count;
count = a = b = c = 0;

int getMedian(int x) {
  count++;
  int m=0;
  if (count == 1) m=x;
  else if (count == 2) {
    a = x;
    m=(a+b)/2;
  }
  else if (count & 1) {
    if (x<a)
  }
}

int main() {
  int x;
  while(cin>>x && x!='z') {
    getMedian(x);
  }
  return 1;
}
