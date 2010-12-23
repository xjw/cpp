#include <iostream>
#define NSIZE 26

class TrieNode{
 public:
  TrieNode();
  ~TrieNode();
  void insert(char str[], TrieNode* root);

 private:
  TrieNode *children[NSIZE];
};

TrieNode::TrieNode() {
  for(int i=0; i<NSIZE; ++i) {
    children[i] = NULL;
  }
}

class Trie{
 public:
  Trie();
  ~Trie();
  TrieNode *root;
};

int main() {
  return 0;
}

