public class SetMatrixZero {
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
