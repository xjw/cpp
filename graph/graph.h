#ifndef _XJ_GRAPH_
#define _XJ_GRAPH_

#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class edge {
 public:
  int v;
  int w;
  edge(int vertice, int weight) : v(vertice), w(weight) {}
};

class node {
 public:
  int v;
  vector<edge> edges;
  void addEdge(int v, int weight);
  node(int vertice) : v(vertice) {}
};

void node::addEdge(int v, int weight) {
    edges.push_back(edge(v, weight));
}

class graph {
 public:
  vector<node *> v;
  int VNUM;
  graph(int n);
  ~graph();
  void addEdge(int s, int d, int weight);
  void BFS();
  void DFS();
  void DFS_recursive(int s);
};

graph::graph(int n) {
    VNUM = n;
    v.assign(n, (node *)NULL);

    // equivalent
    /*
       v.reserve(n);
       for (int i=0; i<n; ++i) v[i]=NULL;
       */
}

graph::~graph() {
    for(vector<node *>::iterator it = v.begin(); it != v.end(); ++it) {
        delete *it;
    }
}

void graph::addEdge(int s, int d, int weight) {
    if (v[s]==NULL) {
        v[s] = new node(s);
    }
    if (v[d]==NULL) {
        v[d] = new node(d);
    }
    v[s]->addEdge(d, weight);
    v[d]->addEdge(s, weight);
}

void graph::BFS() {
    bool *visited = new bool[VNUM];
    for (int i=0; i<VNUM; ++i) {
        visited[i] = false;
    }

    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        cout << front << endl;
        for (vector<edge>::iterator it=v[front]->edges.begin(); it != v[front]->edges.end(); ++it) {
            int idx = (*it).v;
            if (!visited[idx]) {
                q.push(idx);
                visited[idx] = true;
            }
        }
    }

    delete[] visited;
}

void graph::DFS() {
    stack<int> st;
    bool *visited = new bool[VNUM];
    for (int i=0; i<VNUM; ++i) visited[i] = false;

    st.push(0);

    while(!st.empty()) {
        int top = st.top();
        st.pop();

        if (!visited[top]) {
            cout << top << endl;
            visited[top] = true;
            for (vector<edge>::iterator it = v[top]->edges.begin(); 
                 it!= v[top]->edges.end(); ++it) {
                int idx = (*it).v;
                if (!visited[idx]) st.push(idx);
            }
        }
    }
}

void graph::DFS_recursive(int s) {
    static bool visited[100];
    // static bool *visited = new bool[VNUM]; //this is WRONG!!!!!!!!!!!!!!!
    cout<<s<<endl;
    visited[s] = true;
    for (vector<edge>::iterator it = v[s]->edges.begin(); 
         it != v[s]->edges.end(); ++it) {
        int idx = (*it).v;
        if (!visited[idx]) DFS_recursive(idx);
    }
}

#endif
