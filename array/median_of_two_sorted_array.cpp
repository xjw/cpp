#include <iostream>

using namespace std;

/*
 * http://www.leetcode.com/onlinejudge
 *
 * Inspired by mit material, but they failed to handle edge cases
 * http://www.leetcode.com/2011/03/median-of-two-sorted-arrays.html#comment-1053
 * http://ideone.com/8VgdW
 * http://www2.myoops.org/course_material/mit/NR/rdonlyres/Electrical-Engineering-and-Computer-Science/6-046JFall-2005/30C68118-E436-4FE3-8C79-6BAFBB07D935/0/ps9sol.pdf
 *
 * The idea is to choose i from A[], j from B[] to satisfy
 * 1. i+j = (size_A + size_B)/2 - 1
 * 2. B[j]<A[i]<B[j+1]
 * So that A[i] will be the median because it's bigger than i elements in A and j+1 elements in B(including B[j])
 * i+j+1 = (size_A+size_B)/2, so A[i] is bigger than half of the two arrays
 *
 * Edge cases need careful handling
 * Suppose size_A = m, size_B = n
 * i should be in [0, m);
 * j in [-1,n) !!!!!!!!!! (Why? because the use of B[j+1])
 *  1. j = (m+n)/2-i-1
 *  2. i>=0  && i<m
 *  3. j>=-1 && j<n (=> i needs to be satisfy [(m-n)/2, (m+n)/2]
 *
 */
double findMedian(int A[], int B[], int l, int r, int m, int n) {
    // if l>r, it means median is not in A, search in B instead
    if (l>r) return findMedian(B,A,max(0,(m+n)/2-m),min(n,(m+n)/2),n,m);
    // binary search i; but also i needs to be in [(m-n)/2, (m+n)/2], reason see above comments
    int i = max( (m-n)/2, min( (m+n)/2, l + (r-l)/2));
    // because of the range of i, j will be in [-1,n)
    int j = (m+n)/2 - i - 1; 

    // set edge case for Bj and Bj+1
    int Bj1 = (j>=n-1)? INT_MAX : B[j+1];
    int Bj  = (j==-1) ? INT_MIN : B[j];

    if (A[i]<Bj)  return findMedian(A,B,i+1,r,m,n); //i is too small
    if (A[i]>Bj1) return findMedian(A,B,l,i-1,m,n); //i is too big

    // when size_A+size_B is odd, A[i] is median
    if ((m+n)%2 == 1) return (double)A[i];
    // when size_A+size_B is even, the other median is
    // either A[i-1] and B[j]
    int the_other_median = i>0? max(A[i-1],Bj) : Bj;
    return (A[i]+the_other_median)/2.0;
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
    
