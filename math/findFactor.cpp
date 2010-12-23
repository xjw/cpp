#include <iostream>
#include <set>

using namespace std;

void findFactor(int n) {
  if (n<=0) return;

  set<int> s;
  for (int i=1; i*i<=n; ++i) {
    if (n%i == 0) {
      s.insert(i);
      s.insert(n/i);
    }
  }

  for (set<int>::iterator it=s.begin(); it!=s.end(); ++it) {
    cout<<*it<<endl;
  }
}

int main() {
  int n;
  cin>>n;
  findFactor(n);
  return 1;
}
