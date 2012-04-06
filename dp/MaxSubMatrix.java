import java.util.*;

public class MaxSubMatrix {

    /*
     * Problem 1: find max sum out of matrix
     * http://www.algorithmist.com/index.php/UVa_108
     * 
     */
    public int maxSum(int[][] a) {
        int i, j, m, n;
        m = a.length;
        if (m==0) return 0;
        n = a[0].length;
        // first compute the vertical prefix sum for later calculation
        // O(m*n)
        int[][] s = new int[m+1][n]; // allocate m+1 to make edge case simpler
        for (j=0; j<n; j++) {
            for (i=0; i<m; i++) {
                s[i+1][j] = s[i][j] + a[i][j]; 
            }
        }

        // use kadane's algorithm to find max sub sum
        // O(n*m^2)
        int sum_max, sum_so_far, sum_of_current_column;
        sum_max = sum_so_far = Integer.MIN_VALUE;
        for (int i1=0; i1<m; i1++) {
            for (int i2=i1; i2<m; i2++) {
                sum_so_far = Integer.MIN_VALUE;
                for (j=0; j<n; j++) {
                    sum_of_current_column = s[i2+1][j]-s[i1][j];
                    sum_so_far = (sum_so_far<0)? sum_of_current_column
                        : sum_so_far + sum_of_current_column;
                    sum_max = Math.max(sum_max, sum_so_far);
                }
            }
        }

        return sum_max;
    }

    /*
     * Key observation: 
     假设输入二位矩阵为M,构造辅助矩阵S 
     If M[i][j] is 1 then 
     S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1 
     Else If M[i][j] is 0*
     S[i][j] = 0 
     * Complexity: O(MN) 
     *
     */
    public int maxSubSqaureWithAllOne(int[][] a) {
        int i,j,m,n,max;
        m = a.length;
        if (m==0) return 0;
        n = a[0].length;
        max = Integer.MIN_VALUE;
        int[][] s = new int[m][n];
        for (i=0; i<m; i++) s[i][0] = a[i][0];
        for (j=0; j<n; j++) s[0][j] = a[0][j];
        for (i=1; i<m; i++) {
            for (j=1; j<n; j++) {
                s[i][j] = (a[i][j] == 0)? 0 
                    : 1+Math.min(s[i-1][j-1], Math.min(s[i-1][j], s[i][j-1]));
                max = Math.max(s[i][j],max);
            }
        }
        return max;
    }


    /*
     * Key observation:通过一个O(MN)的预处理
     * It translates to the problem of 
     * largest rectangle in histogram
     * O(m*n)
     * http://drdobbs.com/database/184410529
     *
     * 从最后一行开始向上，某个列上的连续的 1 可以看做一个直方柱，直到碰到 0 或矩阵边界。
     * 而最大的1-聚类正是该“直方图”上的最大长方形。因此，
     * 我们可以用 OPT(i) 来表示终止于行 i 的最大的 1-聚类。这样，一共有 O(m)个子问题
     * 而每个子问题可以上面的方法解，时间复杂度为 O(n)，因此总的时间复杂度为 O(mn)！
     * 不过，前提时，对每个子问题，我们可以只用 O(n) 的时间转换成一个“直方图”。事实上，
     * 除了最后一行开始，我们可以利用 OPT(i) 的直方图来构造 OPT(i-1)
     * 的直方图，并且在整个过程中，每个元素只需要被计算一次即可。
     *
     */

    /*
     * DP Caching Helper
     */
    public void setCache(int[][] a, int[] c, int column) {
        for (int i=0; i<c.length; i++) {
            c[i] = (a[i][column]>0)? 1 + c[i] : 0;
        }
    }

    /*
     * solution 1: use cache and scan O(m^2 * n)
     * this cache is vertical(column) direction, 
     * and only 1 dimension is needed, think why?
     */
    public int maxRectangleWithAllOneUsingCache(int[][] a) {
        int ni = a.length;
        if (ni ==0) return 0;
        int nj = a[0].length;
        int i1, i2, j, width, max;
        max = 0;
        int[] c = new int[ni];
        for (j=nj-1; j>=0; j--) {
            setCache(a, c, j);  // update cache for each column, from right to left!!!
            for (i1=0; i1<ni; i1++) {
                for (i2=i1, width=c[i2]; i2<ni && (a[i2][j]>0); i2++) {
                    width = Math.min(width, c[i2]);
                    max = Math.max(max, (i2-i1+1)*width);
                }
            }
        }
        return max;
    }


    // solution 2: use stack open/close O(m*n);
    public int maxRectangleWithAllOneUsingHistogramIdea(int[][] a) {
        int ni = a.length;
        if (ni ==0) return 0;
        int nj = a[0].length;
        int i,j;
        int[] cache = new int[ni];
        int max = 0;
        for (j = nj-1; j>=0; j--) {
            setCache(a, cache, j);
            int local_max = getMaxFromHistogram(cache);
            max = Math.max(max, local_max);
        }
        return max;
    }

    // helper function - same with Histogram.java
    public int getMaxFromHistogram(int hist[]) {
        int[] h = Arrays.copyOf(hist, hist.length+1);
        int len = h.length;
        int[] stack = new int[len];
        int[] left = new int[len];
        h[len-1] = -1; // to make sure pop out stack at end
        int top = -1; // top stack pointer
        int max = 0;
        for (int i=0; i<len; i++) {
            while(top != -1 && h[i] < h[stack[top]]) {
                max = Math.max(max,
                        h[stack[top]] * (i-stack[top]+left[top]));
                top--;
            }
            int left_width = (top == -1)? i : i-stack[top]-1;
            stack[++top] = i;
            left[top] = left_width;
        }
        return max;
    }




    // --------testing---------------

    public void testmaxRectangleWithAllOne() {
        int[][] a = {
            {0, 1, 1, 0, 1},
            {1, 1, 1, 1, 0},
            {0, 1, 1, 1, 0},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0}
        };
        System.out.println("testing max rectangle with all ones");
        System.out.println(maxRectangleWithAllOneUsingCache(a));
        System.out.println(maxRectangleWithAllOneUsingHistogramIdea(a));
    }

    public void testMaxSum() {
        int a[][] = {
            {-1,-2,-3,-4},
            {-5,-6,-7,-8},
            {-9,-10,-11,-12},
            {-13,-14,-15,-16}
        };

        int c[][] = {
            {0,-2,-7,0},
            {9,2,-6,2},
            {-4,1,-4,1},
            {-1,8,0,2}
        };
        System.out.println(maxSum(a));
        System.out.println(maxSum(c));
        assert -1 == maxSum(a);
        assert 15 == maxSum(c);
    }

    public static void main(String[] args) {
        MaxSubMatrix m = new MaxSubMatrix();
        int[][] a = {};
        m.testMaxSum();
        m.testmaxRectangleWithAllOne();
    }
}
