import java.util.*;

public class StringMisc {
    String removeCharInplace(String s, char c) {
        char[] arr = s.toCharArray();
        int r, w;
        r = w = 0;
        while (r<arr.length) {
            if (arr[r] == c) r++;
            else arr[w++] = arr[r++];
        }
        return new String(arr, 0, w);
    }

    /*
     * Question from Google
     * Remove A in string, and double B
     * CAABD => CBBD
     * Two loops
     * 1st one remove a and count b
     * get new_len
     * 2nd one double b
     */
    String removeANDoubleB(String s) {
        char a[] = s.toCharArray();
        int r, w, count=0;
        r = w = 0;
        while (r<a.length) {
            if (a[r] == 'A') r++;
            else {
                if (a[r] == 'B') count++;
                a[w++] = a[r++];
            }
        }
        int new_len = w+count;
        if (new_len > a.length) 
            throw new RuntimeException("arr length not enough");
        r = w-1;
        w = new_len-1;
        while (w>=0) {
            a[w--] = a[r];
            if (a[r] == 'B')
                a[w--] = a[r];
            r--;
        }
        return new String(a, 0, new_len);
    }

    public static void main(String[] args) {
        StringMisc sm = new StringMisc();
        System.out.println(sm.removeCharInplace("llHello, world!ll",'l'));
        System.out.println(sm.removeCharInplace("CAABD",'A'));
        System.out.println(sm.removeANDoubleB("CAABBD"));
    }
}
