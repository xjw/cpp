#include "linkedlist.h"
#define swap(a,b) ((int)(a)) ^= ((int)(b)) ^= ((int)(a)) ^= ((int)(b))

int main() {
  List<int> l1, l2;
  l1.insert(5);
  l1.insert(3);
  l1.insert(2);
  l1.insert(1);
  l1.print();
  l1.reverse_cool();
  l1.print();

  // l2.insert(3);
  // l2.insert(2);
  // l2.insert(1);

  // l.reverse();
  // l.print();
  // l.find_n_to_last_using_two_pointers(0);
  // l.find_n_to_last_using_array(0);
  // l.reverse_recursive();
  // l.find_middle();

  return 0;
}
