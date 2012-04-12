import java.util.*;

public class Selection {
    public static void swap(int[] a, int i, int j) {
        if (i==j) return;
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    public static int partition(int[] a, int left, int right) {
        if (left >= right) return left;
        // select last one as pivot
        int p = a[right]; 
        int i, j;
        i = left;
        j = right-1;
        while (true) {
            while (a[i]<p) i++; //pay attention to this
            while (a[j]>p && i<j) j--;
            if (i>=j) break;
            swap(a, i,j);
        }
        swap(a, i, right);
        return i;
    }

    public static int select(int[] a, int k) {
        if (k<=0 || k > a.length) throw new IllegalArgumentException();
        int l = 0;
        int r = a.length-1;
        while (l <= r) {
            int m = partition(a, l, r);
            if (m+1 == k) return a[m];
            if (m+1 < k) l = m+1;
            else r = m-1;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] a = {1,6,5,4,3,7};
        Scanner sc = new Scanner(System.in);
        int k;
        while ((k = sc.nextInt()) >= 0) {
            System.out.println(select(a, k));
        }
    }
}
