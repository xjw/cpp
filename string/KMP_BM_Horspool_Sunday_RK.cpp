#include <iostream>
#include <string.h>

using namespace std;

const int CHAR_MAX=256;

/**
 * http://en.wikipedia.org/wiki/Boyer%E2%80%93Moore%E2%80%93Horspool_algorithm 
 */
char * boyer_moore_horspool(char *s1, char *s2) {
  if (!s1 || !s2) return NULL;
  int l1, l2;
  l1 = strlen(s1);
  l2 = strlen(s2);

  // preparing steps
  int steps[CHAR_MAX];
  for (int i=0; i<CHAR_MAX; ++i) {
    steps[i] = l2;
  }
  for (int i=0; i<l2; ++i) {
    steps[s2[i]] = l2-i-1;
    // cout<<s2[i]<<l2-i-1<<endl;
  }

  int p1, p2;
  p1 = p2 = l2-1;
  while(p1<l1) {
    while(p2>=0 && s1[p1] == s2[p2]) {p1--;p2--;}; 
    if (p2<0) return s1+p1+1;
    p1 += steps[s1[p1]];
    p2 = l2-1;
  }
  return NULL;
}

/**
 * Refer to
 * sunday算法研究——超越kmp的字符串匹配
 * http://blog.csdn.net/hairetz/archive/2009/10/26/4729397.aspx 
 */
char *sunday(char *s1, char *s2) {
  if (!s1 || !s2) return NULL;
  int l1, l2;
  l1 = strlen(s1);
  l2 = strlen(s2);

  // preprocess
  int steps[CHAR_MAX];
  for (int i=0; i<CHAR_MAX; ++i) {
    steps[i] = l2+1;
  }
  for (int i=0; i<l2; ++i) {
    steps[s2[i]] = l2-i;
  }

  int p1, p2, p;
  p1 = p2 = l2-1;
  while(p1<l1) {
    p = p1;
    while(p2>=0 && s1[p1]==s2[p2]) {p1--;p2--;}
    if (p2<0) return s1+p1+1;
    if (p == l1-1) return NULL;
    p1 += steps[s1[p+1]];
    p2 = l2-1;
  }
  return NULL;
}

/**
 *  http://blog.csdn.net/touzani/archive/2007/05/30/1632149.aspx
 */
char *rabin_karp(char *s1, char *s2, int d, int q) {
  if (!s1 || !s2) return NULL;
  int l1, l2;
  l1 = strlen(s1);
  l2 = strlen(s2);

  // precompute
  unsigned long long int h1, h2, h;
  h1 = h2 = 0;
  h=1;
  for (int i=0; i<l2; ++i) {
    h2 = (h2 * d + s2[i])%q;
    h1 = (h1 * d + s1[i])%q;
  }
  for (int i=0; i<l2-1; ++i) {
    h = h*d%q;
  }

  // matching
  for (int p=0; p<=l1-l2; p++) {
    // cout<<h1<<"-"<<h2<<endl;
    if (h1==h2) {
      int i = 0;
      while(i<l2 && s1[p+i]==s2[i]) i++;
      if (i == l2) return s1+p;
    }
    if (p<l1-l2) {
      h1 = ((h1-s1[p]*h%q+q)*d+s1[p+l2])%q;
    }
    else 
      break;
  }

  return NULL;
}

int main() {
  char a[] = "abcabcade";
  char b[] = "abcad";
  cout << rabin_karp(a, b, 128, 6999997) << endl;
  // cout << boyer_moore_horspool(a, b) << endl;
  return 1;
}
