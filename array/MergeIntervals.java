/*
 * http://www.leetcode.com/onlinejudge
 */
import java.util.*;

public class MergeIntervals {
    class Interval {
        int start;
        int end;
        Interval (int s, int e) {
            start = s; end = e;
        }
    }

    public ArrayList<Interval> merge(ArrayList<Interval> intervals) {
        ArrayList<Interval> r = new ArrayList<Interval>();
        Collections.sort(intervals, new Comparator<Interval>() {
            public int compare(Interval a, Interval b) {
                return a.start - b.start;
            }
        });
        for (Interval curr : intervals) {
            if (r.isEmpty()) {
                r.add(curr);
                continue;
            } 
            int prev_idx = r.size()-1;
            Interval prev = r.get(prev_idx);
            if (prev.end < curr.start) {
                r.add(curr);
            } else {
                prev.end = Math.max(prev.end, curr.end);
                r.set(prev_idx, prev);
            }
        }
        return r;
    }
}
