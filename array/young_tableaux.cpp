/**
 *  
 *  Paper about O(n) algorithm - Generalized Selection and Ranking: Sorted Matrices
 *
 *  http://zhiqiang.org/blog/science/computer-science/median-algorithm-of-ordered-matrix.html
 *  http://stackoverflow.com/questions/4065158/completely-sorted-matrix
 *
 *  priority queue implementation
 *  http://stackoverflow.com/questions/5000512/find-the-top-k-sums-of-two-sorted-arrays
 */

#include <iostream>
#include <queue>
#include <assert.h>

using namespace std;

const int M=3;
const int N=3;

int find_median(int a[M][N]) {
    int n = M*N;
    int m = n/2;
    int i, j;
}

int selection_find_medium(int a[M][N], int i0, int j0, int i2, int j2, int k) {
    int n = (i2-i0+1)*(j2-j0+1);
    int i1 = i0 + (i2-i0)/2;
    int j1 = j0 + (j2-j0)/2;
    int x = a[i1][j1];
}


// solution for find kth in young
struct element {
    int i;
    int j;
    int val;
    element(int a, int b, int v) : i(a), j(b), val(v) {}
    bool operator < (const element& rhs) const {
        return val < rhs.val;
    }
};


int get_kth_from_young_tableaux(int a[M][N], int m, int n, int k) {
    assert(k>0 && k<=m*n);

    priority_queue<element> pq;
    int i, j, val;
    i = j = 0;
    val = a[i][j];
    pq.push(element(i,j,val));
    while(k) {
        k--;
        element top = pq.top();
        pq.pop();
        i = top.i;
        j = top.j;
        if (k==0) {
            cout << i << "-" << j << "-" <<top.val<<endl;
            return top.val;
        }

        if (i<m-1) pq.push(element(i+1,j,a[i+1][j]));
        if (j<n-1) pq.push(element(i,j+1,a[i][j+1]));
    }
}

int main() {
    int y[M][N] = {
        13,10,3,
        11,9,2,
        7,5,1
    };
    cout << find_median(y) << endl;
    // cout << selection_find_medium(y, 0, 0, n-1, n-1, M*N/2) << endl;
    cout << get_kth_from_young_tableaux(y, M, N, 4) << endl;
    return 1;
}
