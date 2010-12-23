#include <iostream>
#include <sstream>

using namespace std;

const int N = 26;
const int HEX = 16;

const string HEXCODE = "0123456789ABCDEF";

char getHexCode(int x) {
  return HEXCODE.at(x);
}

string decimalToHex(int n) {
  string s;
  while(n>0) {
    int r = n % HEX;
    s = getHexCode(r) + s;
    n = (n - r)/HEX;
  }
  return s;
}

string decimalToHexRecurisve(int n) {
  int r = n % HEX;
  string s;
  stringstream ss;
  ss << getHexCode(r);
  ss >> s;
  if (n<=r) return s;
  return decimalToHex((n-r)/HEX) + s; 
}

/**
 * standard decimal to 26 
 */
string decimalTo26(int n) {
  string s;
  while(n>0) {
    int r = n % N;
    s = char('a'+r) + s;
    n = (n-r)/N;
  }
  return s;
}

/**
 * special decimal to 26
 * 0 -〉a
 * 1 -> b
 * 2 -> c
 * 3 -> d
 * ......
 * 25 -> z
 * 26 -> aa (not exact decimal to 26, because here first a represent 1)
 * 27 -> ab
 * ......
 * 写一个算法把任意非负整数变为字符窜
 */
string decimalTo26Special(int n) {
  string s(1, char(n%26+'a'));
  n = n/26;
  while(n>0) {
    s = char((n-1)%26+'a')+s;
    n = (n-1)/26;
  }
  return s;
}

int main() {
  int n;
  cin>>n;
  cout<< decimalToHex(n) <<endl;
  cout<< decimalTo26(n) <<endl;
  cout<< decimalTo26Special(n) <<endl;
  return 1;
}
