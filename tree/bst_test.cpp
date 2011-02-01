#include "bst.h"
#include "bst_iterator.h"
#include <iostream>

using namespace std;

void inOrderUsingIterator(BST<int> *bst) {
  TreeIter<int> *it = new TreeIter<int>(bst);
  it->inOrderFirst();
  while(!it->isDone()) {
      cout << it->current() << endl;
      it->inOrderNext();
  }
}

void inOrderUsingIteratorStack(BST<int> *bst) {
  TreeIter<int> *it = new TreeIter<int>(bst);
  it->inOrderFirstStack();
  while(!it->isDoneStack()) {
      cout << it->currentStack() << endl;
      it->inOrderNextStack();
  }
}

void preOrderUsingIterator(BST<int> *bst) {
  TreeIter<int> *it = new TreeIter<int>(bst);
  it->preOrderFirst();
  while(!it->isDone()) {
      cout << it->current() << endl;
      it->preOrderNext();
  }
}

int main() {
  BST<int> *bst = new BST<int>;
  bst->insert_item(6);
  bst->insert_item(9);
  bst->insert_item(8);
  bst->insert_item(10);
  bst->insert_item(2);
  bst->insert_item(3);
  bst->insert_item(4);
  bst->insert_item(5);

  bst->printByLevel();

  // bst->check();
  // bst->delete_item(6);
  // bst->check();

  // bst->printByLevel();
  // bst->printByLevelQueue();
  // bst->printByLevelQueueNewLine();
  // bst->printByLevelQueueNewLineNoToken();
  // delete bst;

  // cout<<endl;
  // int arr[] = {1,2,3,4,5,6};
  // BST<int> *bst1 = new BST<int>;
  // bst1->root = bst1->insertFromArray(arr, 0, 5);
  // bst1->printByLevel();

  cout<<endl;
  preOrderUsingIterator(bst);
  cout<<endl;
  inOrderUsingIterator(bst);
  cout<<endl;
  inOrderUsingIteratorStack(bst);
  cout<<endl;

  return 0;
}
