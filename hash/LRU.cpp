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
#include <hash_map>
#include <string.h>

using namespace std;
using namespace __gnu_cxx;

struct eqstr {
    bool operator() (const char * s1, const char * s2) const {
        return strcmp(s1, s2) == 0;
    }
};

template <class V>
struct CacheEntry {
    string key;
    V val;
    CacheEntry(string k, V v) : key(k), val(v) {}
};

template <class V>
class LRU {
    public:
        LRU(int n);
        ~LRU();
        V get(string key);
        void put(string key, V value);
        void print();
        void pop_back();
        typedef list< CacheEntry<V>* > LIST;
        typedef hash_map<const char *, typename LIST::iterator, hash<const char *>, eqstr> HASHMAP;
        typedef typename LIST::iterator LIST_ITER;
        typedef typename HASHMAP::iterator HASHMAP_ITER;
    private:
        int MAX_SIZE;
        LIST L;
        HASHMAP M;
};

template <class V>
LRU<V>::LRU(int n) {
    MAX_SIZE = n;
}

template <class V>
LRU<V>::~LRU() {
    for(LIST_ITER it = L.begin(); it != L.end(); it++) {
        delete *it;
    }
}

template <class V>
V LRU<V>::get(string s) {
    const char *key = s.c_str();
    HASHMAP_ITER it = M.find(key);
    if (it == M.end()) return NULL;
    else {
        LIST_ITER lit = it->second;
        CacheEntry<V> *e = *lit;
        L.erase(lit);
        L.push_front(e);
        it->second = L.begin();
        return e->val;
    }
}

template <class V>
void LRU<V>::pop_back() {
    if (L.empty()) return;
    CacheEntry<V> *e = L.back();
    delete e;
    L.pop_back();
    HASHMAP_ITER it = M.find(e->key.c_str());
    if (it != M.end())
        M.erase(it);
}

template <class V>
void LRU<V>::put(string s, V value) {
    const char * key = s.c_str();
    HASHMAP_ITER it = M.find(key);
    CacheEntry<V> *e;

    if (it == M.end()) {
        if (L.size() == MAX_SIZE) pop_back();
        e = new CacheEntry<V>(s, value);
    }
    else {
        e = *(it->second);
        L.erase(it->second);
    }
    L.push_front(e);
    M[key] = L.begin();
}

template <class V>
void LRU<V>::print() {
    for(LIST_ITER it = L.begin(); it != L.end(); it++) {
        cout << (*it)->key << "-" << (*it)->val << endl;
    }
}

int main() {
    LRU<int> cache(5);
    cache.put("b",2);
    cout << cache.get("b") << endl;
    cache.put("b",3);
    cache.put("a",1);
    cache.print();
    cout << endl;
    cout << cache.get("b") << endl << endl;
    cache.put("c",4);
    cache.put("d",5);
    cache.put("e",6);
    cache.put("f",7);
    cache.print();

    cout << endl;
    cout << cache.get("a") << endl;
    cout << endl;
    cache.print();
}
