#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

bool checkDigits(int a[9]) {
    int x=0;
    for (int i=0; i<9; i++) {
        assert (a[i]>=0 && a[i]<=9);
        x |= (1 << (a[i]-1));
    }
    return x == 0x1ff;
}

bool checkSudoku(int s[9][9]) {
    for (int i=0; i<9; i++)
        if (!checkDigits(s[i])) return false;

    for (int j=0; j<9; j++) {
        int x = 0;
        for (int i=0; i<9; i++)
            x |= (1<< (s[i][j]-1));
        if (x!=0x1ff)
            return false;
    }

    for (int i=0; i<9-3; i+=3) {
        for (int j=0; j<9-3; j+=3) {
            int x = 0;
            for (int m=i; m<i+3; m++) {
                for (int n=j; n<j+3; n++)
                    x |= (1<< (s[m][n]-1));
            }
            if (x!=0x1ff) return false;
        }
    }

    return true;
}


bool checkSudoku2(int s[9][9]) {
    bool c[9];
    memset(c, 0, 9);

    int i, j, k, x;

    for (i=0; i<9; i++) {
        memset(c, 0, 9);
        for (j=0; j<9; j++) {
            assert(s[i][j]>=0 && s[i][j]<=9);
            k = s[i][j]-1;
            if (c[k]) return false;
            c[k] = true;
        }
    }

    for (j=0; j<9; j++) {
        memset(c, 0, 9);
        for (i=0; i<9; i++) {
            assert(s[i][j]>=0 && s[i][j]<=9);
            k = s[i][j]-1;
            if (c[k]) return false;
            c[k] = true;
        }
    }

    for (int m=0; m<9-3; m+=3) {
        for (int n=0; n<9-3; n+=3) {
            memset(c, 0, 9);
            for (i=m; i<m+3; i++) {
                for (j=n; j<n+3; j++) {
                    assert(s[i][j]>=0 && s[i][j]<=9);
                    k = s[i][j]-1;
                    if (c[k]) return false;
                    c[k] = true;
                }
            }
        }
    }

    return true;
}

int main() {
    int s[9][9] = {
        4,1,7,3,6,9,8,2,5,
        6,3,2,1,5,8,9,4,7,
        9,5,8,7,2,4,3,1,6,
        8,2,5,4,3,7,1,6,9,
        7,9,1,5,8,6,4,3,2,
        3,4,6,9,1,2,7,5,8,
        2,8,9,6,4,3,5,7,1,
        5,7,3,2,9,1,6,8,4,
        1,6,4,8,7,5,2,9,3
    };
    cout << checkSudoku(s) << endl;
    cout << checkSudoku2(s) << endl;
    return 1;
}
