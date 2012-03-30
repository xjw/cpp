import java.util.*;

public class AtoiItoa {
    public static int itoa(String s) {
        int x = 0;
        if (s == null || s.isEmpty()) return x;
        int i = 0;
        int neg = 1;
        if (s.charAt(0) == '-') {
            i++;
            neg = -1;
        }
        while (i<s.length()) {
            char c = s.charAt(i++);
            if (c<'0' || c>'9') throw new RuntimeException("invalid input");
            if (x > Integer.MAX_VALUE/10) throw new ArithmeticException("integer overflow");
            x *= 10;
            if (x > Integer.MAX_VALUE - (c - '0')) throw new ArithmeticException("integer overflow");
            x += c - '0';
        }
        return x*neg;
    }

    public static String atoi(int x) {
        StringBuilder sb = new StringBuilder();
        boolean neg = false;
        if (x<0) {
            x = -x;
            neg = true;
        }
        do {
            sb.append(x%10);
            x = x/10;
        } while (x>0);

        if (neg) {
            sb.append("-");
        }

        return sb.reverse().toString();
    }

    public static void testItoa() {
        Scanner sc = new Scanner(System.in);
        String s;
        //while (!"x".equals(s = sc.next())) {
            //System.out.println(itoa(s));
        //}
        int x;
        while (9 != (x = sc.nextInt())) {
            System.out.println(atoi(x));
        }
    }

    public static void main(String[] args) {
        testItoa();
    }

}
