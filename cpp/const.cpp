#include <iostream>

using namespace std;

class A {
 public:
  int d;

  int* consta() const {
    return &d;   // const function requires if return is reference/pointer, const required
  }

  int* constb() {
    static int c = 0;
    return &c;
  }
};

int main() {
  A a;
  const A * b = &a;
  a.consta();
  b->constb(); // can not call a non-const function for a const object
}
