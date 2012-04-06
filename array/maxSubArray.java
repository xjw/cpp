public class maxSubArray {
    public static int getMax(int[] a) {
        int max, max_including_current;
        max =  max_including_current = Integer.MIN_VALUE;
        for (int i=0; i<a.length; i++) {
            max_including_current = (max_including_current>0)? max_including_current + a[i] : a[i];
            max = Math.max(max, max_including_current);
        }
        return max;
    }

    public static void main(String[] args) {
        int a[] = {2,-6,7,-3,9,4};
        System.out.println(getMax(a));
    }
}
