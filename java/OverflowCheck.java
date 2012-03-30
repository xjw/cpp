public class OverflowCheck {
    public static int safeAdd(int x, int y) {
        if (y>0 ? x > Integer.MAX_VALUE - y
                : x < Integer.MIN_VALUE - y) {
            throw new ArithmeticException("Integer overflow");
        }
        return x + y;
    }

    public static int safeSubtract(int x, int y) {
        if (y>0 ? x < Integer.MIN_VALUE + y 
                : x > Integer.MAX_VALUE + y) {
            throw new ArithmeticException("Integer overflow");
                }
        return x - y;
    }

    /*
     * Be careful here!!!
     */
    public static int safeMultiply(int x, int y) {
        if (y>0 ? (x > Integer.MAX_VALUE/y || x < Integer.MIN_VALUE/y)
                : (y < -1 ? (x < Integer.MAX_VALUE/y || x > Integer.MIN_VALUE/y)
                          : (y == -1 && x == Integer.MIN_VALUE))) {
            throw new ArithmeticException("Integer overflow");
                          }
        return x * y;
    }

    public static int safeDivide(int x, int y) {
        if (x == Integer.MIN_VALUE && y == -1) {
            throw new ArithmeticException("Integer overflow");
        }
        return x/y;
    }

}
