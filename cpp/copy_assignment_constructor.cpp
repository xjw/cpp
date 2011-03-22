#include <iostream>

using namespace std;

class A {
 public:
  int c;
  int *b;

  A(void) {
      cout<< "default constructor" << endl;
  }
  explicit A(int d) : c(d) {
      cout<< "non-default constructor" << endl;
  }

  A(const A &rhs) {
      cout<< "copy constructor" << endl;
      c = rhs.c;
  }

/**
 * http://en.wikipedia.org/wiki/Assignment_operator_(C%2B%2B) 
 */
  A& operator=(const A &rhs) {
      if (this != &rhs) {
          c = rhs.c;
          if (b != NULL) {
              delete [] b;
              b = new int[rhs.c];
              copy(rhs.b, rhs.b+rhs.c, b);
          }
      }
      cout<< "copy assignment constructor" << endl;
      return *this;
  }

  ~A() {
      cout<< "default destructor" << endl;
  }
};

class B : A {
 public:
    B() {
        cout<< "default constructor from B" << endl;
    }
    ~B() {
        cout<< "default destructor from B" << endl;
    }
};

int main() {
    A a = 3; 
    // equivalent to A a( A(3) ); complier optimize this to be A(3)
    // but copy constructor need to be accessible
    // refer to http://stackoverflow.com/questions/2847787/constructor-or-assignment-operator
    return 1;
}
