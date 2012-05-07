import java.util.*;

public class LowerUpperBound {
    /*
     * lower_bound 1st one = x
     * upper_bound 1st one > x
     * if (lower_bound == upper_bound) then x does not exist
     */
    int lower_bound(String[] a, String prefix) {
        int l, r, m;
        l = 0;
        r = a.length;
        while(l<r) {
            m = l + (r-l)/2;
            if (a[m].compareTo(prefix)<0) l = m+1;
            else r=m;
        }
        return l;
    }

    int upper_bound(String[] a, String prefix) {
        int l, r, m;
        l = 0;
        r = a.length;
        while(l<r) {
            m = l + (r-l)/2;
            if (a[m].startsWith(prefix) || a[m].compareTo(prefix)<=0) l = m+1;
            else r=m;
        }
        return l;
    }


    // for int 
    int lower_bound(int[] a, int x) {
        int l, r, m;
        l = 0;
        r = a.length-1;
        while (l<r) {
            m = l + (r-l)/2;
            if (x>a[m]) l = m+1;
            else r = m;
        }
        return l;
    }

    int upper_bound(int[] a, int x) {
        int l, r, m;
        l = 0;
        r = a.length-1;
        while (l<r) {
            m = l + (r-l)/2;
            if (x>=a[m]) l = m+1;
            else r = m;
        }
        return l;
    }

    void test() {
        String[] s = new String[] {
            "abc",
            "abcd",
            "acd",
            "add",
            "ae",
            "aef",
            "aefg",
            "aefg",
            "b",
            "bcv",
            "fr"
        };
        String prefix = "b";
        System.out.println(lower_bound(s, prefix));
        System.out.println(upper_bound(s, prefix));
    }

    void testInt() {
        int[] a = {1,1,2,2,2,3,3,3,3,3,3, 3, 4, 4, 5, 6, 6};
        int x;
        Scanner sc = new Scanner(System.in);
        while ((x = sc.nextInt()) != -1) {
            System.out.println(lower_bound(a, x));
            System.out.println(upper_bound(a, x));
        }
    }

    public static void main(String[] args) {
        LowerUpperBound p = new LowerUpperBound();
        p.testInt();
    }
}
