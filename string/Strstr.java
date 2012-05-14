public class Strstr {
    /*
     * http://www.leetcode.com/2010/10/implement-strstr-to-find-substring-in.html
     * General version strstr
     */
    public String strStr(String haystack, String needle) {
        for (int i=0; i<=haystack.length()-needle.length(); i++) {
            int j = 0;
            while(j<needle.length()
                    && haystack.charAt(i+j) == needle.charAt(j))
                j++;
            if (j == needle.length()) return haystack.substring(i);
        }
        return null;
    }

    /*
     * haystack too big, stored in array
     */
    public String strStr(String[] haystack, String needle) {
        int i, j, k;
        i = j = 0;
        for (int i=0; i<haystack.length; i++) {
            String s = haystack[i];
            k = 0;
            while(j<needle.length && k<haystack.length 
                    && s.charAt(k) == needle.charAt(j)) {
                k++; j++;
            }

        }
    }
}
