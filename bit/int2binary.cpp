/**
 * http://www.cprogramming.com/tutorial/bitwise_operators.html 
 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <bitset>
#include <limits>
#include <limits.h>

using namespace std;

string int2binary(int n) {
  if (n==0) return "0";
  string s;
  for (int i=numeric_limits<int>::digits; i>=0; --i) { // i=31;
    if (n&(1<<i)) s+='1';
    else if(!s.empty()) {
      s+='0';
    }
  }
  return s;
}

void int2binaryRecursive(int n) {
  if (n<2) {
    cout << n;
    return;
  }
  int2binary(n>>1);
  cout<<n%2;
}
  
void binary2int(string str)
{
  // cout << bitset<numeric_limits<long>::digits>(str).to_ulong() << '\n' ;
}

int main() {
  int n;
  cin>>n;
  cout<<int2binary(n)<<endl;
  return 1;
}
