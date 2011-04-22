//LRU Cache O(1) Get/Put implementation

#include <iostream>
#include <list>
#include <hash_map>
using namespace std;
using namespace __gnu_cxx;
#define N 3
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
			cache.erase(chash.find(kstr)->second);

			CacheEntry* test = new CacheEntry;
            test->key = test->value = "test";

			cache.push_front(e);
            cout << ((cache.begin() == chash.find(kstr)->second)? "yes" : "no");
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
	cout << "Get " << cache.get(string("1")) << endl;
    cache.print();
    cout << endl;
	cout << "Get " << cache.get(string("1")) << endl;
    cache.print();
    return 1;

	cout << "Get " << cache.get(string("1")) << endl;
	cache.print();
    cout<< endl;
	cache.put(string("2"), string("b"));
	cache.print();
    cout<< endl;
	cout << "Get " << cache.get(string("1")) << endl;
	cache.print();
    cout<< endl;
    return 1;
	cout << "Get " << cache.get(string("3")) << endl;
	cache.put(string("4"), string("d"));
  // cout << "Get " << cache.get(string("3")) << endl;
	cache.print();
    return 1;

	cache.put(string("4"), string("d"));
	cout << "Get " << cache.get(string("1")) << endl;
    return 1;
	cache.print();
	cout << "Get " << cache.get(string("3")) << endl;
	cache.print();
    // if(cache.get(string("5")).compare(NULL)==0)
        // cout << "Get 5 failed\n";
}
