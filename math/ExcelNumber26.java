import java.util.*;

public class ExcelNumber26 {
/*
 * http://www.leetcode.com/2010/10/amazon-bar-raiser-interview-question.html
 * Given the sequence S1 = {a,b,c,d,…,x,y,z,aa,ab,ac…. } and 
 * given that this sequence corresponds (term for term) to the sequence 
 * S2 = {0,1,2,3,….}. 
 * Write code to convert an element of S2 to the corresponding element of S1.
 */
    static String getExcelNumber(int n) {
        if (n<0) return "";
        return getExcelNumber(n/26 -1) + (char)('a'+n%26);
    }

    static String getExcelNumberIterative(int n) {
        if (n<0) return "";
        StringBuilder sb = new StringBuilder();
        while (n>=0) {
            sb.insert(0, (char)('a'+n%26));
            n = n/26 - 1;
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x;
        while ((x = sc.nextInt())>=0) {
            System.out.println(getExcelNumber(x));
            System.out.println(getExcelNumberIterative(x));
        }
    }
}
