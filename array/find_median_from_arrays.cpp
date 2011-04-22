/**
 * http://geeksforgeeks.org/?p=2105 
 */

#include <iostream>

using namespace std;

/**
 * O(n) merge method 
 */
int find_median_merge(int a[], int m, int b[], int n) {
    int m1, m2, i, j, count, median_loc;
    i = j = count =  0;
    median_loc = (m + n)/2;
    int *a1 = a;
    int *a2 = b;
    while(count<=median_loc) {
        if (i==m) {
            a1 = b;
            i = 0;
        } 
        if (j==n) {
            a2 = a;
            j = 0;
        }
        if (a1[i]<a2[j]) {
            i++;
            m1 = m2;
            m2 = a1[i];
        }
        else {
            j++;
            m1 = m2;
            m2 = a2[j];
        }
        count++;
    }
    return (m1+m2)/2;
}

int main() {
    int a[] = {1, 12, 15, 26, 38};
    int b[] = {2, 13, 17, 30, 45};
    int m = sizoef(a) / sizeof(a[0]);
    int m = sizoef(b) / sizeof(b[0]);
    cout << find_median_merge(a, b) << endl;
    return 1;
}
