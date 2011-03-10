/**
 * http://stackoverflow.com/questions/2057424/lru-implementation-in-production-code 
 * http://gcc.gnu.org/projects/cxx0x.html
 * http://stackoverflow.com/questions/2504178/lru-cache-design
 * http://www.codeproject.com/KB/recipes/LRUCache.aspx
 */
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
/**
 *
 * compile use g++ -std=c++0x
 *
 */

using namespace std;

template <class K, class V>
struct equal {
  bool operator() (list<V>::iterator i1, list<V>::iterator i2) const {
    return i1 == i2;
  }
};

template <class K, class V>
class LRU {
 public:
  LRU(int n);
  // void addItem(K key, V value);
  // V getItem(K k);
 private:
  int size;
  list<V> L;
  unordered_map<K, list<V>::iterator, hash<string>, equal<K, v> > M;
};

template <class K, class V>
LRU<K, V>::LRU(int n) {
  size = n;
}

// template <class K, class V>
// V LRU<K, V>::getItem(K key) {
  // return *M[key];
// }

// template <class K, class V>
// void LRU<K, V>::addItem(K key, V value) {
  // if (!M[key]) {
    // L.push_front(value);
    // M[key] = L.begin();
  // }
// }

int main() {
  LRU<string, int> cache(5);
  // cache.addItem("test",3);
  // cout << cache.getItem("test") << endl;
}
