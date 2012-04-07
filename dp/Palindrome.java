import java.util.*;

public class Palindrome {
    boolean isPalindrome(String s) {
        for (int l=0, r=s.length()-1; l<r; l--,r--) {
            if (s.charAt(l--) != s.charAt(r--)) return false;
        }
        return true;
    }

    // helper function
    public String longestPalindromeFromPosition(String s, int i, int j) {
        for (; i>=0 && j<s.length() && s.charAt(i)==s.charAt(j); i--,j++);

        return (++i != --j && s.charAt(i) == s.charAt(j))? 
            s.substring(i, j+1) : "";
    }

    // O(n^2)
    public String longestPalindrome(String s) {
        String p, p1, p2;
        p = "";
        for (int k=1; k<s.length(); k++) {
            p1 = longestPalindromeFromPosition(s, k-1, k+1);
            p2 = longestPalindromeFromPosition(s, k-1, k);
            if (p1.length() > p.length() || p2.length() > p.length()) {
                p = (p1.length() > p2.length())? p1 : p2;
            }
        }
        return p;
    }

    public static void main(String[] args) {
        Palindrome pa = new Palindrome();
        Map<String, String> map = new HashMap<String,String>();
        map.put("banana", "anana");
        map.put("bob", "bob");
        map.put("good", "oo");
        map.put("god", "");
        map.put("g", "");
        Iterator it = map.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry e = (Map.Entry) it.next();
            String s = (String)e.getKey();
            String p = (String)e.getValue();
            String out = pa.longestPalindrome(s);
            System.out.println(p + "=" + out);
            assert p.equals(out);
        }
    }
}
