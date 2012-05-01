import java.util.*;

public class Prime {
    /*
     * http://www1.cse.wustl.edu/~ychen/131/Notes/Recursion/recursion.html
     */
    boolean primeHelper(int k, int n) {
        if (k>=n) return true;
        if (n % k == 0) return false;
        return primeHelper(k+1, n);
    }

    boolean isPrimeRecursive(int n) {
        return (n>1 && primeHelper(2, n));
    }

    boolean isPrime(int n) {
        if (n == 2) return true;
        if (n<2 || n % 2 == 0) return false;
        for (int i=3; i<=Math.sqrt(n); i+=2) {
            if (n%i == 0) return false;
        }
        return true;
    }

    void primeSieve(int n) {
        boolean[] isPrime = new boolean[n+1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i=2; i<=Math.sqrt(n); i++) {
            if (isPrime[i]) {
                for (int j=2*i; j<=n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i=0; i<=n; i++) {
            if (isPrime[i]) System.out.println(i);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Prime p = new Prime();
        int x;
        while ( (x = sc.nextInt()) > 0) {
            p.primeSieve(x);
            //System.out.println();
        }
    }
}
