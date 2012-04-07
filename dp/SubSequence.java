import java.util.*;

public class SubSequence {
    /*
     * DP Approach O(n^2)
     */
    public int getLongestIncreasingSubSequence(int[] a) {
        int max;
        int[] c = new int[a.length];
        max = c[0] = 1;
        for (int i=1; i<a.length; i++) {
            c[i] = 1;
            for (int j=0; j<i; j++) {
                if (a[i]>a[j]) { //a[i]>=a[j] for nondecreasing
                    c[i] = Math.max(c[i], c[j]+1);
                }
            }
            max = Math.max(max, c[i]);
        }
        return max;
    }

    /*
     * Its uncessary to compare with all previous elements before current
     * just need to compare with the last element of previous sequence
     * and we can store the index of (smallest of last element)
     * those last element will be in sorted order !!!!
     *
     * http://www.algorithmist.com/index.php/Longest_Increasing_Subsequence.cpp
     */
    public int getLongestIncreasingSubSequenceUsingBinarySearch(int[] a) {
        if (a.length ==0) return 0;
        List<Integer> list = new ArrayList<Integer>();
        int[] c = new int[a.length];
        int[] p = new int[a.length];
        c[0] = 1; // cache, not needed if p is used
        p[0] = -1; // to store previous index
        list.add(0);
        for (int i=1; i<a.length; i++) {
            if (a[i]>a[list.get(list.size()-1)]) { //>= for nondecreasing
                c[i] = c[list.get(list.size()-1)]+1;
                p[i] = list.get(list.size()-1);
                list.add(i);
            } else {
                // binary search index
                // find the largest index whose value < current
                // list.get(idx) < a[i]
                int l = 0;
                int r = list.size()-1;
                while(r>l) {
                    int m = l + (r-l)/2;
                    if (a[i]>=a[list.get(m)]) l=m+1;
                    else r=m;
                }
                if (a[i]<a[list.get(l)]) {
                    c[i] = c[list.get(l)];
                    list.set(l, i);
                    p[i] = (l>0)? list.get(l-1) : -1;
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i=list.get(list.size()-1); i>=0; i=p[i]) {
            sb.append(" " + a[i]);
        }
        System.out.println(sb.reverse().toString());
        return c[list.get(list.size()-1)];
    }


    /*
     * DP - overlapping subproblem + memorization
     * this needs additional O(mn) space
     */
    public int getLongestCommonSubSequence(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();
        int[][] c = new int[m+1][n+1];
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (s1.charAt(i-1) == s2.charAt(j-1)) {
                    c[i][j] = c[i-1][j-1]+1;
                } else {
                    c[i][j] = Math.max(c[i-1][j], c[i][j-1]);
                }
            }
        }
        System.out.println("common subsequence: " + backtracking(c, s1, s2, m, n));
        return c[m][n];
    }

    /*
     * backtracking printing
     */
    public String backtracking(int[][] c, String s1, String s2, int i, int j) {
        if (i ==0 || j == 0)
            return "";
        if (s1.charAt(i-1) == s2.charAt(j-1)) 
            return backtracking(c, s1, s2, i-1,j-1) + s1.charAt(i-1);
        if (c[i-1][j] > c[i][j-1])
            return backtracking(c, s1, s2, i-1, j);
        return backtracking(c, s1, s2, i, j-1);
    }

    /*
     * if only length is needed
     * actually only 2*O(n) space is enough
     * current row and previous row
     *
     */
    public int getLongestIncreasingSubSequenceLessSpace(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();
        int[] curr = new int[n+1];
        int[] prev = new int[n+1];
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (s1.charAt(i-1) == s2.charAt(j-1)) {
                    curr[j] = prev[j-1]+1;
                } else {
                    curr[j] = Math.max(curr[j-1], prev[j]);
                }
            }
            int[] t = prev;
            prev = curr;
            curr = prev;
        }
        return curr[n];
    }

    public void testLongestIncreasingSubSequence() {
        int[][] a = {
            {3,4,6,8,9,12},
            {2,4,3,5,1,7,6,9,8},
            {1,3,5,2,6,4,7,8,9,5,6},
            {1,5,4,6,7,8,2,6,9,7},
            {1,9,3,8,11,4,5,6,4,19,7,1,7}
        };
        System.out.println("--testing increasing subsequence--");
        for (int i=0; i<a.length; i++) {
            System.out.println(getLongestIncreasingSubSequence(a[i]) 
                + "=" + getLongestIncreasingSubSequenceUsingBinarySearch(a[i]));
        }
    }

    public void testLongestCommonSubSequence() {
        String[][] s = {
            {"a","a"},
            {"acbe", "cfdbfe"},
            {"BANANA", "ATANA"}
        };
        System.out.println("--testing common subsequence--");
        for (int i=0; i<s.length; i++) {
            System.out.println(getLongestCommonSubSequence(s[i][0], s[i][1]) 
                    + "=" + getLongestIncreasingSubSequenceLessSpace(s[i][0], s[i][1]));
        }
    }

    public static void main(String[] args) {
        SubSequence s = new SubSequence();
        s.testLongestIncreasingSubSequence();
        s.testLongestCommonSubSequence();
    }

}
