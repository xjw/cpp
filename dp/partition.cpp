/**
 * http://www.mitbbs.com/article_t/JobHunting/31717591.html 
 * http://poj.org/problem?id=3273
 * http://poj.org/bbs?problem_id=3273
 * http://www.matrix67.com/blog/archives/1013
 *
 *第一套题里的二分题是一个简单题：把一个长为N的数列划分为M段，要求每段数之和的最大值最小。
 * 例如，把100 400 300 100 500 101 400分割成5块，则
 * 100 400 | 300 100 | 500 | 101 | 400是最优方案之一，最大值500已经不能再小了，
 * 这个题一看就知道是二分后贪心判断，“最大值最小”之类的关键词几乎成了二分题的信号灯。
 *
 *
 * 题意：给你天数n，和每天需要花的钱，让你把这些天分成m份（每份都是连续的天），要求每份的和尽量少，输出这个和。
 * 一开始二分的上界为n天花费的总和（相当于分成1份），下界为每天花费的最大值（相当于分成n份），然后二分，
 * 每次的mid值为（上界 + 下界）/ 2，然后根据mid值遍历n天花费，对n天的花费进行累加，
 * 每当超过mid值 份数++，看看这个mid值能把n天分成几份，
 * 如果份数大于m，表示mid偏小，下界 = mid + 1，
 * 反之小于等于mid，上界 = mid - 1，
 * 然后输出最后的mid值即可，
 * 复杂度为 O(nlogM)，M约为第一次的上界。
 */

#include <iostream>
using namespace std;

int partition_binary_search(int a[], int n, int k) {
  int sum, max;
  sum = max = 0;
  for (int i=0; i<n; ++i) {
    sum += a[i];
    if (a[i]>max) {
      max = a[i];
    }
  }
  int l, r, m, j;
  l = max;
  r = sum;
  while(l<r) {
    cout<<l<<"-"<<r<<endl;
    sum = 0;
    j = 1;
    m = (l+r)/2;
    for (int i=0; i<n; ++i) {
      if (a[i]+sum>m) {
        sum = a[i];
        j++;
      }
      else {
        sum += a[i];
      }
    }
    cout<<"m-"<<m<<" "<<"j"<<"-"<<j<<endl;
    // if (j==k) return m;
    // else if (j<k) r=m-1;
    // else l=m+1;
    if (j<=k) r=m;
    else l=m+1;
  }
  return l;
  return m;
}

//Use binary search to do greedy search
int max_t(int B[], int N)
{
	int m = 0;
	for(int i=0; i<N; i++)
		m = max(m, B[i]);
	return m;
}

int sum_t(int B[], int N)
{
	int s = 0;
	for(int i=0; i<N; i++)
		s += B[i];
	return s;
}

int partition(int B[], int N, int K) {
    int low = max_t(B, N);
    int high = sum_t(B, N);    

    int i, mid, painterNeeded, alreadyPainted;
    while (low < high) {
        mid = low + (high - low) / 2;

		// calculate k when max = mid
        i = 0;
        painterNeeded = 1;
        alreadyPainted = 0;
        while (i < N) {
            if (alreadyPainted + B[i] <= mid) {
                alreadyPainted += B[i];
                i++;
            }
            else { // exceeds one painter's maximum workload, assign another painter
                alreadyPainted = 0;
                painterNeeded++;
            }
        }

        if (painterNeeded <= K) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {
  int a[] = {1,2,3};
  int k = 2;
  // int a[] = {100, 400, 300, 100, 500, 101, 400};
  // int k = 5;
  
  // int a[] = {9, 8, 7, 9, 8, 1, 8, 4, 6, 8, 8, 6, 5};
  // int k = 2;

  cout<<partition_binary_search(a, sizeof(a)/sizeof(a[0]), k)<<endl;
  cout<<partition(a, sizeof(a)/sizeof(a[0]), k)<<endl;

  return 1;
}
