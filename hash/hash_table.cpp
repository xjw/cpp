#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

typedef string HASH_KEY;
typedef long int HASH_VAL;
const unsigned int HASHTABLE_SIZE=13;

/**
 * using separate chaining 
 */
class LinkedHashEntry {
  public:
    HASH_KEY key;
    HASH_VAL val;
    LinkedHashEntry *next;
    LinkedHashEntry(HASH_KEY k, HASH_VAL v) {
      key = k; val = v;
      next = NULL;
    }
};

class ChainHashtable {
  public:
    ChainHashtable();
    ~ChainHashtable();
    HASH_VAL get(HASH_KEY key);
    int put(HASH_KEY key, HASH_VAL val);
    int getIndex(HASH_KEY key);
    unsigned long getHash(HASH_KEY key);
    unsigned long BernsteinHash(HASH_KEY key);
    void printHashTable();
  private:
    LinkedHashEntry **table;
};

ChainHashtable::ChainHashtable() {
  table = new LinkedHashEntry*[HASHTABLE_SIZE];
  assert(table!=NULL);
  for (int i=0; i<HASHTABLE_SIZE; ++i) {
    table[i] = NULL;
  }
}

unsigned long ChainHashtable::BernsteinHash(HASH_KEY key) {
  unsigned long int h=0;
  for (int i=0; i<key.size(); ++i) {
    h = h *33 + key[i];
  }
  return h;
}

int ChainHashtable::getIndex(HASH_KEY key) {
  return BernsteinHash(key) % HASHTABLE_SIZE;
}

HASH_VAL ChainHashtable::get(HASH_KEY key) {
  int idx = getIndex(key);
  LinkedHashEntry *entry = table[idx];
  while(entry) {
    if (entry->key==key) return entry->val;
    entry=entry->next;
  }
  return NULL;
}

int ChainHashtable::put(HASH_KEY key, HASH_VAL val) {
  int idx = getIndex(key);
  LinkedHashEntry *entry = table[idx];
  while(entry) {
    if (entry->key == key) return -1;
    entry = entry->next;
  }
  LinkedHashEntry *new_entry = new LinkedHashEntry(key, val);
  new_entry->next = table[idx];
  table[idx] = new_entry;
}

ChainHashtable::~ChainHashtable() {
  for (int i=0; i<HASHTABLE_SIZE; ++i) {
    LinkedHashEntry *head, *next;
    head = table[i];
    while (head) {
      next = head->next;
      delete head;
      head = next;
    }
  }
  delete [] table;
}

void ChainHashtable::printHashTable() {
  for (int i=0; i<HASHTABLE_SIZE; ++i) {
    LinkedHashEntry *head = table[i];
    cout<<"index "<<i<<":"<<endl;
    while(head) {
      cout<<head->key<<"-"<<head->val<<"  ";
      head = head->next;
    }
    cout<<endl;
  }
}

int main() {
  ChainHashtable ht;
  ht.put("good", 1);
  ht.put("yes", 2);
  ht.put("no", 3);
  ht.put("bad", 4);
  ht.put("b", 5);
  ht.put("a", 6);

  ht.printHashTable();
  cout<<endl;

  cout<<ht.get("a")<<endl;
  return 1;
}
