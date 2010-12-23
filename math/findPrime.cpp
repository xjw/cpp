// http://stackoverflow.com/questions/1510124/program-to-find-prime-numbers-in-c+
// http://www.algolist.net/Algorithms/Number_theoretic/Sieve_of_Eratosthenes

#include <iostream>
#include <string.h>
#include <math.h>


using namespace std;

bool isPrime(int n) {
  if (n<2) return false;
  for(int i=2; i<=sqrt(n); i++) {
    if (n%i == 0) return false;
  }
  return true;
}

void findPrime(int n){
  for(int i=2; i<=n; ++i) {
    if (isPrime(i)) {
      cout<<i<<endl;
    }
  }
}

void sieve_of_eratosthenes(int n) {
  if (n<2) return;

  bool *p = new bool[n+1];
  memset(p, 1, sizeof(bool)*(n+1));

  // mark compsite
  for (int i=2; i*i<=n; i++) {
    if (p[i]) {
      for(int k=i*i; k<=n; k+=i) 
        p[k] = 0;
    }
  }

  // print
  for (int i=2; i<=n; i++) {
    if (p[i]) cout << i << endl;
  }

  delete[] p;
}


int main() {
  int n;
  cin>>n;
  // findPrime(n);
  sieve_of_eratosthenes(n);
  return 1;
}
