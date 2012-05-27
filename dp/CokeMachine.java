/*
   http://www.mitbbs.com/article_t1/JobHunting/32119891_0_1.html
 
   Three coke machines. Each one has two values min & max, which means if 
   you get coke from this machine it will load you a random volume in the range
   [min, max]. Given a cup size n and minimum soda volume m, show if it's 
   possible to make it from these machines.

   比如三台machine(50, 100), (100, 200), (500, 1000). n=110, m=40, yes. n=90, m
   =40, no. n=100, m=60, no.
 */
public class CokeMachine {
    int[][] machines = new int[][] {
        {50,100},
        {100,200},
        {500,1000},
    };

    boolean getCoke(int m, int n) {
        if (n<=0 || m> n) return false;
        for (int[] row : machines) {
            int min = row[0];
            int max = row[1];
            if ( (min>=m && max<=n)
                || getCoke(m-min, n-max))
                return true;
        }
        return false;
    }

    void test() {
        assert getCoke(40, 110);
        assert !getCoke(40, 90);
        assert !getCoke(60, 100);
    }

    public static void main(String[] args) {
        new CokeMachine().test();
    }

}
