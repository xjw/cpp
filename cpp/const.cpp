#include <iostream>

using namespace std;

class A {
 public:
  int d;

  static const float c = 1.7;

  const int* consta() const {
    return &d;   // const function requires if return is reference/pointer, const required
  }

  int* constb() {
    static int c = 0;
    return &c;
  }
};

void test_const(int a) {
}

int main() {
  A a;
  const A * b = &a;
  a.consta();
  cout<< a.c << endl;
  cout<< A::c << endl;

  A *test = 0;
  delete test;
  delete test;
  
  const int b;
  test_const(b);

  // b->constb(); // can not call a non-const function for a const object
}
