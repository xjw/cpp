//LRU Cache O(1) Get/Put implementation

#include <iostream>
#include <list>
#include <hash_map>
using namespace std;
using namespace __gnu_cxx;
#define N 13
#include <string.h>

struct eqstr
{
  bool operator()(char* s1, char* s2) const
  {
    return strcmp(s1, s2) == 0;
  }
};

struct CacheEntry{
  string key;
  string value;
};

class Cache{
private:
	list<CacheEntry*> cache;
        hash_map<char*, list<CacheEntry*>::iterator, hash<char*>, eqstr> chash;

public:
	string get(string key){
	        char* kstr = (char*)key.c_str();
		if(chash.find(kstr) != chash.end()){
			CacheEntry* e = *(chash.find(kstr)->second);
			//cout << "**" << e->key << ":" << e->value << endl;
			cache.erase(chash.find(kstr)->second);
			cache.push_front(e);
			return e->value;
		}
		return 0;
	}

	void put(string key, string value){
		if(cache.size() == N){
			CacheEntry* t = cache.back();
			//cout << "**" << t->key.c_str() << ":" << t->value.c_str() << endl;
			cache.pop_back();
			delete t;
		}

		CacheEntry * e = new CacheEntry;
                e->key = key;
                e->value = value;
		cache.push_front(e);
		chash.insert(make_pair((char*)key.c_str(), cache.begin()));
	}

	void print(){
		list<CacheEntry*>::iterator it = cache.begin();
		for(; it!=cache.end(); it++){
			cout << (*it)->key << ":" << (*it)->value << endl;
		}
	}
};

int main(){
	Cache cache;
	cache.put(string("1"), string("a"));
	cache.put(string("2"), string("b"));
	cache.put(string("3"), string("c"));
	cout << "Get " << cache.get(string("3")) << endl;
	cache.put(string("4"), string("d"));
	cache.print();
	cout << "Get " << cache.get(string("3")) << endl;
	cache.print();
    // if(cache.get(string("5")).compare(NULL)==0)
        // cout << "Get 5 failed\n";
}
