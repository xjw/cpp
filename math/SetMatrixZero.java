public class SetMatrixZero {
    /*
     * Approach 1: with m+n space
     */
    static void setMatrixZero(int[][] x) {
        int m, n;
        m = x.length;
        n = x[0].length;
        int[] row = new int[m];
        int[] column = new int[n];
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (x[i][j] == 0) {
                    row[i] = 1;
                    column[j] = 1;
                }
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (row[i] == 1 || column[j] == 1) {
                    x[i][j] = 0;
                }
                System.out.print(x[i][j] + " ");
            }
            System.out.println();
        }
    }

    /*
     * Approach 2:  O(1) space
     * http://dl.dropbox.com/u/19732851/LeetCode/SetMatrixZeroes.html
     */
    static void SetMatrixZeroInPlace(int[][] x) {
        int i, j;
        boolean firstRowZero, firstColumnZero;
        firstRowZero = firstColumnZero = 0;
        for (i=0; i<x[0].length; i++) {
            if (x[0][i] == 0) {
                firstRowZero = true;
                break;
            }
        }
        for (i=0; i<x.length; i++) {
            if (x[i][0] == 0) {
                firstColumnZero = true;
                break;
            }
        }
        for (int i=1; i<x.length; i++) {
            for (int j=1; j<x[i].length; j++) {
                if (x[i][j] == 0) {
                    x[0][j] = 0;
                    x[i][0] = 0;
                }
            }
        }
        for (int i=1; i<x.length; i++) {
            for (int j=1; j<x[i].length; j++) {
                if (x[i][0] == 0 || x[0][j] == 0) x[i][j]=0;
            }
        }
        if (firstRowZero) {
            for (int i=0; i<x[0].length; i++) x[0][i] = 0;
        }
        if (firstColumnZero) {
            for (int j=0; j<x.length; j++) x[j][0] = 0;
        }
    }

    public static void main(String[] args) {
        int m[][] = new int[][]{
            {1,2,3,4,0},
            {5,6,7,8,5},
            {9,0,1,2,0},
            {3,4,5,6,0},
            {3,4,5,6,7},
            {3,4,5,6,0}
        };
        setMatrixZero(m);
    }
}
