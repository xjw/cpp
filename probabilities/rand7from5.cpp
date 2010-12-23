#include <iostream>
#include <stdlib.h>
/**
 * http://stackoverflow.com/questions/137783/given-a-function-which-produces-a-random-integer-in-the-range-1-to-5-write-a-fun/137809#137809 
 * http://stackoverflow.com/questions/137783?page=1&tab=newest#tab-top
 */

using namespace std;

int rand5() {
  return rand()%5+1;
}

int rand7() {
  int r;
  do {
    r = 5*(rand5()-1) + rand5();
  } while (r>21);

  return r%7 + 1;
}

int main() {
  time_t tt = time(NULL);
  for (int i=0; i<10; ++i) {
    srand(tt+i);
    cout<<rand7()<<endl;
  }
  return 1;
}
