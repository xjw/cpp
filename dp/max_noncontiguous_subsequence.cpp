#include <iostream>

using namespace std;

/*
 * Given an array all of whose elements are positive numbers
 * find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence 
 * should be adjacent in the array. For example,
 * i) 3 2 7 10 should return 13 (sum of 3 and 10) 
 * ii) 3 2 5 10 7 should return 15 (sum of 3, 5 and 7)
 * 
 * http://nthrgeek.wordpress.com/2009/10/09/maximum-non-contiguous-subsequence/
 */

int max_noncontiguous_subsequence(int a[], int n) {
    int incl = 0;
    int excl = 0;
    int excl_new = 0;
    for (int i=0; i<n; i++) {
        excl_new = max(incl, excl); // if a[i] coud be neg, need max(incl, exel, 0)
        incl = excl + a[i];
        exel = exel_new;
    }
    return max(excl, incl);
}

int main() {
    //int a[] = {1,3,1,3,100};
    int a[] = {200,1,1,100,1,1};
    cout << max_noncontiguous_subsequence(a,sizeof(a)/sizeof(int)) << endl;
    return 1;
}
