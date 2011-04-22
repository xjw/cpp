/**
 * http://eternallyconfuzzled.com/tuts/algorithms/jsw_tut_hashing.aspx
 * http://en.literateprograms.org/Hash_function_comparison_(C,_sh)
 *
 * JAVA HASHCODE
 * http://stackoverflow.com/questions/3613102/why-use-a-prime-number-in-hashcode
 * http://stackoverflow.com/questions/299304/why-does-javas-hashcode-in-string-use-31-as-a-multiplier
 */

#include <iostream>

using namespace std;

typedef unsigned long hash_t;

hash_t add_hash(unsigned char *key) {
  hash_t hash=0;
  while(*key) hash += *key++;
  return hash;
}

hash_t xor_hash(unsigned char *key) {
  hash_t hash=0;
  while(*key) hash^=*key++;
  return hash;
}

hash_t rotating_hash(void *key) {
  unsigned char *k = (unsigned char *)key;
  hash_t hash=0;
  while(*k) {
    hash = (hash<<4)^(hash>>28)^*k++;
  }
  return hash;
}

hash_t shift_add_xor_hash(unsigned char *key) {
  hash_t hash=0;
  while(*key) hash^=(hash<<5)+(hash>>2)+*key++;
  return hash;
}

hash_t bernstein_hash(unsigned char *key) {
  hash_t hash=0;
  while(*key) hash=hash*33+*key++;
  // another way of computing *33
  // while(*key) hash=hash<<5+hash+*key++;
  return hash;
}
