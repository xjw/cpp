#include <iostream>

using namespace std;

int c1=0;
int c2=0;

int gcd(int a, int b) {
  for (int c=min(a, b); c>0; c--) {
    c1++;
    if (a%c==0 && b%c==0) return c;
  }
}

/**
 * http://en.wikipedia.org/wiki/Euclidean_algorithm 
 */
int gcdEuclid(int a, int b) {
  c2++;
  if (b==0) return a;
  return gcdEuclid(b, a%b);
}

int main() {
  int a;
  int b;
  cin>>a;
  cin>>b;
  cout<< a%b <<endl;
  cout<< gcd(a, b) <<endl;
  cout<< gcdEuclid(a, b) <<endl;

  cout<<c1<<endl;
  cout<<c2<<endl;
  return 1;
}
