/**
 *  http://thenoisychannel.com/2011/08/08/retiring-a-great-interview-problem/
 *  http://www.mitbbs.com/article_t/JobHunting/31730553.html
 */
#include <iostream>
#include <map>
#include <set>

using namespace std;

// code is simple but complexity is bad
// 2^n
int partition_count(map<string, bool> dict, string words) {
  int count = 0;

  if (dict[words])
    count++;
  
  for (int i=1, n=words.size(); i<n-1; i++) {
    if (dict[words.substr(0, i)]) 
      count += partition_count(dict, words.substr(i, n-i));
  }

  return count;
}

string partition_count_using_memorization(set<string> dict, string word, map<string, string> cache) {
  if (dict.find(word) != dict.end()) {
    return word;
  }
  if (cache.find(word) != cache.end()) {
    return cache[word];
  }
  int n = word.size();
  
  for (int i=1; i<n; i++) {
    string prefix = word.substr(0,i);
    if (dict.find(prefix) != dict.end()) {
      string temp = word.substr(i,n-i);
      string suffix = partition_count_using_memorization(dict, temp, cache);
      if (!suffix.empty()) {
        string s = prefix + " " + suffix;
        cache[word] = s;
        return s;
      }
    }
  }
  cache[word] = "";
  return "";
}

int main() {
  set<string> dict;
  dict.insert("aaa");
  dict.insert("bb");
  dict.insert("cc");
  dict.insert("aaabb");
  //dict.insert("bbcc");

  map<string, string> cache;
  string word = "aaabbcc";
  cout << partition_count_using_memorization(dict, word, cache) << endl;
  return 1;

  //cout<< partition_count(dict, words) << endl;
  return 1;
}
