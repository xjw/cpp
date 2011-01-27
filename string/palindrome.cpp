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

///////////////////////////////////////////////////////////////////////
// 2nd time

/**
 * BIGGGGGGGGGGGGG BUG HERE 
 */
int findLongestPalindromFromIndex(char *s, int l, int r, int len) {
  while(l>=0 && r<=len-1 && s[l]==s[r]) {l--; r++;}

  // check this again to see whether you can find the bug!!!!!!!!
  // test case abaddd
  ///////////////////////////////////////
  // while(l>=0 && r<=len-1 && s[l--]==s[r++]);
  // ////////////////////////////////// 

  return r-l-1;
}

/**
 * best case O(n)
 * worst case O(n^2)
 * the less palindrom, the better run time
 */

int findLongestPalindrom2(char *s) {
  if (!s) return 0;
  int global_max, local_max;
  for (int i=1, p=0, len=strlen(s); i<=len-1; ++i) {
    local_max = max(findLongestPalindromFromIndex(s, i-1, i+1, len), findLongestPalindromFromIndex(s, i-1, i, len));
    global_max = max(global_max, local_max);
  }
  return global_max;
}

int main() {
  char s[5000];
  cin>>s;
  cout<<findLongestPalindrom(s)<<endl;
  cout<<endl;
  cout<<findLongestPalindrom2(s)<<endl;
  return 0;
}

