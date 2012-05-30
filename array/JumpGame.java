import java.util.*;
/*
 * http://www.leetcode.com/onlinejudge
 *
 * JumpGame1
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 Each element in the array represents your maximum jump length at that position.
 Determine if you are able to reach the last index.
 For example:
 A = [2,3,1,1,4], return true.
 A = [3,2,1,0,4], return false.

 
 * JumpGame2
   Given an array of non-negative integers, you are initially positioned at the first index of the array.
   Each element in the array represents your maximum jump length at that position.
   Your goal is to reach the last index in the minimum number of jumps.
   For example:
   Given array A = [2,3,1,1,4]
   The minimum number of jumps to reach the last index is 2.
   (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */
public class JumpGame {

    // solution to problem 1:
    // record the furthest step
    public boolean canJump(int[] A) {
        int max = 0;
        int i=0;
        while (i<=max) {
            if (i+A[i]>max) max = i+A[i];
            if (max>=A.length-1) return true;
            i++;
        }
        return false;
    }


    /* solutions to problem 2
     *
     * Best Approach O(n)!!!! 
     * Greedy, jump as far as possible
     * http://www.mitbbs.com/article_t1/JobHunting/32118959_0_1.html
     */
    public int jump(int[] A) {
        int start, end, max, step;
        start = end = step = 0;
        while (end<A.length-1) {
            max = 0;
            while(start<=end) {
                max = Math.max(start+A[start],max);
                start++;
            }
            step++;
            start = end+1;
            end = max;
        }
        return step;
    }

    /*
     * Approach 2: DP
     */
     public int jumpDP(int[] A) {
        int len = A.length;
        int[] cache = new int[len];
        Arrays.fill(cache,len);
        cache[len-1]=0;
        
        for (int i=len-2; i>=0; i--) {
            int step = A[i];
            if (i+step>=len-1) {
                cache[i] = 1;
            } else {
                int min = len;
                while(step>0) {
                    min = Math.min(cache[i+step]+1, min);
                    step--;
                }
                cache[i] = min;
            }
        }
        return cache[0];
    }

    public 

    public static void main(String[] args) {
        JumpGame j = new JumpGame();
        System.out.println(j.jump(new int[] {2,0,2,0,1}));
        System.out.println(Integer.MAX_VALUE);
    }
}
