import java.util.*;
/*
   Given an array of non-negative integers, you are initially positioned at the first index of the array.
   Each element in the array represents your maximum jump length at that position.
   Your goal is to reach the last index in the minimum number of jumps.
   For example:
   Given array A = [2,3,1,1,4]
   The minimum number of jumps to reach the last index is 2.
   (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */
public class JumpGame {
    public int jump(int[] A) {
        int len = A.length;
        int[] cache = new int[len];

        Arrays.fill(cache, len);
        cache[len-1] = 0;

        for (int i=len-2; i>=0; i--) {
            int step = A[i];
            if (step <= 0) {continue;}
            if (i + step >= len -1) {
                cache[i] = 1;
            } else {
                for (int j=i+1; j<=i+step; j++) {
                    cache[i] = Math.min(cache[i], 1+cache[j]);
                }
            }
        }
        return cache[0];
    }

    public static void main(String[] args) {
        JumpGame j = new JumpGame();
        System.out.println(j.jump(new int[] {2,0,2,0,1}));
        System.out.println(Integer.MAX_VALUE);
    }
}
