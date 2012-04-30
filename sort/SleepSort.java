/*
 * http://rosettacode.org/wiki/Sorting_algorithms/Sleep_sort#Java
 * http://dis.4chan.org/read/prog/1295544154
 * Time Complexity O(highest value in threads + n) linear time for creating each thread
 */
public class SleepSort {
    static void sleepsort(int[] a) {
        for (final int n : a) {
            new Thread(new Runnable() {
                public void run() {
                    try {
                        Thread.sleep(10*n);
                        System.out.println(n);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }).start();
        }
    }

    public static void main(String[] args) {
        int[] a = {3, 1, 4, 5, 2, 3, 1, 6, 1, 3, 2, 5, 4, 6,};
        sleepsort(a);
    }
}
