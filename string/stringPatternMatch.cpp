#include <iostream>

using namespace std;


bool isMatchV1(const char *s, const char *p) {
    if (!s || !p) return false;
    if (*s == '\0' || *p == '\0') return *p == *s;

    // next is not *
    if (*(p+1) != '*') {
        return ((*p == *s ) || (*p == '.')) && isMatchV1(s+1, p+1);
    }
    // next is *
    while (*s == *p || (*s != '\0' && *p == '.')) {
        if (isMatchV1(s,p+2)) return true;
        s++;
    }
    return false;
}

/*
 * http://www.leetcode.com/2011/09/regular-expression-matching.html
 */
bool isMatch(const char *s, const char *p) {
    if (!s || !p) return false;
    if (*p == '\0') return *s == '\0'; 
    // next is not *
    if (*(p+1) != '*') {
        return *s && ((*p == *s ) || (*p == '.')) && isMatch(s+1, p+1);
    }
    // next is *
    while (*s == *p || (*s != '\0' && *p == '.')) {
        if (isMatch(s,p+2)) return true;
        s++;
    }
    return isMatch(s,p+2);
}


int wildcmp(const char *wild, const char *string) {
  // Written by Jack Handy - <a href="mailto:jakkhandy@hotmail.com">jakkhandy@hotmail.com</a>

  const char *cp = NULL, *mp = NULL;

  while ((*string) && (*wild != '*')) {
    if ((*wild != *string) && (*wild != '?')) {
      return 0;
    }
    wild++;
    string++;
  }

  while (*string) {
    if (*wild == '*') {
      if (!*++wild) {
        return 1;
      }
      mp = wild;
      cp = string+1;
    } else if ((*wild == *string) || (*wild == '?')) {
      wild++;
      string++;
    } else {
      wild = mp;
      string = cp++;
    }
  }

  while (*wild == '*') {
    wild++;
  }
  return !*wild;
}


int main() {
  if (wildcmp("*a*pg", "blah.apg")) {
    //printf("matched!\n");
  }
  cout << (isMatch("a","a.")) << endl;
  return 1;
}
