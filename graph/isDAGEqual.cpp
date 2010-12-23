#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class DAG {
  T data;
  vector<DAG<T> > neighbors;
};

template <typename T>
bool isDAGEqual(DAG<T> a, DAG<T> b) {
  if (a == NULL || b == NULL) return (a==NULL && b==NULL);
  if (a.data != b.data) return false;
  if (a.neighbors.size() != b.neighbors.size()) return false;
  typename vector<DAG<T> >::iterator it1, it2;
  it1 = a.neighbors.begin();
  it2 = b.neighbors.begin();
  while(it1!= a.end() && it2!=b.end()) {
    if (!isDAGEqual(*it1, *it2)) return false;
    it1++;
    it2++;
  }
  return true;
}

int main() {
  return 1;
}
