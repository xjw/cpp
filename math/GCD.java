/*
 * http://www1.cse.wustl.edu/~ychen/131/Notes/Recursion/recursion.html
 */
import java.util.*;
public class GCD {
    static int gcd(int x, int y) {
        for (int d=Math.min(x, y); d>0; d--) {
            if (y%d ==0 && x%d ==0) return d;
        }
        return 1;
    }

    static int gcdEuclid(int x, int y) {
        if (y==0) return x;
        return gcdEuclid(y, x%y);
    }

    static int gcdDijkstra(int x, int y) {
        if (x == y) return x;
        return x>y? gcdDijkstra(x-y, y) : gcdDijkstra(y-x, x);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        System.out.println(gcd(x, y));
        System.out.println(gcdEuclid(x, y));
        System.out.println(gcdDijkstra(x, y));
    }

}
