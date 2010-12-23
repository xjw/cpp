// #include <iostream>
#include <map>
#include "random.h"

using namespace std;

void testRandom() {
  map<int, int> m;
  time_t tt = time(NULL);
  int range = 5;

  for (int i=0; i<100000; ++i) {
    srand(tt+i);
    // m[randMax(range)]++;
    m[randMaxBetter(range)]++;
  }

  for (map<int, int>::iterator it=m.begin(); it!=m.end(); ++it) {
    cout<<it->first<<"--"<<it->second<<endl;
  }
}

int main() {
  testRandom();

  return 1;
}
