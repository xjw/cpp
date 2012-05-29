/*
 * Validate if a given string is numeric.

 http://www.leetcode.com/onlinejudge
 http://dl.dropbox.com/u/19732851/LeetCode/ValidNumber.html

 Some examples:
 "0" => true
 " 0.1 " => true
 "abc" => false
 "1 a" => false
 "2e10" => true

 Note: It is intended for the problem statement to be ambiguous. 
 You should gather all requirements up front before  implementing one.

 */
public NumberValidation {
     public boolean isNumber(String s) {
        if (s.isEmpty()) return false;
        int i=0;
        int len = s.length();
        boolean isNum, isExp, isDecimal, hasSpace;
        isNum = isExp = isDecimal = hasSpace = false;

        while (i<len && s.charAt(i) == ' ') i++; // skip begining space
        if (i< len && (s.charAt(i) == '+' || s.charAt(i) == '-')) i++; //skip initial sign

        while (i<len) {
            char c = s.charAt(i);
            if (c == ' ')
                hasSpace = true;
            else if (hasSpace)
                return false; //non space following space make it invalid
            else if (c >= '0' && c <= '9')
                isNum = true;
            else if (c == '.') {
                if (isExp || isDecimal) return false;
                isDecimal = true;
            } else if (c == 'e' || c == 'E') {
                if (isExp || !isNum) return false;
                isExp = true;
                isNum = false; // expect number after E, so make it false for now
            } else if (c == '+' || c == '-') {
                if (s.charAt(i-1) != 'e') return false; //sign should only follow e
            } else 
                return false; // anything else if invalid
            i++;
        }
        return isNum;
    }
}
