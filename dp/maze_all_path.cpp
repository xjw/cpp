#include <iostream>
using namespace std;

#define N 2

void find_all_path(int x, int y, int m[N][N]) {
    if (x<0 || y < 0) return;
    if (x==0 && y==0) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
        cout << "----" << endl;
        return;
    }
    if (x>0) {
        m[x][y] = 0;
        find_all_path(x-1, y, m);
    }
    if (y>0) {
        m[x][y] = 1;
        find_all_path(x, y-1, m);
    }
}

int main() {
    int m[N][N] = {
        2,2,
        2,2
    };
    find_all_path(N,N,m);
    return 1;
}

