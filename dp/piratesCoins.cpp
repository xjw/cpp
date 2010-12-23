/**
 * 两海盗在分金币，金币放在N个瓶子里，每个瓶子放有金币，瓶子放在一排，
 * 两海盗都知道每个瓶子放的金币数目，分的规则是这样的，
 * 每个海盗呢只也取边上的一个瓶子，第一个，或最后一个。
 * 请你写一算法，帮其中一海盗获得最可以多的金币，
 * 前提是两海盗可是一样的聪明啊。
 * 给出算法复杂度 
 */

#include <iostream>

using namespace std;

int getMostCoins(int a[], int start, int end) {
  if (start == end) return a[start];
  int sum=0;
  for (int i=start; i<=end; ++i) {
    sum += a[i];
  }
  int choice1 = sum - getMostCoins(a, start+1, end);
  int choice2 = sum - getMostCoins(a, start, end-1);
  return (choice1>choice2)? choice1 : choice2;
}

int main() {
  int a[] = {5,7,8,4};
  cout<<getMostCoins(a, 0, (sizeof(a)/sizeof(a[0])) - 1)<<endl;
  return 1;
}
