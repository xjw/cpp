/**
 * http://geeksforgeeks.org/?p=7953 
 */

#include <iostream>
using namespace std;

void swap (int &a, int &b) {
  int t = b;
  b = a;
  a = t;
}

void findDuplicateSwap(int a[], int n) {
  for(int i=0; i<n; ++i) {
    while(i+1 != a[i]) {
      if (a[a[i]-1] == a[i]) {cout<<i<<"-"<<a[i]<<endl; break;}
      swap(a[i], a[a[i]-1]);
    }
  }
}

//better solution
void findDuplicateSetNegative(int a[], int n) {
  for (int i=0; i<n; ++i) {
    if (a[a[i]-1]>0) {
      a[a[i]-1] = -a[a[i]-1];
    }
    else {
      cout<<-a[a[i]-1]<<endl;
    }
  }
}

int main() {
  // int a[] = {1,2,1,2,2,1,3,4};
  int a[] = {1,2,2,1,3,4};
  findDuplicate(a, sizeof(a)/sizeof(a[0]));
  findDuplicateSetNegative(a, sizeof(a)/sizeof(a[0]));
  return 1;
}
