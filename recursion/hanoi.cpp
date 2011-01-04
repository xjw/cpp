#include <iostream>

using namespace std;

enum tower{ONE, TWO, THREE};

void move(int, tower a, tower c) {
  cout<<"move from "<<a<<" to "<<c<<endl;
}

void hanoi(int n, tower a, tower b, tower c) {
  if (n<1) return;
  hanoi(n-1, a, c, b);
  move(1, a, c);
  hanoi(n-1, b, a, c);
}

int main() {
  int n;
  cin>>n;
  hanoi(n, ONE, TWO, THREE);
  return 1;
}
