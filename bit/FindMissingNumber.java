import java.util.*;

public class FindMissingNumber {
    // use bit array
    public int findMissingNumber() {
        int radix = 8;
        byte[] b = new byte[0xffffffff/radix];
        Scanner sc = new Scanner(new FileReader("a.txt"));
        while (sc.hasNextInt()) {
            int x = sc.nextInt();
            b[x/radix] |= 1<<(x%radix);
        }
        for (int i=0; i<b.length; i++) {
            if (b[i] != 0xff) {
                for (int j=0; j<radix; j++) {
                    if ((b[i] & (1<<j)) == 0)
                    return i*radix + j;
                }
            }
        }
    }
}
