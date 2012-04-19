import java.util.*;

public class Permutate {
    public String swap(String s, int i, int j) {
        if (i==j) return s;
        char[] c = s.toCharArray();
        char t = c[i];
        c[i] = c[j];
        c[j] = t;
        return new String(c);
    }

    public void printPermutation(String s, int start) {
        if (start == s.length()-1) {
            System.out.println(s);
            return;
        }
        for (int i=start; i<s.length(); i++) {
            if (i==start || s.charAt(i) != s.charAt(start)) { // actually this does no work as expected e.g ABB
                printPermutation(swap(s,start,i), start+1);
            }
        }
    }

    public void printPermutationNoDup(String s, int start) {
        if (start == s.length()-1) {
            System.out.println(s);
            return;
        }
        for (int i=start; i<s.length(); i++) {
            if (i != start && s.charAt(i) == s.charAt(i-1)) continue;
            printPermutationNoDup(swap(s,start,i), start+1);
        }
    }

    // --- next permutation

    public void swap(char[] c, int i, int j) {
        char t = c[i];
        c[i] = c[j];
        c[j] = t;
    }

    public void reverse(char [] c, int i, int j) {
        while (i<j) {
            swap(c, i, j);
            i++;
            j--;
        }
    }

    /*
     * http://marknelson.us/2002/03/01/next-permutation/
     * NICE! From c++ stl
     * handle dulicates perfectly
     *
     */
    public boolean next_permutation(char[] c) {
        int len = c.length;
        if (len == 0 || len == 1) return false;
        int i, j, k;
        j = k = len -1;
        i = j-1;
        while (true) {
            if (i < 0) return false;
            if (c[i]<c[j]) {
                while(c[k]<c[i]) {k--;};
                swap(c, i, k);
                reverse(c, j, len-1);
                return true;
            }
            i--; j--;
        }
    }

    public static void main(String[] args) {
        Permutate p = new Permutate();
        p.printPermutation("ABC", 0);
        p.printPermutation("1234", 0);

        String s;
        Scanner sc = new Scanner(System.in);
        while (!"z".equals(s = sc.next())) {
            char[] c = s.toCharArray();
            while (p.next_permutation(c)) {
                System.out.println(c);
            }
        }
    }
}
