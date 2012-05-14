import java.util.*;

public class RemoveDuplicate {
    static String removeDuplicateBruteforce(String s) {
        char[] a = s.toCharArray();
        int k = 0;
        for (int i=0; i<a.length; i++) {
            int j=0;
            while (j<i && a[j] != a[i]) j++;
            if (j == i) a[k++] = a[i];
        }
        return new String(a, 0, k);
    }

    static String removeDuplicate(String s) {
        char[] a = s.toCharArray();
        boolean[] dict = new boolean[256];
        int k = 0;
        for (int i=0; i<a.length; i++) {
            if (!dict[a[i]]) {
                a[k++] = a[i];
                dict[a[i]] = true;
            }
        }
        return new String(a, 0, k);
    }

    public static void main(String[] args) {
        String s;
        Scanner sc = new Scanner(System.in);
        while ((s = sc.next()) != null) {
            System.out.println(removeDuplicateBruteforce(s));
            System.out.println(removeDuplicate(s));
        }
    }

}
