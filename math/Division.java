public class Division {
    /*
     * http://courses.cs.vt.edu/~cs1104/BuildingBlocks/divide.030.html
     * http://www.bearcave.com/software/divide.htm
     * http://www.leetcode.com/onlinejudge
     * COULD OVERFLOW!!!!!!!!!!!!!!!!
     */
    public static long binaryDivision(int dividend, int divisor) {
        if (divisor == 0) throw new ArithmeticException();
        long x = dividend; ////////////////////////why? must have!!!!!
        long y = divisor; 

        boolean neg = false;
        if ((x > 0 && y < 0) || (x < 0 && y > 0)) {
            neg = true;
        }
        x = Math.abs(x); //////////////////////////BUGGGGGGGGGGGGGG
        y = Math.abs(y);

        int n = 0;
        while ((y<<n) < x) {
            n++;
        }
        long r = 0;
        while (n>=0) {
            if ((y<<n) <= x) {
                r |= (1<<n);
                x -= (y<<n);
            }
            n--;
        }
        return (neg? -r : r);
    }


    public static void main(String[] args) {
        System.out.println(binaryDivision(Integer.MIN_VALUE, -1));
    }
}
