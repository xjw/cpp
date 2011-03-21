/**
 * http://johanjeuring.blogspot.com/2007/08/finding-palindromes.html 
 *
 * Solution 1: O(n^2), no optimization
 * i from 0->len-1, check the largest palindrome starting from i
 *
 * Solution 2: best case O(n), optimized
 * i from 1->len-1, expand left/right from i
 *
 * Solution 3: worse than solution, more than O(n^2)
 *  1. Original string is A
 *  2. Reverse string is B
 *  3. Find common strings are C, D, E ....
 *  4. Find palindromic strings in step 3, suppose C, D.
 *  5. Find the max length of strings in step 4. Return.
 *
 * Solution 4: Suffix Tree/Array
 *  http://www.allisons.org/ll/AlgDS/Tree/Suffix/
 *  http://www.math.tau.ac.il/~haimk/seminar02/suffixtrees.ppt
 *
 *
 */

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

int findLongestPalindrom1(char *s) {
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
  global_max = local_max = 0;
  for (int i=1, p=0, len=strlen(s); i<=len-1; ++i) {
    local_max = max(findLongestPalindromFromIndex(s, i-1, i+1, len), findLongestPalindromFromIndex(s, i-1, i, len));
    global_max = max(global_max, local_max);
  }
  return global_max;
}

int main() {
  char s[5000];
  cin>>s;
  cout<<findLongestPalindrom1(s)<<endl;
  cout<<endl;
  cout<<findLongestPalindrom2(s)<<endl;
  return 0;
}

