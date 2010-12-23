#include <iostream>
#include "stack.h"

using namespace std;

int main() {
  int size;
  cout << "Enter the size of the stack (greater than 0): ";
  cin >> size;

  Stack stack(size);

  cout << "\nEnter characters you wish to push onto the stack.\n";
  cout << "Enter Z when done.\n";

  char ch;
  cin >> ch;
  while (ch != 'Z') {
    stack.push(ch);
    cin >> ch;
  }

  while (!stack.isEmpty()) {
    cout<<stack.pop()<<endl;
  }

  return 0;
}
