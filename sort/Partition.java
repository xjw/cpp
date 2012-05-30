import java.util.*;

/*
 * Attention to the difference among
 *
 * partitionBasic (i, k) return k
 * partitionDutchFlag (i, j, k) return k
 * partition (just i, j) return i
 *
 */
public class Partition {
    public static void swap (int[] a, int i, int j) {
        if (i==j) return;
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    public static int partitionBasic(int[] a, int l, int r) {
        int pivot = a[r];
        int i, j;
        for (i=j=l; i<r; i++) {
            if (a[i]<pivot) {
                swap(a, i, j);
                j++;
            }
        }
        swap(a, j, r);
        return j;
    }


    /*
     * this is wrong for example int[] a = {1,6,5,4,3,7};
     */
    public static int partitionWrong(int[] a, int l, int r) {
        if (l>=r) return l;

        int pivot = a[r];
        int i, j;
        i = l;
        j = r-1;
        while (true) {
            while (a[i]<pivot && i<j) i++;
            while (a[j]>pivot && i<j) j--;
            if (i>=j) break;
            swap(a, i, j);
        }
        swap(a, i, r);
        return i;
    }

    public static int partition(int[] a, int l, int r) {
        if (l>=r) return l;
        int i, j;
        int p = a[r];
        i = l;
        j = r-1;
        while (true) {
            while (a[i]<p) i++; 
            while (a[j]>p && j>i) j--;
            if (i>=j) break;
            swap(a, i, j);
        }
        swap(a, i, r);
        return i;
    }

    public static int partitionHoare(int[] a, int l, int r) {
        int p = a[l+(r-l)/2]; // can be any between l and r
        while (true) {
            do r--; while (a[r]>p);
            do l++; while (a[l]<p);
            if (l<r) swap(a, l, r);
            else return r+1;
        }
    }

    /*
     * http://www.sorting-algorithms.com/static/QuicksortIsOptimal.pdf
     */
    public static void partitionThreeWay(int[] a, int l, int r) {
        int p = a[r];
        int i, j, m, n, u, v;
        m = i = 0;
        n = j = r-1;
        while (true) {
            while (a[i]<p && i<j) i++;
            while (a[j]>p && i<j) j--;
            if (i>=j) break;
            if (a[i] == p) {swap(a, i, m); m++;} // move equal to left
            if (a[j] == p) {swap(a, j, n); n--;} // move equal to right
        }
        swap(a, i, r);
        u = l-1;
        v = j+1;
        // now those euqal to p are on left and right side of array
        for (int k=l; k<m; k++,u--) swap(a, k, u);
        for (int k=r; k>n; k--,v++) swap(a, k, v);
    }

    /*
     * partition three different values, m is the middle value
     */
    public static int partitionDutchFlag(int[] a, int m) {
        int i, j, k;
        i = k = 0;
        j = a.length-1;
        while (i<=j) { //import while condition until =====
            if (a[i]<m)
                swap(a,i++,k++);
            else if (a[i]>m)
                swap(a,i,j--);
            else 
                i++;
        }
        return k;
    }

    public static void merge(int[] a, int l, int m, int r) {
        int[] aux = new int[r-l+1];
        int i, j, k;
        for (i=l,j=m+1,k=0; i<=m && j<=r; ) {
            aux[k++] = (a[i]<a[j])? a[i++] : a[j++];
        }
        while (i<=m) aux[k++] = a[i++];
        while (j<=r) aux[k++] = a[j++];
        for (i=l, k=0; i<=r; i++, k++) a[i] = aux[k];
    }

    public static void mergeB(int[] a, int l, int m, int r) { 
        int i,j,k;
        int[] aux = new int[100];
        for (i=l, k=0; i<m; i++, k++) aux[k] = a[i];
        for (j=m, k=r; j<=r; j++, k--) aux[k] = a[j];
        for (i=k=l,j=r; i<j; ) {
            a[k++] = (aux[i]<aux[j])? aux[i++] : aux[j--];
        }
    }

    public static void testPartition() {
        int[] a = {1,2,1,3,6,4,5,7,3};
        int len = a.length;
        //partitionBasic(a, 0, len-1);
        //partition(a, 0, len-1);
        //partitionThreeWay(a, 0, len-1);
        System.out.println(partition(a, 0, len-1));
        System.out.println(Arrays.toString(a));
    }

    public static void testDutchFlagPartition() {
        //int a[] = {2,2,1,1,3,3};
        int a[] = {7,3,4,1,5,4,2,2,1,1,3,3,6,9,1};
        System.out.println(partitionDutchFlag(a,4));
        System.out.println(Arrays.toString(a));
    }

    public static void testMerge() {
        int[] a = {1,2,6,3,4,5};
        int[] b = Arrays.copyOf(a, a.length);
        merge(a, 0, 3, 5);
        mergeB(b, 0, 3, 5);
        System.out.println(Arrays.toString(a));
        System.out.println(Arrays.toString(b));
    }

    public static void main(String[] args) {
        testDutchFlagPartition();
        //testPartition();
    }
}
