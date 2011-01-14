/**
 * http://math.stackexchange.com/questions/2356/is-it-possible-to-split-coin-flipping-3-ways
 * http://math.stackexchange.com/questions/1333/is-there-a-possibility-to-choose-fairly-from-three-items-when-every-choice-can-on/1335#1335 
 */

#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

// 0-1
int rand1() {
  return rand()%2;
}

// TIME COMPLEXITIES????????????????????????????
//
//
// and in general with probability 1/2n−1 for n≥2. The sum ∑n≥2n/2n−1 has value 3,
//
//
// You might wonder how many flips this takes, on average, to give a result. 
// With probability 1/2 you get a result on the second flip; with probability 1/4, 
// on the third flip; with probability 1/8, on the fourth flip, 
// and in general with probability 1/2n−1 for n≥2. The sum ∑n≥2n/2n−1 has value 3,
// so on average this method takes three flips.
//
// Each of the 3 DVDs has equal probability 1/4 of being chosen, 
// and with probability 1/4, you have to repeat from scratch. 
// This solution takes 2 trials with probabilty 3/4, 
// 4 trials with probability (1/4)(3/4), 
// 6 trials with probability (1/4)2(3/4) and so on, 
// so takes an expected number of 8/3 (≈ 2.66) trials. (See geometric distribution.)
//
//
// Note that the protocol above is the same as the OP's 4-DVD protocol, 
// with 3 "real" DVDs and one "null" DVD. 
// It's optimal among such variants of power-of-2 protocols, 
// and the following messy argument proves it's optimal (w.r.t expectation) among all (I think): in any protocol, 
// it's impossible to have decided after 1 trial, as that would mean some DVD has probability 1/2 > 1/3. 
// After 2 trials, of the 4 outcomes either 3 terminate or ≤1 (as 1/4 < 1/3 < 2/4). 
// If ≤1, then need at least 3 trials with probability at least 3/4, 
// so expectation is at least (1/4)2 + (3/4)3 > 8/3. 
//
int rand2() {
  int r = rand1() + rand1();
  if (r==0 || r==2) return r;
  else if (rand1() == 0) return 1;
  else return rand2();
}


int main() {
  time_t tt = time(NULL);
  map<int, int> m;
  for (int i=0; i<30000; ++i) {
    srand(tt+i);
    int r = rand2();
    m[r]++;
  }
  cout<< m[0] << endl;
  cout<< m[1] << endl;
  cout<< m[2] << endl;
  return 1;
}
