#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > getSubset(vector<int> d) {
  vector<vector<int> > v;
  int bit_max = 1 << d.size();
  while (--bit_max > 0) {
    vector<int> temp;
    for (int index=0, k=bit_max; k>0; index++, k >>=1) {
      if (k & 1 > 0) temp.push_back(d.at(index));
    }
    v.push_back(temp);
  }

  return v;
}

int main() {
  vector<int> v;
  vector<vector <int> > s;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  s = getSubset(v);

  for(int i=0; i<s.size(); ++i) {
    for (int j=0; j<s[i].size(); ++j) {
      cout<<s[i][j]<<" ";
    }
    cout<<endl;
  }

  return 1;
}
