/**
 * http://stackoverflow.com/questions/2070359/finding-three-elements-in-an-array-whose-sum-is-closest-to-an-given-number
 */

#include <iostream>
#include <algorithm>

using namespace std;

void findThreeSum(int a[],int n,int sum) {
  for (int i=0; i<n; ++i) {
    int k = 0;
    int j = n-1;
    while (k<i && i<j) {
      int r = a[i]+a[k]+a[j];
      if (r == sum) {
        cout << a[i] << "+" << a[k] << "+" << a[j] << "=" << sum << endl;
        k++;
        j--;
      }
      else if (r < sum) 
        k++;
      else 
        j--;
    }
  }
}

bool sum3(int a[], int n, int sum) {
    sort(a, a+n);

    bool ret = false;
    for (int i=0; i<n; i++) {
        int k = i+1;
        int j = n-1;
        while(k<j) {
            int r = sum-a[i]-a[j]-a[k];
            if (r==0) {
                ret = false;
                cout << a[i] << "+" << a[k] << "+" << a[j] << "=" << sum << endl;
                k++; 
                j--;
            }
            else if (r>0) k++;
            else j--;
        }
    }

    return ret;
}

int main() {
  // int a[] = {1,2,3,4,5};
  int a[] = {2,1,3,5,4};
  int size = sizeof(a)/sizeof(a[0]);

  sort(a,a+size);
  for(int i=0; i<size; ++i) {
    cout<<a[i]<<endl;
  }
  findThreeSum(a, size, 9);
  return 1;
}
