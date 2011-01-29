#include <iostream>

using namespace std;

void inplaceMergeTwoArray(int a[], int b[], int la, int lb) {
    int i, j, k;
    for (k=la+lb-1, i=la-1, j=lb-1; i>=0 && j>=0; --k) {
        if (a[i]>b[j])
            a[k]=a[i--];
        else
            a[k]=b[j--];
    }
    while(i>=0) a[k--]=a[i--];
    while(j>=0) a[k--]=b[j--];
}

int main() {
    int a[50] = {1, 3, 5};
    int b[] = {2, 4, 6, 7};
    int la, lb;
    la = 3; 
    lb = 4;
    inplaceMergeTwoArray(a, b, la, lb);
    for (int i=0; i<la+lb; ++i) {
        cout<<a[i]<<endl;
    }
    return 1;
}
