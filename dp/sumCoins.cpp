#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void printVector(vector<int> v) {
  for(vector<int>::iterator it=v.begin(); it != v.end(); ++it) {
    cout<<*it<<endl;
  }
  cout<<endl;
}


void allSumCoins(int a[], int n, int sum, vector<int> v) {
  if (sum == 0) {
    printVector(v);
  }
  if (sum<=0) return;

  for (int i=0; i<n; ++i) {
    if (a[i]>sum) break;

    if (!v.empty()) {
      if (a[i]<v.back()) continue;
    }

    v.push_back(a[i]);
    allSumCoins(a,n,sum-a[i],v);
    v.pop_back();
  }
}

/**
 * find sum with least coins
 */
void leastSumCoins(int a[], int n, int sum) {
  int *min = new int[sum+1];
  // initialize to infinity
  min[0]=0;
  for (int i=0; i<=sum; ++i) {
    min[i] = INT_MAX;
  }

  for (int i=1; i<=sum; ++i) {
    for (int j=0; j<n; ++j) {
      int t = i-a[j];
      if (t>=0 && min[t]+1<min[i]) 
        min[i] = min[t]+1;
    }
  }

  for (int i=0; i<=sum; ++i) {
    cout<<i<<"--"<<min[i]<<endl;
  }

  delete [] min;
}

int main() {
  int sum;
  cin>>sum;
  cout<<endl;
  int a[] = {1,5,10,25};
  int size_a = sizeof(a)/sizeof(a[0]);
  leastSumCoins(a, size_a, sum);
  // vector<int> v;
  // allSumCoins(a, size_a, sum, v);
  return 1;
}
