#include <iostream>

using namespace std;

void stack_grows_up_down(int *a) {
  int b;
  if (&b>a) {
    cout<<"stack grows up"<<endl;
  }
  else {
    cout<<"stack grows down"<<endl;
  }
}

int main() {
  int a;
  stack_grows_up_down(&a);
  return 1;
}
