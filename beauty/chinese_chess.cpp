#include <iostream>
#include <stdio.h>

using namespace std;

/**
 * this is genius!!!!!!!!!!!  
 *
 * number the position 1-9
 * total 9*9 = 81 possibilities
 *
 * for n (0-80) 1->9
 * n%9 + 1 generates 1-9
 * n/9 + 1 generates 1-9
 *
 * n/9%3 determine the vertical position
 * same for n%9%3
 *
 *
 * AGAIN, AWESOMENESS!!!!!!!!
 */
void printCombination() {
  int n=81;
  while(n--) {
    if (n/9%3 == n%9%3) continue;
    cout << n/9+1 << "-" << n%9+1  << endl;
  }
}

// solution 2 not as good as first one, but more intuitive
struct {
  unsigned char a:4;
  unsigned char b:4;
} i;

void pp() {
  for(i.a = 1; i.a <= 9; i.a++)
    for(i.b = 1; i.b <= 9; i.b++)
      if(i.a % 3 != i.b % 3)
        printf("A = %d, B = %d\n", i.a, i.b);
}


int main() {
  printCombination();
  // pp();
  return 1;
}
