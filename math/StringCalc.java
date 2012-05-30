/*
 * Given two binary strings, return their sum (also a binary string).
 http://www.leetcode.com/onlinejudge

 For example,
 a = "11"
 b = "1"
 Return "100".
 */
public class StringCalc {
    public String addBinary(String a, String b) {
        int la = a.length();
        int lb = b.length();
        int carry = 0;
        String r = "";
        for (int i=0; i<la || i<lb; i++) {
            int na = (i<la)? Character.getNumericValue(a.charAt(la-i-1)) : 0;
            int nb = (i<lb)? Character.getNumericValue(b.charAt(lb-i-1)) : 0;
            int c =  na + nb + carry;
            carry = c/2;
            r = (c % 2) + r;
        }
        return carry>0? carry + r : r;
    }
}
