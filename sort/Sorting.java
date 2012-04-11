import java.util.*;

public class Sorting {
    public static void quickSort(int[] a, int l, int r) {
        if (l>=r) return;
        int m = Partition.partition(a, l, r);
        quickSort(a, l, m-1);
        quickSort(a, m+1, r);
    }

    public static void mergeSort(int [] a, int l, int r) {
        if (l>=r) return;
        int m = l + (r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        Partition.merge(a, l, m, r);
    }

    public static void main(String[] args) {
        int a[] = {8,7,1,3,10,9,4,5,2,15,4};
        int b[] = Arrays.copyOf(a, a.length);
        quickSort(a, 0, a.length-1);
        mergeSort(b, 0, b.length-1);
        System.out.println(Arrays.toString(a));
        System.out.println(Arrays.toString(b));
    }
}
