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

class A {
 public:
  const int i;
  A(int d) : i(d) {
  }
  ~A() {
    // throw 1;
  }
};

void test() {
  try {
    A a(1);
    throw 2;
  }
  catch (int e) {
    cout<< e << endl;
  }
}

class B {
 public:
  void t() {cout<<"tB"<<endl;}
};

class C {
 public:
  void t() {cout<<"tC"<<endl;}
};

class D : B, C {
};

int main() {
  D d;
  d.t();

  // hash_map<const char *, int, hash<const char *>, eqsch> month;
}
