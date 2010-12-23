#include <iostream>

using namespace std;

int findMissing(int a[], int n) {
  int r=0;
  for (int i=0; i<n; ++i) {
    r^=(i+1)^a[i];
  }
  return r^(n+1);
}

void findTwoMissing(int a[], int n) {
  int r=0;
  for (int i=0; i<n; ++i)
    r^=(i+1)^a[i];
  r^=(n+1);
  r^=(n+2);

  int j = r - (r&(r-1));
  // int j=1;
  // while(r) {
    // if (r&j) break;
    // j<<=1;
  // }

  int x,y;
  x = y = 0;
  for (int i=0; i<n; ++i) {
    if (a[i]&j) {
      x^=a[i];
    }
    if ((i+1)&j) {
      x^=(i+1);
    }
  }
  if ((n+1)&j) {
    x^=(n+1);
  }
  if ((n+2)&j) {
    x^=(n+2);
  }
  y = r^x;
  
  cout<<x<<endl;
  cout<<y<<endl;
}

int main() {
  int a[] = {1,2,4,5};
  int b[] = {3,2,5};
  // int b[] = { 1,2,4,5,9,7,8,10,3 };
  // cout<<findMissing(a,sizeof(a)/sizeof(a[0]))<<endl;
  findTwoMissing(b, sizeof(b)/sizeof(b[0]));
  return 1;
}
