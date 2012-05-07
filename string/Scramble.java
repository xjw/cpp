import java.util.*;
/*
 http://www.mitbbs.com/article_t1/JobHunting/32107851_0_1.html
 http://www.mitbbs.com/article_t1/JobHunting/32107851_0_5.html
 这个状态只需用 O(N^3) 的空间来保存就行，复杂度是 O(N^4)。
 假设 (i,j) 分别为 s1 和 s2 的开始 index，n 为子串的长度，k 是把字串分成两个
 子串的 pivot point (k = 1 ... n-1)：
 F(i, j, n) = F(i+n-k, j, k) && F(i, j+k, n-k) ||
             F(i, j, n-k)   && F(i+n-k, j+n-k, k)
 */
public class Scramble {
    Map<String, Boolean> map = new HashMap<String, Boolean>();

    boolean isScramble(String s1, String s2) {
        if (s1.length() != s2.length()) throw new IllegalArgumentException();
        int len = s1.length();
        if (len == 1) 
            return s1.equals(s2);
        for (int i=1; i<len; i++) {
            if (isScramble(s1.substring(0,i), s2.substring(0,i))
                    && isScramble(s1.substring(i), s2.substring(i)))
                return true;
            if (isScramble(s1.substring(0,i), s2.substring(len-i))
                    && isScramble(s1.substring(i), s2.substring(0,len-i)))
                return true;
        }
        return false;
    }

    boolean isScrambleMemorize(String s1, String s2) {
        if (map.containsKey(s1+s2)) return map.get(s1+s2);

        if (s1.length() != s2.length()) throw new IllegalArgumentException();
        int len = s1.length();
        if (len == 1) 
            return s1.equals(s2);

        boolean flag =false;
        for (int i=1; i<len; i++) {
            if ((isScrambleMemorize(s1.substring(0,i), s2.substring(0,i))
                    && isScrambleMemorize(s1.substring(i), s2.substring(i))) 
            ||
               (isScrambleMemorize(s1.substring(0,i), s2.substring(len-i))
                    && isScrambleMemorize(s1.substring(i), s2.substring(0,len-i))))
                flag = true;
        }
        map.put(s1+s2, flag);
        return flag;
    }


/*
 base case 为 F(i, j, 1) == true, iff s1[i] == s2[j]
 然后 bottom-up 建立表，从所有 F(i, j, 2) --> F(i, j, len)，len = s1 长度。
 那么答案就是 F(0, 0, len).
 以下是非递归的 bottom-up DP 代码，空间复杂度 O(N^3)，时间复杂度 O(N^4).
 */
    boolean isScrambleBottomUpDP(String str1, String str2) {
        char[] s1 = str1.toCharArray();
        char[] s2 = str2.toCharArray();
        int len = s1.length;
        boolean[][][] dp = new boolean[len][len][len];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }
        for (int n = 2; n < len; n++) {
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    boolean found = false;
                    for (int k = 1; !found && k <= n-1; k++) {
                        if ((dp[i+n-k][j][k] && dp[i][j+k][n-k]) ||
                                (dp[i][j][n-k] && dp[i+n-k][j+n-k][k])) {
                            found = true;
                        }
                    }
                    dp[i][j][n] = found;
                }
            }
        }
        return dp[0][0][len];
    }

    public static void main(String[] args) {
        Scramble s = new Scramble();
        System.out.println(s.isScramble("rgtae", "great"));
        System.out.println(s.isScramble("abb", "bab"));
        System.out.println(s.isScramble("abc", "bca"));
        System.out.println(s.isScrambleBottomUpDP("abc", "bca"));
    }

}
