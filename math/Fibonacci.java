import java.util.*;

public class Fibonacci {
    static int fibRecursive(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fibRecursive(n-1) + fibRecursive(n-2);
    }

    static int fib(int n) {
        if (n == 0) return 0;
        int n1, n2;
        n1 = 0;
        n2 = 1;
        for (int i=2; i<=n; i++) {
            int t = n1+n2;
            n1 = n2;
            n2 = t;
        }
        return n2;
    }

    static int fibTailRecursion(int n) {
        return fibTailRecursion(n, 0, 1);
    }

    static int fibTailRecursion(int times, int n1, int n2) {
        if (times == 0) return n1;
        else if (times == 1) return n2;
        return fibTailRecursion(times-1, n2, n1+n2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x;
        while ((x=sc.nextInt())>=0) {
            System.out.println(fib(x));
            System.out.println(fibRecursive(x));
            System.out.println(fibTailRecursion(x));
        }
    }
}
