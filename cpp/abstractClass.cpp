#include <iostream>

using namespace std;

class base {
 public:
  base () {
    cout<<"abstract class constructor"<<endl;
  }
  virtual void func1() = 0;
};

class deri : base {
 public:
  void func1() {
    cout<<"override virtual function in base"<<endl;
  }
};

int main() {
  deri d;
  return 1;
}
