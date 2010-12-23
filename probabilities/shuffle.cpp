#include <iostream>
#include <stdlib.h>
#include <map>
#include <sstream>
#include "random.h"

using namespace std;

void shuffleKnuth(int a[], int n) {
  for (int i=n-1; i>0; --i) {
    // int j = rand() % (i+1);
    int j = randMax(i+1);
    if (i != j) {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }
}

int main() {
  map<string, int> m;
  time_t tt = time(NULL);

  for (int i=0; i<600000; ++i) {
    srand(tt+i);
    int a[] = {1,2,3};
    int n = sizeof(a)/sizeof(a[0]);
    shuffleKnuth(a, n);
    string s;
    for (int i=0; i<n; ++i) {
      s.append(1,a[i]+'0');
    }
    m[s]++;
  }

  for (map<string, int>::iterator it=m.begin(); it!=m.end(); ++it) {
    cout<<it->first<<"--"<<it->second<<endl;
  }

  return 1;
}
