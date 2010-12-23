/**
 * refer to
 * http://www.yolinux.com/TUTORIALS/C++Singleton.html 
 */

#include <iostream>

class A {
 public:
  static A* createInstance(); //mistake 1 no static
 private:
  A() {}; // mistake 2, missing {}
  static A* instance;
};

A* A::instance = NULL; 
// mistake 3, so static required during declaration
// not inilialization
// same for data members and functions

A* A::createInstance() {
  if (!instance) {
    instance = new A();
  }
  return instance;
}
///////////////////////////////////////
/**
 * better version 
 */
template <class T>
class Singleton {
 public:
  static T* Instance();

 private:
  Singleton();
  ~Singleton();
  Singleton(Singleton const&);
  Singleton& operator=(Singleton const&);
  static T* p_instance;
};

template <class T>
T* Singleton<T>::p_instance = NULL;

template <class T>
T* Singleton<T>::Instance() {
  if (!p_instance) {
    p_instance = new T;
  }
  return p_instance;
}

class user {
 public:
  void test() {}
  user() {};
};

int main() {
  user *u = Singleton<user>::Instance(); 
  u->test();

  return 1;
}
