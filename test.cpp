#include <iostream>
#include <limits.h>
#include <memory>
#include <string.h>
#include <queue>
#include <math.h>
#include <typeinfo>
// #include <unordered_map>
// #include <hash_map>


using namespace std;

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

struct padding {
    char a;
    int b;
    char c;
};

class AA {
    void A();
};

class BB : public AA {
    void A();
};

struct T {
};

int main() {
    T t;

    int a[10];
    for (int i=0; i<9; ++i) {
        cout << a[i] << endl;
    }

    return 1;

    // unordered_map<int, int> m;
    // m[3] = 4;
    // cout << m[3] << endl;
    // if (m[4]==NULL) {
    // cout<<5<<endl;
    // }

    // hash_map<const char *, int, hash<const char *>, eqsch> month;
}
