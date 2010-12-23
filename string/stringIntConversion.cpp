#include <iostream>
#include <sstream>

// http://www.cplusplus.com/forum/general/13135/
// http://stackoverflow.com/questions/191757/c-concatenate-string-and-int
// http://stackoverflow.com/questions/228005/alternative-to-itoa-for-converting-integer-to-string-c

using namespace std;

string int2string1(int x) {
  string s;
  stringstream ss;
  ss<<x;
  s = ss.str();
}

int string2int(string s) {
  int r;
  stringstream ss(s);
  ss >> r;
  return r;
}

int main() {
  return 1;
}
