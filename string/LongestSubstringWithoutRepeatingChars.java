/*
 * http://www.leetcode.com/2011/05/longest-substring-without-repeating-characters.html
 */
public class LongestSubstringWithoutRepeatingChars {
    public int lengthOfLongestSubstring(String s) {
        int[] a = new int[256];
        Arrays.fill(a,-1);
        int max, local_max;
        int start, end;
        max = local_max = 0;
        start = 0;
        for (int i=0; i<s.length(); i++) {
            if (a[s.charAt(i)]>=start) {
                local_max = i-start;
                max = Math.max(max,local_max);
                start = i;
            }
            a[s.charAt(i)] = i;        
        }
        local_max = s.length()-start;
        max = Math.max(max,local_max);
        return max;
    }

    public static void main(String[] args) {

    }
}
