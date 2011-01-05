#include <iostream>
#include <string.h>

using namespace std;

const int CHAR_MAX=256;


char *sunday(char *s1, char *s2) {
  if (!s1 || !s2) return NULL;
  int l1, l2;
  l1 = strlen(s1);
  l2 = strlen(s2);

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

int main() {
  char *a = "abcabcade";
  char *b = "bcad";
  cout << sunday(a, b) << endl;
  return 1;
}
