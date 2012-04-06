import java.util.*;
/*
 * The maximal rectangle problem
 * http://drdobbs.com/database/184410529
 */
public class Histogram {
    /*
     * find the highest h 
     * and then go from left to h, whenever a[i]>left, left is set to a[i]
     * and then from right to h
     */
    public int getLargestWater(int[] a) {
        int h = 0;
        for (int i=1; i<a.length; i++) {
            if (a[i]>a[h]) h = i;
        }
        int total = 0;

        int left = a[0];
        for (int i=1; i<h; i++) {
            if (a[i]>left) left = a[i];
            else total += (left-a[i]);
        }

        int right = a[a.length-1];
        for (int i=a.length-2; i>h; i--) {
            if (a[i]>right) right = a[i];
            else total += right-a[i];
        }

        return total;
    }

    public void testWater() {
        int[][] data = {
            {1,0,1}, {1},
            {2,1,0,2}, {3},
            {1}, {0},
            {2,2}, {0},
            {2,3,4}, {0},
            {2,3,4,3,1}, {0}
        };
        for (int i=0; i<data.length; i+=2) {
            assert(getLargestWater(data[i]) == data[i+1][0]);
        }
    }

    /*
     http://tech-queries.blogspot.com/2011/03/maximum-area-rectangle-in-histogram.html
     Go through array three times
     1. Get Left[i]
     2. Get Right[i]
     3. Calculate width*height and getMax
     */
    public long getMaxAreaUsingStack(int[] h) {
        int[] w = new int[h.length];
        Stack<Integer> st = new Stack<Integer>();
        int pos;
        for (int i=0; i<h.length; i++) {
            while (!st.isEmpty() && h[st.peek()]>=h[i]) {
                st.pop();
            }
            pos = st.isEmpty()? -1 : st.peek();
            w[i] = i-pos-1;
            st.push(i);
        }

        while (!st.isEmpty()) {
            st.pop();
        }

        for (int i=h.length-1; i>=0; i--) {
            while(!st.isEmpty() && h[i]<=h[st.peek()]) {
                st.pop();
            }
            pos = st.isEmpty()? h.length : st.peek();
            w[i] += pos-i-1;
            st.push(i);
        }

        int max = 0;
        for (int i=0; i<h.length; i++) {
            max = Math.max(max, h[i]*(w[i]+1));
        }
        return max;
    }

    /**
     * Use this one ! The Approach to use
     *  
     *  1. http://hi.baidu.com/bellgrade/blog/item/2db68150914f8f858c54308d.html
     *  2. http://www.mitbbs.com/article_t/JobHunting/31573617.html
     *  3. http://fayaa.com/tiku/view/83/
     *
     *  Solution Stack OR UNION
     *
     * 提示：如果一个矩形条出现在结果之中，那它往左和往右不低于它的矩形条都会出现在结果中，
     * 程序中出现的两个计数器可以不回退，对所有矩形的最左最优的计算可以在线性时间内完成。 
     */
    public int getMaxAreaUsingLeftRightArray(int[] h) {
        int len = h.length;
        int[] left  = new int[len];
        int[] right = new int[len];
        left[0] = 0;
        right[len-1] = len-1;
        int i, j;
        for (i=1; i<len; i++) {
            for (j=i-1; j>=0 && h[i]<=h[j]; j=left[j]-1);
            left[i] = j+1;
        }
        for (i=len-2; i>=0; i--) {
            for (j=i+1; j<=len-1 && h[i]<=h[j]; j=right[j]+1);
            right[i] = j-1;
        }
        int max = 0;
        for (i=0; i<h.length; i++) {
            max = Math.max(max, h[i]*(right[i]-left[i]+1));
        }
        return max;
    }


    class E {
        int i;
        int l;
        E (int v) {i=v; l=0;}
    }

    public int getMaxArea(int[] h) {
        Stack<E> s = new Stack<E>();
        int max;
        for (int i=0; i<h.length; i++) {
            E top = s.peek();
            if (h[i] >= h[top.i]) {
                s.push(new E(i));
            } else {
                while(!s.empty() && h[i] < h[top.i]) {
                    max = Math.max(h[i] * (i-top.i+top.l));
                }
                E e = new E(i);
                e.l = s.empty()? i : i - s.peek().i; 
            }
        }
    }


    public int getMaxAreaSuccint(int[] hist) {
        int[] h = Arrays.copyOf(hist, hist.length+1);
        int len = h.length;
        int[] left = new int[len];
        int[] postack = new int[len];
        int area = 0;
        int top = -1; // top stack pointer
        h[len-1] = -1; // to make sure pop out stack at end
        for (int i=0; i<len; i++) {
            while(top != -1 && h[i] < h[postack[top]]) {
                // h * (right + left)
                area = Math.max(area,
                        h[postack[top]] * (i - postack[top] + left[top]));
                top--;
            }
            int l = (top == -1)? i : i-postack[top]-1;
            top++;
            left[top] = l;
            postack[top] = i;
        }
        return area;
    }

    public void test() {
        int[] a = {5,1,1,1,1,1};
        //int[] a = {2,10,15,7,9,8,3};
        System.out.println(new Histogram().getMaxAreaUsingStack(a));
        System.out.println(new Histogram().getMaxAreaUsingLeftRightArray(a));
        System.out.println(new Histogram().getMaxAreaSuccint(a));
    }

    public static void main(String[] args) {
        new Histogram().test();
    }

}
