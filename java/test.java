public class test {
    public static void main(String[] args) {
        for (int i=1000000000; i<=Integer.MAX_VALUE; i++) {
                if ((i > Integer.MAX_VALUE/10) && i == (i*10)/10) {
                    System.out.println(i);
                    return;
                }
        }
    }
}
