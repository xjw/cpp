#include <iostream>

using namespace std;

int main() {
  int a= 0x01;
  char *b = (char *)&a;
  cout<< ((*b)? "little endian" : "big endian")<<endl;
  return 1;
}
