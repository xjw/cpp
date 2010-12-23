#include <iostream>
#include <string.h>
#include <assert.h>
#include <stdio.h>

using namespace std;

// the 1st version
char *encode(char *str) {
  cout<<str<<endl;
  char *t = new char[2*strlen(str)+1];
  char *w = t;
  char *start, *forward;
  for(start = str; *start; start = forward) {
    forward = start + 1;
    while(*forward  == *start) forward++;
    *w++ = *start;
    w += sprintf(w, "%d", forward - start);
  }
  *w = '\0';
  return t;
}

// second
void encode(string s) {
  string r;
  int i, j, l;
  i = j = 0;
  l = s.size();
  while(j<=l) {
    while(j<l && s[j]==s[i]) j++;
    cout << s[i] << j-i;
    i = j++;
  }
  cout<<endl;
}

/**
 * this is very nice code!!!!!!!!!! 
 */

void encode(const char *s) {
  assert(s);
  while(char c = *s) {
    int n = 1;
    while(c==*(++s)) n++;
    cout<<c<<n;
  }
  cout<<endl;
}

// not as good as the one above because the inilialization of count of 0 here
void printfreq(const char *s)
{
  assert(s);
  while(*s){
    int count=0;
    char c=*s;
    while(*s==c){
      count++;
      s++;
    }
    printf("%c%d",c,count);
  }
}

int main() {
  char a[50];
  cin>>a;
  encode(a);
  printfreq(a);
  return 1;
}
