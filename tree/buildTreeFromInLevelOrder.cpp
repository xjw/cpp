#include <iostream>
#include "bst.h"

using namespace std;

int main() {
  // char *pre = "124536"; char *in = "425163";
  char *pre = "123"; char *in = "213";

  BST<char> bst;
  bst.buildTreeFromPreInOrder(pre, in);
  bst.printByLevel();

  return 1;
}
