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
 */
void floyd_warshall(graph &g, int **dist) {
    int n = g.VNUM;
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (dist[i][k]<INT_MAX && dist[k][j]<INT_MAX) // THIS IS THE PRBLEM!!!!!!!!!!!!!!!!!
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
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

    int **dist = new int*[n];
    for (int i=0; i<n; i++) {
        dist[i] = new int[n];
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            dist[i][j] = ((i==j)? 0 : INT_MAX);
        }
    }

    for (int i=0; i<n; i++) {
        node *p = g.v[i];
        for (vector<edge>::iterator it=p->edges.begin(); it!=p->edges.end(); ++it) {
            int j = (*it).v;
            int w = (*it).w;
            dist[i][j] = w;
        }
    }

    floyd_warshall(g, dist);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<i<<"-"<<j<<"="<<dist[i][j]<<endl;
        }
    }

    for (int i=0; i<n; ++i) {
        delete [] dist[i];
    }
    delete [] dist;

    return 1;
}
