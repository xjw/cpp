/**
 * http://stackoverflow.com/questions/5000512/find-the-top-k-sums-of-two-sorted-arrays 
 */

#include <iostream>
#include <queue>
#include <assert.h>

using namespace std;

struct element {
    int i;
    int j;
    int val;
    element(int a, int b, int v) : i(a), j(b), val(v) {}
    bool operator < (const element& rhs) const {
        return val < rhs.val;
    }
};

int get_kth_sum_of_two_array(int a[], int m, int b[], int n, int k) {
    assert(k>0 && k<=m+n);

    priority_queue<element> pq;
    int i, j, val;
    i = j = 0;
    val = a[i]+b[j];
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

        if (i<m-1) pq.push(element(i+1,j,a[i+1]+b[j]));
        if (j<n-1) pq.push(element(i,j+1,a[i]+b[j+1]));
    }
}


int get_kth_from_young_tableaux(int **a, int m, int n, int k) {
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
    int a[] = {10,8,2,1};
    int b[] = {7,6,5,4,3};
    // sum order 17,16,15,15,14,14,14,13,13
    int k = 5;
    // cin >> k;
    get_kth_sum_of_two_array(a, sizeof(a)/sizeof(a[0]), 
                             b, sizeof(b)/sizeof(b[0]),
                             k);
    return 1;
}
