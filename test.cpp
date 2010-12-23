#include <iostream>
#include <limits.h>
#include <memory>
#include <string.h>
#include <queue>
#include <math.h>
#include <typeinfo>
// #include <hash_map>


using namespace std;
using namespace __gnu_cxx;

int words_count(char *str) {
  int count = 0;
  int len = strlen(str);
  for (int i=1; i<len; i++) {
    if ((i==1 || str[i-1] == ' ') && str[i] != ' ') {
      count++;
    }
  }
  return count;
}


class A {
 public:
  int a;
  A() {cout<<"A"<<endl;}
};

class B : public A {
 public:
  int a;
  void p() {cout<<a<<endl;}
  B() {cout<<"B"<<endl;}
};


struct eqstr {
  bool operator() (string s1, string s2) const {
    return (s1==s2);
  }
};

struct eqsch {
  bool operator() (const char * s1, const char * s2) const {
    return (0==strcmp(s1,s2));
  }
};

int main() {
  // hash_map<const char *, int, hash<const char *>, eqsch> month;
  int a = 1;
  a-=1+1;
  cout<<a<<endl;
}
