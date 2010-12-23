/**
 * Chapter 5 of "Secure Coding in C and C++" by Seacord
 * http://www.informit.com/content/images/0321335724/samplechapter/seacord_ch05.pdf
 *
 * http://www.hardtoc.com/archives/119 
 * http://www.fefe.de/intof.html
 */

#include <iostream>
#include <limits.h>
#include <float.h>
#include <assert.h>

using namespace std;

/**
 * arithmetic operation with overflow check 
 *
 * a and b are signed int
 */

int add(int a, int b) {
  if ((a>0 && b>INT_MAX-a) || (a<0 && b<INT_MIN-a)) {
    // overflow
  }
  else {
    return a+b;
  }
}

int add2(int a, int b) {
  long long sum;
  assert(LLONG_MAX>INT_MAX);
  sum = (long long)a+b;
  if (sum>INT_MAX || sum<INT_MIN) {
    // overflow
  }
  else {
    return sum;
  }
}

int minus(int a, int b) {
  if ((b<0 && a>INT_MAX+b) || (b>0 && a<INT_MIN+b)) {
    // overflow
  }
  else {
    return a-b;
  }
}

int multiply(int a, int b) {
  if (a!=0 && INT_MAX/b<a) {
    // overflow
  }
  else {
    return a*b;
  }
}

int main() {
  cout<<-2147483648<<endl;
  if (-2147483648 > 0)     printf("positive\n");
	if (-2147483647 - 1 < 0) printf("negative\n");
	if (INT_MIN == -INT_MIN) printf("equal\n");
	if (FLT_MIN > 0)         printf("floating\n");

  return 1;
}
