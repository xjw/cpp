#include <iostream>
#include <map>
#include <vector>

// http://stackoverflow.com/questions/1523393/permutations-of-letters-and-numbers-in-a-phone-number
using namespace std;

void printCombinations(const vector<string> &v, vector<char> &r, vector<string>::iterator it) {

  if (it>=v.end()) {
    for(vector<char>::iterator ch_it = r.begin(); ch_it!=r.end(); ch_it++) {
      cout<<*ch_it;
    }
    cout<<endl;
    return;
  }

  string s = *it;
  for(string::iterator s_it=s.begin(); s_it!=s.end(); s_it++) {
    vector<char> r_temp = r;
    r_temp.push_back(*s_it);
    printCombinations(v, r_temp, it+1);
  }
}

void setMapping(map<char, string> &m) {
  m['0'] = "0";
  m['1'] = "1";
  m['2'] = "abc";
  m['3'] = "def";
  m['4'] = "ghi";
  m['5'] = "jkl";
  m['6'] = "mno";
  m['7'] = "pqrs";
  m['8'] = "tuv";
  m['9'] = "wxyz";
}

int main() {
  char c[50];
  cin>>c;

  vector<string> v;
  vector<char> r;
  map<char, string> m;
  setMapping(m);

  char *p = c;
  while(*p) {
    if (m.find(*p) != m.end()) {
      v.push_back(m[*p]);
    }
    p++;
  }

  printCombinations(v,r,v.begin());

  return 1;
}
