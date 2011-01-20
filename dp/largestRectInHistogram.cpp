/**
 *  
 *  http://hi.baidu.com/bellgrade/blog/item/2db68150914f8f858c54308d.html
 *  http://www.mitbbs.com/article_t/JobHunting/31573617.html
 *  http://fayaa.com/tiku/view/83/
 *
 */

#include <iostream>

using namespace std;

void printArray(int a[], int n) {
  for (int i=0; i<n; ++i) {
    cout<<a[i]<<"-";
  }
  cout<<endl;
}

/**
 * 提示：如果一个矩形条出现在结果之中，那它往左和往右不低于它的矩形条都会出现在结果中，
 * 程序中出现的两个计数器可以不回退，对所有矩形的最左最优的计算可以在线性时间内完成。 
 */
int getLargestRecInHistogram1(int h[], int n) {
  int *left = new int[n];
  int *right = new int[n];
  int i, j, ret;

  left[0] = 0;
  right[n-1] = n-1;

  for (i=1; i<n; ++i) {
    for (j = i-1; j>=0 && h[j]>=h[i]; j = left[j]-1);
    left[i] = j+1;
  }
  // printArray(left, n);

  for (i=n-2; i>=0; --i) {
    for (j=i+1; j<=n-1 && h[j]>=h[i]; j = right[j]+1);
    right[i] = j-1;
  }
  // printArray(right, n);

  for (i=0, ret=0; i<n; ++i) {
    ret = max(h[i]*(right[i] - left[i] + 1), ret);
  }

  return ret;
}

/**
 * same idea with 1 but simpler edge case if index starts from 1 
 */
int getLargestRecInHistogram2(int a[], int n) {
  int *left = new int[n];
  int *right = new int[n];
  int i, j, ret;

  int *h = new int[n+2];
  h[0] = h[n+1] = -1;
  for (int i=1; i<n+1; i++) {
    h[i] = a[i-1];
  }

  for (i=1; i<=n; ++i) {
    for (j = i-1; h[j]>=h[i]; j = left[j]-1);
    left[i] = j+1;
  }
  // printArray(left, n);

  for (i=n; i>0; --i) {
    for (j=i+1; h[j]>=h[i]; j = right[j]+1);
    right[i] = j-1;
  }
  // printArray(right, n);

  for (i=1, ret=0; i<=n; ++i) {
    ret = max(h[i]*(right[i] - left[i] + 1), ret);
  }

  return ret;
}

struct element {
  int h;
  int lwidth;
  int idx;
};

const int N = 100;
int getLargestRecInHistogram(int h[], int n) {
  element e[N];
  for (int i=0; i<n; ++i) {
    e[i].h = h[i];
  }

  int top=-1;
  int max, area, lwidth;
  max = area = 0;

  for (int i=0; i<n; ++i) {
    while (top!=-1 && h[i]<e[top].h) {
      area = e[top].h * (i-e[top].idx+e[top].lwidth);
      if (area>max) max = area;
      top--;
    }

    if (top == -1) {
      lwidth = i;
    }
    else {
      lwidth = i-e[top].idx-1;
    }

    top++;
    e[top].idx = i;
    e[top].lwidth = lwidth;
  }

  cout << max << endl;
}



int main() {
  int a[] = {2,1,4,5,1,3,3};
  int n = sizeof(a)/sizeof(a[0]);
  // printArray(a, n);
  cout<<getLargestRecInHistogram1(a, n)<<endl;
  cout<<getLargestRecInHistogram2(a, n)<<endl;
  cout<<getLargestRecInHistogram(a, n);
  return 1;
}
