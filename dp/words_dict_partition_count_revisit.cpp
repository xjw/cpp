/**
 *  http://www.mitbbs.com/article_t/JobHunting/31730553.html
 */
#include <iostream>
// #include <ext/hash_map>
#include <unordered_map>

using namespace std;

struct eqstr {
  bool operator() (string s1, string s2) const {
    return s1==s2;
  }
};

typedef unordered_map<string, bool, hash<string>, eqstr> hash_table;

int partition_count(hash_table dict, string s) {
  int count = 0;

  if (dict[s]) count++;

  for (int i=1, len=s.size(); i<len; ++i) {
    if (dict[s.substr(0, i)]) {
      count += partition_count(dict, s.substr(i, len-i));
    }
  }

  return count;
}

int main() {
  hash_table dict;
  // unordered_map<string, bool, hash<string>, eqstr> dict;
  dict["aaa"] = true;
  dict["bb"] = true;
  dict["cc"] = true;
  dict["aaabb"] = true;
  dict["bbcc"] = true;

  string words = "aaabbcc";
  cout<< partition_count(dict, words) << endl;
  return 1;
}
