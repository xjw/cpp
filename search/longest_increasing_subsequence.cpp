#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

vector<int> find_longest_increasing(int a[], int n) {
  vector<int> max;
  vector<int> cur;

  int temp = INT_MIN;

  for (int i=0; i<n; ++i) {
    if (a[i] < temp) {
      if (cur.size() > max.size()) {
        max = cur;
      }
      cur.clear();
    }
    temp = a[i];
    cur.push_back(temp);
  }

  return (max.size() > cur.size())? max : cur;
}

int main() {
  int a[] = {1,3,5,2,6,4,7,8,9,5,6};
  vector<int> r = find_longest_increasing(a, sizeof(a)/sizeof(a[0]));
  for (int i=0; i<r.size(); ++i) {
    cout<<r.at(i)<<" ";
  }
  cout<<endl;
  return 1;
}
