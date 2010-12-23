#include <iostream>
#include <set>

using namespace std;

void printSumPair(int *a, int n, int sum) {
  set<int> s;
  for(int i=0; i<n; ++i) {
    if (s.find(sum - a[i]) != s.end()) {
      cout << a[i] << "+" << sum - a[i] << "=" << sum << endl;
    }
    s.insert(a[i]);
  }
}

void findSumFromTwoSortedArray(int *a, int *b, int m, int n, int sum) {
  int high, low;
  high = m-1;
  low = 0;
  while(high>=0 && low<n) {
    int cur_sum = a[high]+b[low];
    if (sum==cur_sum) {
      cout<<a[high]<<"+"<<b[low]<<"="<<sum<<endl;
      return;
    }
    else if (sum>cur_sum) {
      high--;
    }
    else {
      low++;
    }
  }
  cout<<"failed"<<endl;
}

int main() {
  // int a[] = {1,2,3,4,5,6,7,8,9};
  // printSumPair(a, sizeof(a)/sizeof(a[0]), 10);
  // int a[] = {1,1,1,1};
  // printSumPair(a, sizeof(a)/sizeof(a[0]), 2);
  int a[] = {6,5,2,1};
  int b[] = {7,4,3,2};
  int sum;
  cin>>sum;
  findSumFromTwoSortedArray(a, b, sizeof(a)/sizeof(a[0]), sizeof(b)/sizeof(b[0]), sum);
  return 1;
}
