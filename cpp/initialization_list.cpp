/**
 * http://www.cprogramming.com/tutorial/initialization-lists-c++.html 
 * have to for those!
 * 1. initialize const
 * 2. parent no default constructor
 * 3. initialize reference
 */

#include <iostream>

using namespace std;

class A {
};

class B : public A {
 public:
  int b;
  const int c;

  /* version 1 wrong
  B (int b) {
      b = b;
  }
  */

  /* version 2 works
  B (int b) {
      this->b = b;
  }
  */

  // best approach
  // const can only be initialized here
  B (int b) : b(b), c(b) {}
};

int main() {
    B b(3);
    cout << b.b << endl;
    return 1;
}
