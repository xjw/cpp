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

void threewayPartition(int a[], int n, int l, int m, int r) {
    int i, j, k;
    i = k = 0;
    j = n-1;
    while(k<=j) {
        if (a[k]<=l) swap(a[k++],a[i++]);
        else if (a[k]>=r) swap(a[k], a[j--]);
        else k++;
    }
}

int main() {
    // int a[] = {3,1,2,3,1,3,3,1,1,2,2,1};
    int a[] = {2,2,1,1,3,3};
    int b[] = {2,2,1,1,2};
    int n1 = sizeof(a)/sizeof(a[0]);
    int n2 = sizeof(b)/sizeof(b[0]);
    threewayPartition(a, n1, 1, 2, 3);
    twowayPartition(b, n2, 1, 2);

    for (int i=0; i<n1; ++i) {
        cout<< a[i];
    }
    cout << endl;
    for (int i=0; i<n2; ++i) {
        cout<< b[i];
    }
    cout << endl;
    return 1;
}
