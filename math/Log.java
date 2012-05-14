/*
 * if x close to 1, log2(x) = x/ln2
 * else log2(x) = 2*log2(sqrt(x))
 * http://shashank7s.blogspot.com/2011/05/write-function-that-computes-log2-using.html
 */
import java.util.*;
public class Log {
    static double epsilon = 0.0001;
    static double log2(double x) {
        if (x<=0) throw new IllegalArgumentException();
        if (x-1<epsilon) return (x-1)/Math.log(2);
        else return 2*log2(Math.sqrt(x));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double x;
        while ((x = sc.nextDouble()) > 0) {
            System.out.println(log2(x) + "-" + Math.log(x)/Math.log(2));
        }
    }
}
