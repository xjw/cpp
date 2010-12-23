/**
 * http://www.eternallyconfuzzled.com/arts/jsw_art_rand.aspx
 *
 * http://linux.die.net/man/3/rand
 *
 * "If you want to generate a random integer between 1 and 10, you should always do it by using high-order bits, as in
    j = 1 + (int) (10.0 * (rand() / (RAND_MAX + 1.0)));
    and never by anything resembling (which uses lower-order bits)."
    j = 1 + (rand() % 10);
 *
 */

/**
 * http://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
 *
 * Potential sources of bias
 *
 * Modulo bias
 *
 * Doing a Fisher–Yates shuffle involves picking uniformly distributed random integers from various ranges.
 * Most random number generators, however—whether true or pseudorandom—will only directly provide numbers 
 * in some fixed range, such as, say, from 0 to 232−1. A simple and commonly used way to force such numbers
 * into a desired smaller range is to apply the modulo operator; that is, to divide them by the size of the
 * range and take the remainder. However, the need, in a Fisher–Yates shuffle, to generate random numbers 
 * in every range from 0–1 to 0–n pretty much guarantees that some of these ranges will not evenly divide 
 * the natural range of the random number generator. Thus, the remainders will not always be evenly 
 * distributed and, worse yet, the bias will be systematically in favor of small remainders.
 * For example, assume that your random number source gives numbers from 0 to 99 
 * (as was the case for Fisher and Yates' original tables), and that you wish to obtain an unbiased random
 * number from 0 to 15. If you simply divide the numbers by 16 and take the remainder, you'll find that the
 * numbers 0–3 occur about 17% more often than others. This is because 16 does not evenly divide 100: 
 * the largest multiple of 16 less than or equal to 100 is 6×16 = 96, and it is the numbers in the incomplete 
 * range 96–99 that cause the bias. The simplest way to fix the problem is to discard those numbers before
 * taking the remainder and to keep trying again until a number in the suitable range comes up. While in 
 * principle this could, in the worst case, take forever, in practice the expected number of retries will 
 * always be less than one.
 *
 * A related problem occurs with implementations that first generate a random floating-point 
 * number—usually in the range [0,1)—and then multiply it by the size of the desired range and round down.
 * The problem here is that random floating-point numbers, however carefully generated, always have only
 * finite precision. This means that there are only a finite number of possible floating point values in
 * any given range, and if the range is divided into a number of segments that doesn't divide this number
 * evenly, some segments will end up with more possible values than others. While the resulting bias will
 * not show the same systematic downward trend as in the previous case, it will still be there. 
 *
 * So both methods have bias
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

// to get random number [0, range)
int randMax(int range) {
  return rand() % range;
}

// this return [0,1)
double uniform_rand() {
  return rand() * (1.0/(RAND_MAX + 1.0));
}

// better way to use high order bits
int randMaxBetter(int range) {
  return (int)range * uniform_rand();
}

// to get random number [min, max) 
int randRange(int min, int max) {
  return min + rand()%(max-min);
}

// better way to do [min, max)
int randRangeBetter(int min, int max) {
  return min + (int)((max - min) * uniform_rand());
}
