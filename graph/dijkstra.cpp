/*
Dijkstra's Algorithm:

	s.dist = 0
	for (;;)
	    v = smallest unknown distance vertex
	    if (v == not_a_vertex) break;
	    v.known = true;

	    for each w adjacent to v
		if ( ! w.known )
		  if ( v.dist + c(v,w) < w.dist)
		      { decrease (w.dist to  v.dist + c(v,w) 
			w.path = v;
		      }
	}


Running time.
	Depends on data structures. Naive method is O(V^2 + E).
	Scan vertex list to find min each time, for total of V^2; 
	Weight updates happen once per edge, so O(E).

	Can be improved to O((V+E) log V) by organizing the distances
	in a heap. 
	Selection of v is a deleteMin operation--- V of them;
	The update is a decreaseKey operation--- E of them
*/
#include <iostream>
#include "graph.h"
#include "limits.h"

using namespace std;

void printPath(int *parent, int i, int src, int n) {
    if (i == src) {
        cout << i << endl;
        return;
    }
    printPath(parent, parent[i], src, n);
    cout<<i<<endl;
}

/**
 * pass graph g by reference OR define copy constructor
 * otherwise TWICE DESTRUCTOR ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *
 * becoz if pass by value, g get copied, but not deep copy
 * when g_copy goes out of scope, destructor called, pointer within object
 * destroyed, after function return, destructor called again, DISASTER!!!
 */

int dijkstra(int src, int dst, int n, graph &g) {
    int *dist = new int[n];
    int *parent = new int[n];
    int *visited = new int[n];
    int i = 0;
    int s = src;
    while(i<n) {
        dist[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
        i++;
    }

    dist[s] = 0;

    while(!visited[s]) {
        if (s == dst) break;
        visited[s] = true;
        node *p = g.v[s];
        for (vector<edge>::iterator it = p->edges.begin();
             it != p->edges.end(); ++it) {
            int v = (*it).v;
            if (visited[v]) continue; // better have this to save time, not in the algorithm design manual example
            int alt = dist[s]+(*it).w;
            if (dist[v]>alt) {
                dist[v] = alt;
                parent[v] = s;
            }
        }

        for (int min_d=INT_MAX, i=0; i<n; ++i) {
            if (!visited[i] && dist[i]<min_d) {
                s = i;
                min_d = dist[i];
            }
        }
    }

    printPath(parent, dst, src, n);

    int shortest  = dist[dst];
    delete [] dist;
    delete [] parent;
    delete [] visited;

    return shortest;
}

int main() {
    int n = 6;
    graph g(n);
    g.addEdge(1, 2, 10);
    g.addEdge(0, 1, 5);
    g.addEdge(1, 3, 30);
    g.addEdge(0, 4, 4);
    g.addEdge(4, 5, 8);
    g.addEdge(4, 3, 3);

    // g.DFS();
    cout<< "shortest length is:" << dijkstra(2, 4, n, g) << endl;
    return 1;
}
