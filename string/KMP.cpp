#include <iostream>
#include <string.h>

using namespace std;

const int CHAR_MAX=256;

char *preCompute(char *s, int m[]) {
  char *cp = s;
  while(*cp) {
    m[*cp-'0'] = cp-s;
    cp++;
  }
}

char * sunday(char *str1, char *str2) {
  int m[CHAR_MAX];
  for (int i=0; i<CHAR_MAX; ++i) {
    m[i] = -1;
  }
  preCompute(str2,m);
  // for (int i=0; i<CHAR_MAX; ++i) {
    // cout<<m[i]<<endl;
  // }

  int l1 = strlen(str1);
  int l2 = strlen(str2);
  char *e1 = str1+l1-1;
  char *e2 = str2+l2-1;
  
  char *s1 = str1;
  char *s2 = str2;
  char *p1, *p2;
  while(*s1 && s1+l2-1<=e1) {
    p1 = s1+l2-1;
    p2 = s2+l2-1;
    while(p2>=s2 && *p2==*p1) {
      p2--;
      p1--;
    } 
    if (p1<s1) return s1;
    int idx = m[*p1-'0'];
    if (idx == -1) s1+=(l2-1);
    else s1+=(l2-idx-1);
  }
  return NULL;
}

int main() {
  char *a = "abcabcade";
  char *b = "bcad";
  cout << sunday(a, b) << endl;
  return 1;
}
