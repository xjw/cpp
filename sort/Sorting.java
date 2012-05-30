import java.util.*;

public class Sorting {
    public static void quickSort(int[] a, int l, int r) {
        if (l>=r) return;
        int m = Partition.partition(a, l, r);
        quickSort(a, l, m-1);
        quickSort(a, m+1, r);
    }

    /*
     * Better quicksort using three way partition
     * Improvement for duplicate key
     */
    public static void quickSortOptimized(int[] a, int l, int r) {
        if (l>=r) return;
        int i, lower, upper;
        i = lower = l;
        upper = r;
        int p = a[i];
        while (i<=upper) {
            if (a[i] < p)
                Partition.swap(a, i++, lower++);
            else if (a[i]>p) {
                Partition.swap(a, i, upper);
                upper--;
            }
            else
                i++;
        }
        quickSortOptimized(a, l, lower-1);
        quickSortOptimized(a, upper+1, r);
    }

    public static void mergeSort(int [] a, int l, int r) {
        if (l>=r) return;
        int m = l + (r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        Partition.merge(a, l, m, r);
    }

    public static void insertionSort(int[] a) {
        for (int i=0; i<a.length-1; i++) {
            for (int j = i+1; j>0 && a[j]<a[j-1]; j--) {
                Partition.swap(a, j, j-1);
            }
        }
    }

    public static void insertionSortNoSwap(int[] a) {
        for (int i=1; i<a.length; i++) {
            int j, temp;
            j = i;
            temp = a[i];
            while(j>0 && a[j-1]>temp) j--;
            for (int k=i; k>j; k--) {
                a[k] = a[k-1];
            }
            a[j] = temp;
        }
    }

    public static void selectionSort(int[] a) {
        for (int i=0; i<a.length; i++) {
            int min = i;
            for (int j=i+1; j<a.length; j++) {
                if (a[j]<a[min]) min=j;
            }
            Partition.swap(a,i,min);
        }
    }

    public static void bubbleSort(int[] a) {
        for (int i=a.length-1; i>=0; i--) {
            for (int j=0; j<i; j++) {
                if (a[j]>a[j+1]) Partition.swap(a, j, j+1);
            }
        }
    }

    public static void bubbleSortOptimized(int[] a) {
        for (int i=a.length-1; i>=0; i--) {
            boolean sorted = true;
            for (int j=0; j<i; j++) {
                if (a[j]>a[j+1]) {
                    Partition.swap(a, j, j+1);
                    sorted = false;
                }
            }
            if (sorted) return;
        }
    }

    public static void main(String[] args) {
        int a[] = {8,7,1,3,10,9,4,5,2,15,4};
        int b[] = Arrays.copyOf(a, a.length);
        int c[] = Arrays.copyOf(a, a.length);
        int d[] = Arrays.copyOf(a, a.length);
        int e[] = Arrays.copyOf(a, a.length);
        int f[] = Arrays.copyOf(a, a.length);
        int g[] = Arrays.copyOf(a, a.length);
        quickSort(a, 0, a.length-1);
        mergeSort(b, 0, b.length-1);
        bubbleSort(c);
        insertionSort(d);
        insertionSortNoSwap(e);
        selectionSort(f);
        quickSortOptimized(g, 0, g.length-1);
        System.out.println(Arrays.toString(a));
        System.out.println(Arrays.toString(b));
        System.out.println(Arrays.toString(c));
        System.out.println(Arrays.toString(d));
        System.out.println(Arrays.toString(e));
        System.out.println(Arrays.toString(f));
        System.out.println(Arrays.toString(g));
    }

}
