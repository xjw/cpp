#include "hash_function.h"

int main() {
  char key[256];
  cin>>key;
  unsigned char *k = (unsigned char *)key;
  cout<<add_hash(k)<<endl;
  cout<<xor_hash(k)<<endl;
  cout<<shift_add_xor_hash(k)<<endl;
  cout<<bernstein_hash(k)<<endl;
  cout<<rotating_hash(key)<<endl;
  return 1;
}
