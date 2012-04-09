import java.util.*;


/**
 * SHOULD compare a[m] with right, consistent with findPivot
 * benefit of comparing with right is:
 *
 * if m==r, l must == r, because (l+r)/2 = r => l==r => l==r==m;
 * so 
 * if (a[m]>a[r]) else 
 * generate the same result with ====
 * if (a[m]>=a[r]) else
 *
 *
 * COMPARE with left will cause bugs if no additional careful check!!!
 *
 */
public class RotatedBinarySearch {
    public int search(int[] a, int x) {
        int l = 0;
        int r = a.length-1;
        while (l<=r) {
            int m = l + (r-l)/2;
            if (x == a[m]) return m;
            if (a[m]>a[r]) {
                if (x>=a[l] && x<a[m]) r = m-1;
                else l=m+1;
            }
            else {
                if (x<=a[r] && x>a[m]) l = m+1;
                else r = m-1;
            }
        }
        return -1;
    }

    public int findPivot(int a[]) {
        int l = 0;
        int r = a.length;
        while (a[l]>a[r]) {
            int m = l + (r-l)/2;
            if (a[m]>a[r]) l=m+1;
            else r=m;
        }
        return l;
    }

    public void testRotatedBinarySearch() throws Exception {
        List<int[]> arraylist = new ArrayList<int[]>();
        List<int[]> xlist = new ArrayList<int[]>();
        List<int[]> retlist = new ArrayList<int[]>();
        arraylist.add(new int[]{0});
        xlist.add(new int[] {-1,0,1});
        retlist.add(new int[] {-1,0,-1});

        arraylist.add(new int[]{0,1});
        xlist.add(new int[]{-1,0,1,2,100});
        retlist.add(new int[]{-1,0,1,-1,-1});

        arraylist.add(new int[]{1,0});
        xlist.add(new int[]  {-1,1,0,2});
        retlist.add(new int[]{-1,0,1,-1});

        arraylist.add(new int[]{0,1,2});
        xlist.add(new int[]{-1,0,1,2,3});
        retlist.add(new int[]{-1,0,1,2,-1});

        arraylist.add(new int[]{2,0,1});
        xlist.add(new int[]{-1,0,1,2});
        retlist.add(new int[]{-1,1,2,0});

        arraylist.add(new int[]{6,7,8,9,1,2,3,4,5});
        xlist.add(new int[]{-1,0, 6,7,8,9,1,2,3,4,5,100});
        retlist.add(new int[]{-1,-1,0,1,2,3,4,5,6,7,8,-1});

        //arraylist.add(new int[]{2,2,2,2,2,3,2,2}); // this is the catch for duplicate
        //xlist.add(new int[]{-1, 0, 1,2,3});
        //retlist.add(new int[]{-1,-1,-1,0,5});

        for (int i=0; i<arraylist.size(); i++) {
            for (int j = 0; j<retlist.get(i).length; j++) {
                int[] a = arraylist.get(i);
                int x = xlist.get(i)[j];
                int e = retlist.get(i)[j];
                int r =  search(a, x);
                if (r != e) {
                    throw new Exception (Arrays.toString(a) + " searching:" + x + " Found=>" + r + "!=" + e);
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        RotatedBinarySearch search = new RotatedBinarySearch();
        search.testRotatedBinarySearch();
    }
}
