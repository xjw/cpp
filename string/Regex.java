public class Regex {

    /*
     * http://www.leetcode.com/2011/09/regular-expression-matching.html

       implement regular expression matching with support for '.' and '*'.

       '.' Matches any single character.
       '*' Matches zero or more of the preceding element.

       The matching should cover the entire input string (not partial).

       The function prototype should be:
       bool isMatch(const char *s, const char *p)

       Some examples:
       isMatch("aa","a") → false
       isMatch("aa","aa") → true
       isMatch("aaa","aa") → false
       isMatch("aa", "a*") → true
       isMatch("aa", ".*") → true
       isMatch("ab", ".*") → true
       isMatch("aab", "c*a*b") → true
   */
    static boolean isMatch(String s, String p) {
        if (p.isEmpty()) return s.isEmpty();

        // if next is not *, then current must match
        if (p.length()==1 || p.charAt(1) != '*') {
            return !s.isEmpty() 
                && (p.charAt(0) == '.' || p.charAt(0) == s.charAt(0)) 
                && isMatch(s.substring(1), p.substring(1));
        }

        // else next is *
        int i = 0;
        while (i<s.length()) {
            if (isMatch(s.substring(i),p.substring(2)))
                return true;
            else if (p.charAt(0) == '.' || s.charAt(i) == p.charAt(0))
                i++;
            else 
                return false;
        }

        return isMatch(s.substring(i), p.substring(2));
    }

    // isMatch v2, use index instead of substring
    static boolean isMatch2(String s, String p) {
        return match(s, p, 0, 0);
    }

    static boolean match(String s1, String s2, int i1, int i2) {
        int l1 = s1.length();
        int l2 = s2.length();
        if (i2 == l2) return i1 == l1;

        // next is not *
        if (i2 == l2-1 || s2.charAt(i2+1) != '*') {
            return (i1 < l1 
                    && (s1.charAt(i1) == s2.charAt(i2) || s2.charAt(i2) == '.')); 
        }

        while (i1 < l1) {
            if (match(s1, s2, i1, i2+2)) //skip current s1
                return true;
            else if (s1.charAt(i1) == s2.charAt(i2) || s2.charAt(i2) == '.')
                i1++;
            else 
                return false;
        }

        return match(s1, s2, i1, i2+2);
    }


    static void testCases() {
        String[][] tests = new String[][]{
            {"aa", "a"},
            {"aa", "aa"},
            {"aaa", "aa"},
            {"aa", "a*"},
            {"aa", ".*"},
            {"ab", ".*"},
            {"aab", "c*a*b"},
            {"aaa", "aaa"},
            {"aaa", "aa"},
            {"aaa", "aaaa"},
            {"aaa", "a.a"},
            {"aaa", ".a"},
            {"aaa", "a*a"},
            {"aaa", "ab*a"},
            {"aaa", "ab*ac*a"},
            {"aaa", "ab*a*c*a"},
            {"aaca", "ab*a*c*a"},
            {"aaba", "ab*a*c*a"},
            {"aaa", ".*"},
            {"aa", "."},
            {"a", "."},
            {"a", "ab*"},
            {"a", "ab*a"},
            {"bbbba", ".*a*a"},
            {"ab", ".*"},
            {"a", ".*"},
            {"", ".*"},
            {"", "."},
            {"a", "."},
            {"", "c*"},
            {"a", "a."},
            {"a", ""},
            {"", ""},
            {"aasdfasdfasdfasdfas", "aasdf.*asdf.*asdf.*asdf.*s"},
            {"abbbcd", "ab*bbbcd"},
            {"abcdede", "ab.*de"},
        };
        for (int i=0; i<tests.length; i++) {
            System.out.println(isMatch2(tests[i][0], tests[i][1]));
        }
    }

    public static void main(String[] args) {
        System.out.println(isMatch("a", "."));
        System.out.println(isMatch2("ab", ".*"));
        testCases();
    }
}
