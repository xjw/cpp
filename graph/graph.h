#ifndef _XJ_GRAPH_
#define _XJ_GRAPH_

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class edgeNode {
 public:
  int idx;
  T dist;
  edgeNode(int, T);
};

template <typename T>
edgeNode<T>::edgeNode(int i, T d) {
  idx = i;
  dist = d;
}

template <typename T>
class graph {
 public:
  vector< vector<edgeNode<T> > > v;
  graph(int n);
  void addNode(int, int, T);
};

template <typename T>
graph<T>::graph(int n) {
  v.insert(v.begin(),NULL,n);
}

template <typename T>
void graph<T>::addNode(int start, int end, T d) {
  cout << v.size() << endl;
  // v.at(start).push_back(edgeNode<T>(end, d));
}

#endif
