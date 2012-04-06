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
