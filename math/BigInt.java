import java.util.*;

/*
 * http://www.leetcode.com/onlinejudge
 */
public class BigInt {
    static String multiple (String s1, String s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        int[] c = new int[l1+l2];
        for (int i = l1-1; i>=0; i--) {
            int carry = 0;
            int m, n;
            m = l1-i-1;
            for (int j = l2-1; j>=0; j--) {
                int x = (s1.charAt(i) - '0') * (s2.charAt(j) - '0');
                n = l2-j-1;
                c[m+n] += x + carry;
                carry = c[m+n]/10;
                c[m+n] %= 10;
            }
            c[m+l2] = carry;
        }
        StringBuilder sb = new StringBuilder();
        int i = l1+l2-1;

        while (c[i]==0 && i>0) i--; //i>0!!!!!
        while (i>=0) {
            sb.append(c[i]);
            i--;
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        System.out.println(multiple(s1,s2));
    }
}
