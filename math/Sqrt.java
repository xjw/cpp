import java.util.*;

/*
 * http://www.nowamagic.net/algorithm/algorithm_EfficacyOfFunctionSqrt.php
 * Binary search
 * Newton
 *
 * And the best algorithm ever is source code for Quake by John Carmack
 *
 */
public class Sqrt {
    // PART I: Calculate an integer square root

    /*
     * 1. int sqrt using binary search/ bisection method
     * http://www.mathpath.org/Algor/squareroot/algor.square.root.binary.htm
     */
    public static int sqrtBinary(int x) {
        if (x<0) throw new IllegalArgumentException();
        if (x == 0 || x == 1) return x;
        int l, r, m;
        l = 0; r = x; m =x/2;
        do {
            m = l+(r-l)/2;
            if (m>Integer.MAX_VALUE/m || m*m>x) r=m;
            else if (m*m<x) l=m;
            else return m;
        } while (r-l>1);
        return l;
    }


    /*
     * x1 = (x0 + n/x0)/2
     */
    public static int newtonEstimate(int x0, int n) {
        return (x0 + n/x0) >> 1;
    }

    /*
     * http://en.wikipedia.org/wiki/Integer_square_root
     * Based on the stopping condition
     * |Xk+1 - Xk| < c (c=1 is the largest possible number for 
     * Xk+1 is the solution for sqrt(n)
     */
    public static int sqrtNewtonFirst(int n) {
        if (n ==0 || n == 1) return n;
        int x0, x1;
        x0 = 2; // why x0=2? possible overflow if x0=1 (if n=2147483647)
        x1 = newtonEstimate(x0, n);
        while(Math.abs(x0-x1)>1) {
            x0 = x1;
            x1 = newtonEstimate(x0, n);
        };
        while (x1*x1>n) x1--;
        return x1;
    }

    /*
     * http://www.codecodex.com/wiki/Calculate_an_integer_square_root
     * !!!WOW!!!!!
     *
     */
    public static int sqrtNewtonBest(int n) {
        if (n==0 || n==1) return n;
        int x0 = n/2;
        int x1 = newtonEstimate(x0, n);
        while(x0>x1) { // turning point from x^2>n to x^2<n
            x0 = x1;
            x1 = newtonEstimate(x0, n);
        }
        return x0; // get the one smaller than n
    }

    public static final double EPSILON = 0.00001;

    ////////////////////////////////////////////////////////
    // PARTII double sqrt
    public static double sqrtBinary(double n) {
        if (n<0) throw new IllegalArgumentException();
        if (n == 0) return 0;
        double l, r, m;
        if (n>1) {
            l = 1;
            r = n;
        } else {
            l = n;
            r = 1;
        }
        m = l + (r-l)/2;
        do {
            while (m > Integer.MAX_VALUE/m) {
                r = m;
                m = l + (r-l)/2;
            }
            if (m*m < n) l = m;
            else r=m;
            m = l + (r-l)/2;
        } while (Math.abs(m*m-n) > EPSILON);
        return m;
    }


    //////////////////////////////////////////////////////////////
    // NEWTON APPROACH
    //
    // TIME COMPLEXITY Analysis for newton method
    // http://en.citizendium.org/wiki/Newton's_method
    // Using Newton's method as described above, the time complexity of calculating a root of a function  with -digit precision, provided that a good initial approximation is known O(lgn F(n)), F(n) is  where  is the cost of calculating  with f(x)/f'(x) with n digit precision.

    public static double sqrtNewton(double n) {
        if (n<0) throw new IllegalArgumentException();
        if (n == 0) return 0;
        double x0, x1;
        x0 = n/2;
        x1 = (x0 + n/x0)/2;
        while (Math.abs(x0-x1)>EPSILON) {
            x0 = x1;
            x1 = (x0 + n/x0)/2;
        }
        return x1;
    }

    public static void testIntegerSqrt() {
        int[][] a = {
            {0,0},
            {1,1},
            {2,1},
            {3,1},
            {4,2},
            {5,2},
            {6,2},
            {7,2},
            {8,2},
            {9,3},
            {10,3},
            {1024,32},
            {8192,90},
            {2147395599,46339},
            {2147395600,46340},
            {2147483647,46340}
        };
        for (int i=0; i<a.length; i++) {
            assert a[i][1] == sqrtNewtonBest(a[i][0]) ;
            assert a[i][1] == sqrtBinary(a[i][0]) ;
            assert a[i][1] == sqrtBinary2(a[i][0]) ;
        }
    }

    public static void testSqrt() {
        double x;
        Scanner sc = new Scanner(System.in);
        while ((x = sc.nextDouble())>0) {
            System.out.println(sqrtBinary(x));
            System.out.println(sqrtNewton(x));
        }
    }

    public static void main(String[] args) {
        testIntegerSqrt();
    }
}
