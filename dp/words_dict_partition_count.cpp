/**
 *  http://www.mitbbs.com/article_t/JobHunting/31730553.html
 */
#include <iostream>
#include <map>

using namespace std;

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

int main() {
  map<string, bool> dict;
  dict["aaa"] = true;
  dict["bb"] = true;
  dict["cc"] = true;
  dict["aaabb"] = true;
  dict["bbcc"] = true;

  string words = "aaabbcc";
  cout<< partition_count(dict, words) << endl;
  return 1;
}
