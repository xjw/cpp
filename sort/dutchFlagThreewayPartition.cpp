#include <iostream>


using namespace std;

void twowayPartition(int a[], int n, int l, int r) {
    int i, j;
    i = 0;
    j = n-1;
    while(i<=j) {
        if (a[i] == l) i++;
        else swap(a[i], a[j--]);
    }
}

void threeWayPartition(int a[], int n, int l, int m, int r) {
    int i, j, k;
    i = k = 0;
    j = n-1;
    while(k<=j) {
        if (a[k]<=l) swap(a[k++],a[i++]);
        else if (a[k]>=r) swap(a[k], a[j--]);
        else k++;
    }
}

void threeWayPartition(int a[], int n, int m) {
    int i, j, k;
    i = k = 0; 
    j = n-1;
    while(k<j) {
        if (a[k]<m) swap(a[i++], a[k++]);
        else if (a[k]>m) swap(a[k], a[j--]);
        else k++;
    }
}

int main() {
    // int a[] = {3,1,2,3,1,3,3,1,1,2,2,1};
    int a[] = {2,2,1,1,3,3};
    int b[] = {2,2,1,1,2};
    int c[] = {5,5,1,6,7,5,3,8,2,5};
    int d[] = {4,9,4,4,1,4,4,4,9,4,4,1,4};
    int n1 = sizeof(a)/sizeof(a[0]);
    int n2 = sizeof(b)/sizeof(b[0]);
    int n3 = sizeof(c)/sizeof(c[0]);
    int n4 = sizeof(d)/sizeof(d[0]);
    threeWayPartition(a, n1, 1, 2, 3);
    twowayPartition(b, n2, 1, 2);
    threeWayPartition(c, n3, 5);
    threeWayPartition(d, n4, 4);

    for (int i=0; i<n1; ++i) {
        cout<< a[i];
    }
    cout << endl;
    for (int i=0; i<n2; ++i) {
        cout<< b[i];
    }
    cout << endl;
    for (int i=0; i<n3; ++i) {
        cout<< c[i];
    }
    cout << endl;
    for (int i=0; i<n4; ++i) {
        cout<< d[i];
    }
    cout << endl;
    return 1;
}
