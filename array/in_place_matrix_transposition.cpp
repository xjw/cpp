/**
 * http://en.wikipedia.org/wiki/In-place_matrix_transposition 
 * http://cheshirekow.com/blog/?p=4
 */

#include <iostream>
using namespace std;

const int N=4;

void in_place_matrix_transposition(int a[N][N]) {
    for (int i=0; i<N-1; ++i) {
        for (int j=i+1; j<N; ++j) {
            swap(a[i][j], a[j][i]);
        }
    }
}

int main() {
    int a[N][N] = {
        1,2,3,4,
        5,6,7,8,
        9,10,11,12,
        13,14,15,16,
    };
    in_place_matrix_transposition(a);
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cout << a[i][j] << " ";
        }
        cout<<endl;
    }
    return 1;
}
