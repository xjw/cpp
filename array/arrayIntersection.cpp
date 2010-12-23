#include <iostream>

using namespace std;

void findArrayIntersection(int a[], int b[], int m, int n) {
  for (int i=0; i<m;) {
    for (int j=0; j<n;) {
      if (a[i] == b[j]) {
        cout<<a[i]<<endl;
        i++;
        j++;
      }
      else if (a[i] > b[j]) j++;
      else i++;
    }
  }
}

int main() {
  int a[] = {1,2,4,5,9};
  int b[] = {2,3,4,5,6,10};
  findArrayIntersection(a, b, sizeof(a)/sizeof(a[0]), sizeof(b)/sizeof(b[0]));
  return 1;
}
