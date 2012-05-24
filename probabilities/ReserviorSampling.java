/*
 * http://gregable.com/2007/10/reservoir-sampling.html
 * http://eyalsch.wordpress.com/2010/04/01/random-sample/ 
 */
public class ReserviorSampling {
    static int[] getRandomK(int[] a, int k) {
        int[] ret = new int[k];
        Random r = new Random();
        for (int i=0, j=0; i<a; i++) {
            if (j<k) ret[j++]=a[i];
            else {
                int p = r.nextInt(i+1);
                if (p<k) a[p] = a[i];
            }
        }
        return ret;
    }
}
