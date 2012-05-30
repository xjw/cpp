public class Pow {
    static public double powFirstWithBug(double x, int n) {
        if (n==0) return 1;
        if (n<0) return pow(1/x, -n);
        double r = pow(x, n/2) * pow(x, n/2);
        return ((n&1)!= 0)? r*x : r;
    }

    static public double powSecondStillWithBug(double x, int n) {
        if (n==0) return 1;
        if (x==0) {
            if (n<0) throw new ArithmeticException("divide by zero");
            return 0;
        }
        if (n<0) return pow(1/x, -n);
        double r = pow(x, n/2) * pow(x, n/2);
        return ((n&1)!= 0)? r*x : r;
    }

    /*
     * 1st' Bug: divide by zero case & 2's bug
     * if n = Integer.MIN_VALUE
     * n = -n = Math.abs(n) (dead loop)
     */
    static public double pow(double x, int n) {
        if (n==0) return 1;
        if (n<0) {
            if (x==0) throw new ArithmeticException("divide by zero");
            x = 1/x;
            n = -n;
        }
        double r = pow(x, n/2);
        return ((n&1)== 0)? r*r : r*r*x;
    }

    public static void main(String[] args) {
        System.out.println(pow(-1.00000,-2147483648));
    }
}
