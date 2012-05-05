public class Reverse {
    void reverse(char[] a, int i, int j) {
        while (i<j) {
            char c = a[i];
            a[i] = a[j];
            a[j] = c;
            i++;
            j--;
        }
    }

    String reverseSentence(String s) {
        char[] a = s.toCharArray();
        reverse(a, 0, a.length-1);
        int i,j;
        i = j = 0;
        while (j<a.length) {
            if (a[j] != ' ') {
                i = j;
                while(j<a.length && a[j] != ' ') j++;
                reverse(a, i, --j);
            }
            j++;
        }
        return new String(a);
    }

    public static void main(String[] args) {
        Reverse r = new Reverse();
        System.out.println(r.reverseSentence("i have  a dream"));
    }
}
