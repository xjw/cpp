#include <iostream>
#include <string.h>
#include <sstream>
#include <iterator>

using namespace std;
// REGEX WAY
// preg_match_all('/[\S]+/',$str,$matches)

inline bool is_separator(char c) {
  return (c==' '||c==','||c=='.');
}

int words_count(const char *str) {
  int count=0;
  bool flag = true;
  while(*str) {
    if (is_separator(*str))
      flag = true;
    else if (flag) {
      count++;
      flag = false;
    }
    str++;
  }
  return count;
}

int words_count_stream(const char *str) {
  int count=0;
  istringstream ostr(str);
  istream_iterator<string> it(ostr);
  istream_iterator<string> end;
  while(it++!=end) count++;
  return count;
}

int main() {
  char str[100];
  cin.getline(str,100);
  cout << words_count(str) << endl;
  cout << words_count_stream(str) << endl;
}
