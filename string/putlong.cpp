#include <stdio.h>
#include <iostream>

using namespace std;

void putlong(long n) {
  if (n<0) {
    putchar('-');
    n = -n;
  }

  if (n<10) {
    putchar(n+'0');
    return;
  }
  putlong(n/10);
  putchar(n%10+'0');
}

int main() {
  long n;
  cin>>n;
  cout<<n<<endl;
  // putlong(n);
  return 1;
}
