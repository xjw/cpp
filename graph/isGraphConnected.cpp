#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

/**
 *  At first, imagine we have an undirected graph. 
 *  The simplest way to store a graph in STL is to use the lists of vertices adjacent to each vertex. 
 *  This leads to the vector< vector<int> > M structure, where M[i] is a list of vertices adjacent to i. 
 *  Let’s verify our graph is connected via DFS:
 */

vector<bool> flag;
vector<vector <int> > graph;

const int N=15;

void DFS(int i) {
  if (!flag[i]) {
    flag[i] = true;
    for_each(graph[i].begin(), graph[i].end(), DFS);
  }
}

bool DFSIsGraphConnected() {
  flag = vector<bool>(N, false); 
  DFS(0);
  return (find(flag.begin(), flag.end(), false)==flag.end());
}

void BFS(int i) {
  queue<int> q;
  q.push(i);
  flag[i] = true;
  while(!q.empty()) {
    int i = q.front();
    q.pop();
    for (vector<int>::iterator it = graph[i].begin(); it!=graph[i].end(); ++it) {
      if (!flag[*it]) {
        flag[*it] = true;
        q.push(*it);
      }
    }
  }
}

bool BFSIsGraphConnected() {
  flag = vector<bool>(N, false);
  BFS(0);
  return (find(flag.begin(), flag.end(), false)==flag.end());
}

int main() {
  DFSIsGraphConnected();
  BFSIsGraphConnected();
  return 1;
}
