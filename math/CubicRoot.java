import java.util.*;

public class CubicRoot {
    static double EPSILON = 0.01;
    static double cubicRoot(double x) {
        if (x == 0) return 0;
        double x0, x1;
        x0 = x1 = x/2;
        do {
            x0 = x1;
            x1 = (x/(x0*x0) + 2*x0)/3;
        } while (Math.abs(x0-x1)>EPSILON);
        return x1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double x;
        while (( x = sc.nextDouble()) != 99.) {
            System.out.println(cubicRoot(x));
        }
    }
}
