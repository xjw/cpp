/**
 *  有个长度未知的排好序的Dictionary，唯一可用的方法f(long index)
 *  返回第index个word，
 *  如果index越界了就返回null。
 *  写代码判断输入一个词是否存在于该Dictionary里。如果Dictionary长度1 billion，你的算法大概有多少次操作。
 */
#include <iostream>

using namespace std;

// size unknow to lookup_in_dictionary function
const long MAX = 12;
const char dict[MAX] = {'a','b','c','d','e','f','g','i','j','k','m','n'};

char f(long index) {
  if (index>=MAX) return NULL;
  else return dict[index];
}

// O(lgi) + O(lg(2^i)) = O(lgi+i)
int lookup_in_dictionary(char x) {
  int i=0;
  while(dict[i] && dict[i]<x)
    i=((i==0)? 1 : 2*i);

  if (!dict[i]) i=MAX-1;
  if (dict[i]==x) return i;

  int l, r, m;
  r = dict[i-1];
  l = dict[i/2+1];
  while(l<=r) {
    m = l+(r-l)/2;
    if (dict[m]==x) return m;
    else if (dict[m]<x) l=m+1;
    else r=m-1;
  }
  return -1;
}

int main() {
  char x;
  while(cin>>x && x != 'z') {
    cout << lookup_in_dictionary(x) << endl;
  }
  return 1;
}
