import java.util.*;


/*
 * Problem 1:
     giving lots of intervals [ai, bi], 
     find a point intersect with the most number of intervals
     http://www.mitbbs.com/article_t1/JobHunting/32063239_0_1.html

 * Problem 2:
     A period of time where users login and logout, given a sets of login and 
     logout time pairs, write a function that can show the number of users online
     at any given time.
     http://www.mitbbs.com/article_t1/JobHunting/32098277_0_1.html
    
 * Solution:
     Both come to same solution
     1) sort by timestamp (mark each point (login or logout), for problem 2, it's automatically sorted by time
        because of the login logout event happens sequentially (online event)
     2) Go through the list, 
        if (login/start) count++
        else count--
     3) For overlapping
     If 如果每个interval包括起始点，不包括结束点
     [10 20) [20 40)

     10 20 20 40
     +1 -1 +1 -1

     如果每个interval包括起始点和结束点
     [10 20] [20 40]

     10 20 20 40
     +1 +1 -1 -1
     或者先把这样的interval合并
 *
 */

public class IntervalProblems {
    static class Point implements Comparable<Point> {
        int val;
        boolean start; 
        Point (int v, boolean s) {
            val = v;
            start = s;
        }
        public int compareTo(Point p) {
            return this.val - p.val;
        }
    }
    /*
     */
    public static int find_most_intervals(int[][] intervals) {
        if (intervals == null || intervals.length == 0) 
            return 0;

        List<Point> list  = new ArrayList<Point>();

        for (int[] row : intervals) {
            list.add(new Point(row[0], true));
            list.add(new Point(row[1], false));
        }
        Collections.sort(list);

        int count, max, max_point;
        max = count = max_point = 0;

        for (Point p : list) {
            if (p.start) count++;
            else count--;
            if (count > max) {
                max = count;
                max_point = p.val;
            }
        }
        System.out.println(max_point);
        return max;
    }

    public static int[][] createIntervals() {
        return new int[][] {
            {10, 25}, {20, 45}, {30, 48}, {40, 44}, {50, 55}
        };
    }

    public static void main(String[] args) {
        System.out.println(find_most_intervals(createIntervals()));
    }
}
