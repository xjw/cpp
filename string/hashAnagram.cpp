/**
 * http://stackoverflow.com/questions/396005/word-anagram-hashing-algorithm 
 */

#include <iostream>
#include <map>
using namespace std;

// first 26 prime of 10k numbers
const int prime[] = {2, 41, 37, 47, 3, 67, 71, 23, 5, 101, 61, 17, 19, 13, 31, 43, 97, 29, 11, 7, 73, 83, 79, 89, 59, 53};

map<string, int> getFreq(string s) {
  map<string, int> m;
  string word="";
  for (string::iterator it=s.begin(); it!=s.end(); ++it) {
    if (*it == ' ') {
      if (!word.empty()) m[word]++;
      word = "";
    }
    else {
      word += *it;
    }
  }
  return m;
}

void findAnagram(string s){
  map<string, int> m = getFreq(s);
  int product = 1;
  for (map<string, int>::iterator it=m.begin(); it!=m.end(); ++it) {
    product *= it->first 
    cout<< it->first << it->second << endl;
  }
}

int main() {
  // how to c++ string array?
  string s = "man car kile arc none like";
  getFreq(s);

  return 1;
}
