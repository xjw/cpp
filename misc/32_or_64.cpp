#include <iostream>
using namespace std;

// http://www.safercode.com/blog/2009/03/10/portable-code-how-to-check-if-a-machine-is-32-bit-or-64-bit.html
// do not use int, use pointer
void is_32_or_64() {
  cout << sizeof (void *) << endl;
}

// for java 
// System.getProperty("sun.arch.data.model")

int main() {
  is_32_or_64();
}
