/*
 * http://en.wikipedia.org/wiki/Gray_code
 * http://introcs.cs.princeton.edu/java/23recursion/GrayCode.java.html
 * http://introcs.cs.princeton.edu/java/23recursion/
 */

import java.util.*;

public class GrayCode {
    // Approach 1: binary to gray from wiki 
    // x XOR (x/2)
    int graycodeHelper(int x) {
        return (x >> 1) ^ x;
    }

    void generateGrayCodeSimple(int n) {
        for (int i=0; i< (1<<n); i++) {
            //System.out.println(Integer.toBinaryString(graycodeHelper(i)));
            System.out.println(graycodeHelper(i));
        }
    }

    /* Approach 2
     * BEST!!!!!!!
     * IDEA is to append 1 to the previous values to get new additional values
     */
     ArrayList<Integer> grayCode(int n) {
         ArrayList<Integer> list = new ArrayList<Integer>();
         list.add(0);
         for (int i=0; i<n; i++) {
             for (int j=list.size()-1; j>=0; j--) {
                 list.add(list.get(j) | (1<<i));
             }
         }
         return list;
     }


    // Approach 3: recursion
    // http://introcs.cs.princeton.edu/java/23recursion/GrayCode.java.html
    void grayReverse(String prefix, int n) {
        if (n == 0) {
            System.out.println(prefix);
            return;
        }
        gray(prefix+"1", n-1);
        grayReverse(prefix+"0", n-1);
    }

    void gray(String prefix, int n) {
        if (n == 0) {
            System.out.println(prefix);
            return;
        }
        gray(prefix+"0", n-1);
        grayReverse(prefix+"1",n-1);
    }


    /*
     Approach 4: iterative
     To construct the binary-reflected Gray code iteratively,
     start with the code 0, and at step i find the bit position of the least significant '1' in the
     binary representation of i - flip the bit at that position in the previous code to get the next code.
     */
    int findLowestSetBit(int n) {
        int pos = 0;
        if (n > 0) {
            while ((n & 1<<pos) == 0)
                pos++;
        }
        return pos;
    }

    LinkedList<Integer> generateGrayCodeIterative(int n) {
        LinkedList<Integer> list  = new LinkedList<Integer>();
        list.add(0);
        for (int i=1; i<(int)Math.pow(2, n); i++) {
            list.add( (list.getLast()) ^ (1<<findLowestSetBit(i)) );
        }
        return list;
    }

    ///////////////////////////////
    // http://introcs.cs.princeton.edu/java/23recursion/Beckett.java.html
    //Google Question move(i) in and out
    /*
       初始N个人，站在ROOM外，给一个move(i)函数，如果i在外面，move以后就到room里
       ，如果在里面，就移动到外面，要你给出一个move函数，使得N个人的所有子集在房间
       中出现且仅出现一次，比如两个人，
       初始 {}
       move(1): {1}
       move{2}: {1, 2}
       move{1}: {2}
       */
    void move(int n, boolean in) {
        if (n==0) return;
        move(n-1, true);
        if (in) System.out.println("enter " + n);
        else System.out.println("exit " + n);
        move(n-1, false);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x;
        GrayCode g = new GrayCode();
        while ((x = sc.nextInt()) > 0) {
            //System.out.println(generateGrayCodeIterative(x));
            //g.gray("", x);
            System.out.println(g.grayCode(x));
            g.generateGrayCodeSimple(x);
            //g.move(x, true);
        }
    }
}
