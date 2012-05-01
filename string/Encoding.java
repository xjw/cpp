public class Encoding {
    public static String runLengthEncoding(String s) {
        StringBuilder sb = new StringBuilder();
        int i, j, n;
        i = j = 0;
        n = s.length();
        while (j<n) {
            while (j<n && s.charAt(i)==s.charAt(j)) j++;
            sb.append(j-i).append(s.charAt(i));
            i = j;
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        String s = "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW";
        System.out.println(runLengthEncoding(s));
    }
}
