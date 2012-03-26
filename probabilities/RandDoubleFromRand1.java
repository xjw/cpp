import java.util.*;

/*
 http://www.mitbbs.com/article_t1/JobHunting/32054625_0_1.html
 http://www.mitbbs.com/article/JobHunting/32055195_0.html
 给你一个函数 bool Prob() ，有50%的概率返回 True，50%的概率返回 False
 请你用写一个新的函数：bool Prob2(double p)
 要求  p 的概率返回 True， 1 - p 的概率返回 False
 当然，肯定使用 Prob 了
 */
public class RandDoubleFromRand1 {

    /*
     * Use Rejection Sampling
     借助于prob，可以如此进行算法：
     设第k次调用prob前，目标区间是[a,b]；k=1,2,…。k=1时a=0,b=1。对于这一次调用，
     假想prob的工作方式是：随机一个[a,b]上的均匀分布数，如果这个数小于等于(a+b)/2
     ，则返回true；否则返回false。设x=a+p*(b-a)，prob2的工作方式可假想为：随机一
     个[a,b]上的均匀分布数，如果这个数小于等于x，则返回true；否则返回false。于是
     可按两种情况处理：
     (1)    x <= (a+b)/2
     如果调用prob返回true，表明prob产生的随机数在[a,(a+b)/2]之间，但无法确定这个
     随机数是否在[a,x]之间；此时令a’=a, b’=(a+b)/2，继续在[a’,b’]上重复上面的
     过程(第k+1次)。
     如果调用prob返回false，表明prob产生的随机数在((a+b)/2,b]之间，必不可能在[a,x
     ]之间，此时prob2可以返回false。
     (2)    x > (a+b)/2
     如果调用prob返回true，表明prob产生的随机数在[a,(a+b)/2]之间，此时这个随机数
     肯定在[a,x]之间，prob2返回true。
     如果调用prob返回false，表明prob产生的随机数在((a+b)/2,b]之间，但无法确定这个
     随机数是否在[a,x]之间；此时令a’=(a+b)/2，b’=b，继续在[a’,b’]上重复上面的
     过程(第k+1次)。
     算法很快，是指数收敛的。
     */
    public boolean rand(double p) {
        //System.out.println();
        double l = 0.;
        double r = 1.;
        double x = l + (r-l)*p;
        while(true) {
            double m = l + (r-l)/2.;
            //System.out.println(m + "-r-" + rand1 + "-x-" + x);

            // assume if rand1()==1 then rand1() in left half of [a,b] 
            // which is [a,a+(b-a)/2]
            // idea is:
            // if rand() in [a, x], return 1;
            // else 0;
            if (rand1()) { // value in [a,m]
                if (x>=m) return true;
                else r = m; // undecided have to run again
            } else { // value in (m,b]
                if (x<=m) return false;
                else l = m;
            }
        }
    }

    /*
       http://www.mitbbs.com/article_t1/JobHunting/32054625_0_3.html
       From peking2@mitbbs
       就是先找到概率>=0.5的解。
       然后调用Prob， 如果得到需要的解，就结束。如果没有得到需要的解，那么已经浪费
       了0.5的概率了。剩下的概率就是P-0.5.

       因为得到的解是相反的答案，而且概率是0.5, 所以就要在这个0.5里得到(P-0.5)的概
       率。那就是(P-0.5)/0.5。

       比如要得到0.6的概率true

       如果Prob返回true, 就结束。
       如果返回false，那么得到true的概率就剩0.1了。
       而得到false的概率是0.5, 在0.5里得到0.1就需要下一次调Fab得到true的概率是0.2. 
       这样的到true的总概率就是

       0.5+0.5*0.2=0.6
     */
    public boolean randSmarter(double p, boolean e) {
        double p0 = 0.5;
        if (p < p0)  return randSmarter(1-p, !e);
        if (rand1()) return e;
        else         return randSmarter((p-p0)/p0, e);
    }

    public boolean rand1() {
        Random random = new Random();
        return random.nextInt(2) == 0;
    }

    public static void main(String[] args) {
        RandDoubleFromRand1 r = new RandDoubleFromRand1();
        Scanner sc = new Scanner(System.in);
        int total = 1000;
        double x;
        while (( x = sc.nextDouble())>=0) {
            int c1 = 0;
            int c2 = 0;
            for (int i=0; i<total; i++) {
                if (r.rand(x)) {
                    c1++;
                }
                if (r.randSmarter(x,true)) {
                    c2++;
                }
            }
            System.out.println((double)c1/total);
            System.out.println((double)c2/total);
        }
        sc.close();
    }

}
