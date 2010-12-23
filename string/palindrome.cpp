#include <iostream>
#include <string.h>
using namespace std;

bool isAnagram(char *s, int start, int end) {
  if (start>=end) return false;

  while(end>start) {
    if (s[end--] != s[start++]) return false;
  }

  return true;
}

int findLongestPalindrom(char *s) {
  int n = strlen(s);
  int max = 0;
  int start=0;
  for (int i=0; i<n; ++i) {
    int l=0;
    int j=n-1;

    if (j-l+1<=max) break;

    while (j>i) {
      if (isAnagram(s, i, j)) {
        l = j-i+1;
        break;
      }
      j--;
    }

    if (l>max) {
      max=l;
      start=i;
    }
  }
  // print palindrom
  if (max>0) {
    string ans;
    ans.insert(0, s, start, max);
    cout<<ans<<endl;
  }
  return max;
}

int main() {
  char s[5000];
  cin>>s;
  cout<<findLongestPalindrom(s)<<endl;
  return 0;
}

