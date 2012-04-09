public class Strstr {
    public String strStr(String haystack, String needle) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (needle == null || haystack == null 
                || needle.length() > haystack.length()) {
            return null;
                } 

        char[] h = haystack.toCharArray();
        char[] n = needle.toCharArray();
        int i, j;
        for (i=0; i<=h.length-n.length; i++) {
            for (j=0; j<n.length && h[i+j] == n[j]; j++);
            if (j == n.length) return haystack.substring(i);
        }
        return null;
    }
}
