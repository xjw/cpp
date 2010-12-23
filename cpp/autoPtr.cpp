/**
 * http://suanfa.blogspot.com/2010/10/auto-ptr.html
 *  
 */

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main() {
  int *p1 = new int(3);
  auto_ptr<int> p2(p1);
  // still works because copy from pointer to smart pointer
  cout<<*p1<<endl;
  cout<<*p2<<endl;

  auto_ptr<int> p3(new int(4));
  auto_ptr<int> p4(p3);
  cout<<*p4<<endl;
  // cout<<*p3<<endl; // Segmentation fault, coz p3 is NULL

  vector<auto_ptr<int> > v;
  v.push_back(p1); // error, can not push int * to auto_ptr

  v.push_back(p4); // doesn't compile
  //  auto_ptr has a copy constructor with a non-const parameter, 
  //  so the compiler can't call it from vector::push_back() since the latter has const parameter.
  //  The reason is when you initialize one auto_ptr instance from 
  //  another the new instance disconnects the object from 
  //  the other instance and connects it to self 
  //  so avoid a dangling pointer situation when one instance deletes the object and
  //  the other still holds a pointer to it.

  return 1;
}
