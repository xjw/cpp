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
    cout<<s2[i]<<l2-i-1<<endl;
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

char *sunday(char *s1, char *s2) {
  if (!s1 || !s2) return NULL;
  int steps[CHAR_MAX];
  int l1, l2;
  l1 = strlen(s1);
  l2 = strlen(s2);
  for (int i=0; i<CHAR_MAX; ++i) {
    steps[i] = s1[]
  }
  

}

int main() {
  char *a = "abcabcade";
  char *b = "bcad";
  cout << boyer_moore_horspool(a, b) << endl;
  return 1;
}
