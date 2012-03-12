#include <iostream>

using namespace std;

/*
 * http://www.leetcode.com/onlinejudge
 *
 * Inspired by this two, but they have incorrect code
 * http://www.leetcode.com/2011/03/median-of-two-sorted-arrays.html#comment-1053
 * http://ideone.com/8VgdW
 *
 * http://www2.myoops.org/course_material/mit/NR/rdonlyres/Electrical-Engineering-and-Computer-Science/6-046JFall-2005/30C68118-E436-4FE3-8C79-6BAFBB07D935/0/ps9sol.pdf
 */
double findMedian(int A[], int B[], int l, int r, int m, int n) {
    if (l>r) return findMedian(B,A,max(0,(m+n)/2-m),min(n,(m+n)/2),n,m);
    int i = max( (m-n)/2, min( (m+n)/2, l + (r-l)/2));
    int j = (m+n)/2 - i - 1;

    int Bj1 = (j>=n-1)? INT_MAX : B[j+1];
    int Bj  = (j==-1) ? INT_MIN : B[j];

    if (A[i]<Bj)  return findMedian(A,B,i+1,r,m,n);
    if (A[i]>Bj1) return findMedian(A,B,l,i-1,m,n);

    if ((m+n)%2 == 1) return (double)A[i];
    if (i>0) return (A[i] + max(A[i-1],Bj))/2.0;
    return (A[i]+Bj)/2.0;
}


int main() {
    //int a[] = {1,2,3,4,5,6};
    //int b[] = {7};
    //int a[] = {1};
    //int b[] = {2};
    //int a[] = {1,2,3};
    //int b[] = {4};
    //int a[] = {3,4};
    //int b[] = {};
    //int a[] = {3,4,5,6,7};
    //int b[] = {1,2};
    //int a[] = {1,4,5,6,7};
    //int b[] = {2,3};
    int a[] = {2,3,5,6,7};
    int b[] = {1,4};
    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);
    cout << findMedian(a, b, 0, m-1, m, n) << endl;
    return 1;
}
    
