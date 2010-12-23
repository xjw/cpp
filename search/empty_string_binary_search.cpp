/**
 * P183 CUP
 *  9.5 Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string.
 *  Example: find “ball” in [“at”, “”, “”, “”, “ball”, “”, “”, “car”, “”, “”, “dad”, “”, “”] will return 4
 *  Example: find “ballcar” in [“at”, “”, “”, “”, “”, “ball”, “car”, “”, “”, “dad”, “”, “”] will return -1
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findString(vector<string> v, string s, int l, int u) {
  while(l<=u && v.at(u).empty()) {
    u--;
  }
  while(l<=u && v.at(l).empty()) {
    l++;
  }

  if (l > u) return -1;

  while (l <= u) {
    int m = (l + u)/2;
    int k = m;

    while (m<=u && v.at(m).empty()) {
      m++;
    }

    int r = s.compare(v.at(m));

    // STRANGE HERE?????
    // have to use >0????
    if (r == 0)
      return m;
    else if (r > 0)
      l = m+1;
    else
      u = k-1;
  }

  return -1;
}

int main() {
  // string a = "abc";
  // string b = "def";
  // if (a.compare(b)) {
    // cout << "a bigger than b"<<endl;
  // }
  // return 1;
  vector<string> v;
  v.push_back("abc");
  v.push_back("");
  v.push_back("bcd");
  v.push_back("");
  v.push_back("def");
  cout<<findString(v, "bcd", 0, v.size()-1)<<endl;
  return 1;
}
