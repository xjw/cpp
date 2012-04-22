public class Sudoku {
    private int N = 9;

    private int K = 0x1ff;

    public boolean isValid(int[][] a) {
        int i, j, x, n, ni, nj; 
        ni = a.length;
        nj = a[0].length;
        // check row
        for (i=0; i<ni; i++) {
            x = 0;
            for (j=0; j<nj; j++) {
                n = a[i][j];
                if (n<=0 || n>N || (x & 1<<(n-1))>0) return false;
                x |= 1<<(n-1);
            }
            //if (x != K) return false; not needed
        }


        for (j=0; j<nj; j++) {
            x = 0;
            for (i=0; i<ni; i++) {
                n = a[i][j];
                if (n<=0 || n>N || (x & 1<<(n-1))>0) return false;
                x |= 1<<(n-1);
            }
            //if (x != K) return false; not needed
        }

        for (i=0; i<ni-2; i+=3) {
            for (j=0; j<ni-2; j+=3) {
                x = 0;
                for (int p = i; p < i+3; p++) {
                    for (int q = j; q < j+3; q++) {
                        n = a[p][q];
                        if (n<=0 || n>N || (x & 1<<(n-1))>0) return false;
                        x |= 1<<(n-1);
                    }
                }
                //if (x != K) return false; //not needed
            }
        }

        return true;
    }

    // --------------------------------------------------
    // http://www.leetcode.com/onlinejudge
    // Solve sudoku
    public void solveSudoku(char[][] board) {
        solveSudoku(board, 0, 0);
    }
    
    public boolean solveSudoku(char[][] b, int i, int j) {
        if (i>8) return true;
        int next_i, next_j;
        if (j==8) {
            next_j = 0;
            next_i = i+1;
        } else {
            next_j = j+1;
            next_i = i;
        }
        if (b[i][j] != '.') return solveSudoku(b, next_i, next_j);
        
        for (int x = 1; x<=9; x++) {
            b[i][j] = Character.forDigit(x,10);
            if (isValid(b, i, j)) {
                if (solveSudoku(b, next_i, next_j)) 
                    return true;
            }
        }
        b[i][j] = '.';
        return false;
    }

    public boolean isValid(char[][] b, int x, int y) {
        for (int i=0; i<9; i++) {
            if ((i != y && b[x][i] == b[x][y]) || 
                (i != x && b[i][y] == b[x][y]))
                return false;
        }
        int m = 3*(x/3);
        int n = 3*(y/3);
        for (int i=m; i<m+3; i++) {
            for (int j=n; j<n+3; j++) {
                if (b[i][j] == b[x][y] && !(i==x && j==y)) 
                return false;
            }
        }
        return true;
    }

    public void test() {
        int[][] s = {
            {4,1,7,3,6,9,8,2,5},
            {6,3,2,1,5,8,9,4,7},
            {9,5,8,7,2,4,3,1,6},
            {8,2,5,4,3,7,1,6,9},
            {7,9,1,5,8,6,4,3,2},
            {3,4,6,9,1,2,7,5,8},
            {2,8,9,6,4,3,5,7,1},
            {5,7,3,2,9,1,6,8,4},
            {1,6,4,8,7,5,2,9,3}
        };
        System.out.println(isValid(s));

    }

    public static void main(String[] args) {
        new Sudoku().test();
    }

}
