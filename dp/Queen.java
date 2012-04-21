import java.util.*;
/*
 * http://www.leetcode.com/onlinejudge
 * Problem1. Return all possiblities
 * Problem2. Return # of possibilities
 */
public class Queen {
    public ArrayList<String[]> solveNQueens(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<String[]> list = new ArrayList<String[]>();
        if (n>0) {
            int[] q = new int[n];
            solve(q, 0, n, list);
        }
        return list;
    }


    public void solve(int[] q, int k, int n, 
            ArrayList<String[]> list) {
        if (k == n) {
            list.add(getResult(q, n));
            return;
        }
        for (int i=0; i<n; i++) {
            q[k] = i;
            if (canPlace(q, i, k, n)) {
                solve(q, k+1, n, list);
            }
        }
    }

    public int totalNQueens(int n) {
        int[] q = new int[n];
        return getTotal(q, 0, n);
    }
    
    public int getTotal(int[] q, int k, int n) {
        if (k == n) return 1;
        int count = 0;
        for (int i=0; i<n; i++) {
            q[k] = i;
            if (canPlace(q, k, n)) {
                count += getTotal(q, k+1, n);
            }
        }
        return count;
    }

    public boolean canPlace(int[] q, int k, int n) {
        for (int i=0; i<k; i++) {
            if (q[i] == a[k] || Math.abs(q[i]-a[k]) == Math.abs(i-k)) 
                return false;
        }
        return true;
    }

    public String[] getResult(int[] q, int n) {
        String[] r = new String[n];
        char[] c = new char[n];
        for (int i=0; i<n; i++) {
            Arrays.fill(c, '.');
            c[q[i]] = 'Q';
            r[i] = new String(c);
        }
        return r;
    }

    public static void main(String[] args) {
        Queen q = new Queen();
        q.solveNQueens(2);
    }
}
