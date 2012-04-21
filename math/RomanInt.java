import java.util.*;


/*
 * http://www.leetcode.com/onlinejudge
 * http://www.mitbbs.com/article_t/JobHunting/32098547.html
 */
public class RomanInt {
    public int lookup(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }


    public char lookup(int x) {
        switch (x) {
            case 1:
                return 'I';
            case 5:
                return 'V';
            case 10:
                return 'X';
            case 50:
                return 'L'; 
            case 100:
                return 'C';
            case 500:
                return 'D';
            case 1000:
                return 'M';
        }
        return 0;
    }

    /*
     * VI => 5+1 = 6
     * IV => 5-1 = 4
     * So check the one next to current, 
     * if bigger, then next-current, then increment 2
     * else go step by step
     */
    public int romanToInt(String s) {
        if (s == null || s.isEmpty()) return 0;
        int c, n, i, r;
        c = n = i = r = 0;
        while (i < s.length()) {
            c = lookup(s.charAt(i));
            if (i+1 < s.length()) {
                n = lookup(s.charAt(i+1));
                if (n>c) {
                    r += (n-c);
                    i += 2;
                    continue;
                }
            }
            r += c;
            i++;
        }
        return r;
    }


    public String intToRoman(int n) {
        if (n<=0 || n>=4000) return "";

        List<Integer> list = new LinkedList<Integer>();
        while (n>0) {
            list.add(0,n%10);
            n /= 10;
        }

        StringBuilder sb = new StringBuilder();
        int i = list.size()-1;
        for (int d : list) {
            int base = (int)Math.pow(10,i);
            if (d == 4) {
                sb.append(lookup(base)).append(lookup(5*base));
            } else if (d == 9) {
                sb.append(lookup(base)).append(lookup(10*base));
            } else {
                if (d>=5) {
                    sb.append(lookup(5*base));
                }
                for (int mod = d % 5; mod >0 ; mod--) {
                    sb.append(lookup(base));
                }
            }
            i--;
        }

        return sb.toString();
    }

    public static void main(String[] args) {
    }
}
