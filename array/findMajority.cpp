/**
 * Problem - You have to find a majority element in an array.
 * An element is majority element if it occurs more than half times the size of array.
 */

#include <iostream>

using namespace std;

int findMajority(int a[], int n) {
  int m=a[0];
  int count=1;
  for (int i=1; i<n; ++i) {
    if (a[i] == m)
      count++;
    else if (count == 0) {
      m = a[i];
      count = 1;
    }
    else
      count--;
    cout<<m<<"--"<<count<<endl;
  }
  return m;
}

int main() {
  int a[] = {1,1,6,6,6,6,2,6,1};
  int m = findMajority(a, sizeof(a)/sizeof(a[0]));
  cout<<m<<endl;
  return 1;
}
