public class FindMissingNumber {
    static int binarySearch(int[] a) {
        if (a.length<=1) throw new IllegalArgumentException();
        int l, r, m;
        l = 0;
        r = a.length-1;
        while (l<r-1) {
            m = (l+r)/2;
            int e = (a[l]+a[r])/2;
            if (e<a[m]) r=m;
            else l=m;
        }
        return a[l]+1;
    }

    public static void main(String[] args) {
        System.out.println(binarySearch(new int[] {1,2,3,5,6}));
        System.out.println(binarySearch(new int[] {1,3,4,5,6}));
        System.out.println(binarySearch(new int[] {1,2,4}));
        System.out.println(binarySearch(new int[] {1,3,4}));
    }
}
