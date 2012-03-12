#include <iostream>
#include <assert.h>
#include <math.h>
using namespace std;

/*
 * http://www.leetcode.com/2011/01/find-k-th-smallest-element-in-union-of.html
 */
bool find_kth_of_two_sorted_array(int a[], int m, int b[], int n, int k) {
    assert(m>=0 && n>=0 && k>0 && (m+n>=k));
    m = min(m, k);
    n = min(n, k);
    int i = min(m,k/2);
    int j = (k-1)-i;
    if (j>n) {
        j = n;
        i = k-n-1;
    }
    int Ai_1 = (i==0) ? INT_MIN : a[i-1];
    int Bj_1 = (j==0) ? INT_MIN : b[j-1];
    int Ai = (i==m)? INT_MAX : a[i];
    int Bj = (j==n)? INT_MAX : b[j];
    
    if (Ai >= Bj_1 && Ai <= Bj) {
        printf("A[%d]\n", i);
        return true;
    }
    else if (Bj >= Ai_1 && Bj <= Ai) {
        printf("B[%d]\n", j);
        return true;
    }

    if (a[i]<b[j]) {
        // exclude A_i and below positions (i+1)
        // also exclude B_j and above positions
        return find_kth_of_two_sorted_array(a+i+1, m-i-1, b, j-1, k-(i+1));
    } else {
        // exclude A_i and above positions
        // also exclude B_j and below positions (j+1) 
        return find_kth_of_two_sorted_array(a, i, b+j+1, n-j-1, k-(j+1));
    }
}

int main() {
    //int a[] = {2,3,4};
    //int b[] = {1,2,6,7,8};
    //int b[] = {2,3,4};
    //int a[] = {1,2,6,7,8};
    int a[] = {6,7,8};
    int b[] = {1,2,3};
    int k;
    while (cin >> k && k != 'z') {
        if (!find_kth_of_two_sorted_array(a,sizeof(a)/sizeof(int),b,sizeof(b)/sizeof(int),k)) {
            cout << "could not find it" << endl;
        }
    }
    return 1;
}
