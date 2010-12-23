#include <iostream>
#include <stdlib.h>

using namespace std;

typedef char stackElement;

class Stack{
  public:
    Stack(int size);
    ~Stack();

    void push(int, stackElement);
    stackElement pop();

  private:
    int stackPointer[3];
    int stackSize;
    static int test;
    stackElement *content;
};

Stack::Stack(int size) {
  content = new stackElement[size*3];

  if (content == NULL) {
    cout<<"cannot initialize stack"<<endl;
    exit(1);
  }

  stackSize = size;
  for (int i=0; i<3; ++i) {
    stackPointer[i] = -1;
  }
}

Stack::~Stack() {
  delete[] content;
  content = NULL;
  stackSize = 0;
}

void Stack::push(int stackNum, stackElement element) {

}

int main() {
  Stack stack(100);

  return 0;
}
