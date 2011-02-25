#include <iostream>
#include "graph.h"

using namespace std;

int main() {
  graph g(6);
  g.addEdge(1, 2, 10);
  g.addEdge(0, 1, 5);
  g.addEdge(1, 3, 3);
  g.addEdge(0, 4, 4);
  g.addEdge(4, 5, 8);
  g.BFS();
  cout<<endl;
  g.DFS();
  cout<<endl;
  g.DFS_recursive(0);
  return 1;
}
