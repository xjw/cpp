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
            System.out.println(isMatch(tests[i][0], tests[i][1]));
        }
    }

    public static void main(String[] args) {
        System.out.println(isMatch("a", "."));
        //testCases();
    }
}
