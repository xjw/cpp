#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;


//////////////////////////////////////////////////////////////////////////
// first version using vector
void printVector(vector<int> v) {
  for(vector<int>::iterator it=v.begin(); it != v.end(); ++it) {
    cout<<*it<<" ";
  }
  cout<<endl;
}


void allSumCoins(int a[], int n, int sum, vector<int> v) {
  if (sum == 0) {
    printVector(v);
  }
  else if (sum>0) {
    for (int i=0; i<n; ++i) {
      if (a[i]>sum) break; //break is assuming a[] is increasing order

      if (!v.empty()) {
        if (a[i]>v.back()) continue; // prevent duplication
      }

      v.push_back(a[i]);
      allSumCoins(a,n,sum-a[i],v);
      v.pop_back();
    }
  }
}

//////////////////////////////////////////////////////////////////////////
// second version using array
void printArray(int c[], int n) {
  for (int i=0; i<n; ++i) {
    cout << c[i] << " ";
  }
  cout << endl;
}

void allSumCoinsBetterBackTracking(int a[], int c[], int n, int sum, int idx) {
  if (sum==0) printArray(c, idx);
  if (sum>0) {
    for (int i=0; i<n; ++i) {
      int cur=a[i];
      if (cur>sum) continue;
      if (idx>0 && c[idx-1]<cur) continue; //maintain one order either increasing or descreasing to prevent duplicate,both < and > work.
      c[idx] = cur;
      allSumCoinsBetterBackTracking(a, c, n, sum-a[i], idx+1);
    }
  }
}

//////////////////////////////////////////////////////////////////////////
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

void findLeastCoins(int a[], int n, int sum) {
  int count = 0;
  while(sum>0) {
    int i=n-1;
    while(i>=0) {
      if (a[i]<=sum) {
        sum-=a[i];
        count++;
      }
      i--;
    }
  }
  cout << count << endl;
}

int main() {
  int sum;
  cin>>sum;
  cout<<endl;
  //int a[] = {1,5,10,25};
  int a[] = {1,2,5,21,25};
  // int a[] = {1,5,10,25};
  int size_a = sizeof(a)/sizeof(a[0]);
  vector<int> v;
  allSumCoins(a, size_a, sum, v);
  cout << endl;

  int *c = new int[sum];
  allSumCoinsBetterBackTracking(a, c, size_a, sum, 0);
  delete [] c;

  cout << endl;
  //leastSumCoins(a, size_a, sum);
  findLeastCoins(a, size_a, sum);
  return 1;
}
