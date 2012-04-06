public class Subset {
    public void printSubset(int[] a, int k, int[] out, int arr_start, int out_start) {
        if (k == out_start) {
            for (int i=0; i<k; i++) {
                System.out.print(out[i] + " ");
            }
            System.out.println();
            return;
        }
        for (int i = arr_start; i<a.length; i++) {
            out[out_start] = a[i];
            printSubset(a,k,out,i+1,out_start+1);
        }
    }

    public void printSubset(int[] a, int k) {
        int[] out = new int[k];
        printSubset(a, k, out, 0, 0);
    } 


    //---------print string code is simpler because of String ----------------

    public void printStringSubset(String s, int k, String r, int start) {
        if (r.length() == k) {
            System.out.println(r);
            return;
        }
        for (int i=start; i<s.length(); i++) {
            printStringSubset(s, k, r+s.substring(i,i+1), i+1);
        }
    }

    public void printStringSubset(String s, int k) {
        String o = "";
        printStringSubset(s, k, o, 0);
    }

    public static void main(String[] args) {
        Subset s = new Subset();
        int a[] = {1,2,3,4,5};
        s.printSubset(a,3);
        s.printStringSubset("abcde",3);
    }

}
