public class Fibonacci {
    public int fibRecursive(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fibRecursive(n-1) + fibRecursive(n-2);
    }

    public int fib(int n) {
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
}
