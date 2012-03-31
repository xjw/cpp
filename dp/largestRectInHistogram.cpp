/**
 *  
 *  1. http://hi.baidu.com/bellgrade/blog/item/2db68150914f8f858c54308d.html
 *  2. http://www.mitbbs.com/article_t/JobHunting/31573617.html
 *  3. http://fayaa.com/tiku/view/83/
 *
 *  Solution Stack OR UNION
 *
 */

#include <iostream>
#include <stack>


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

/**
 * Using stack 
 * Combin ref1 + ref2 + ref3
 *
 * 考虑直方图的每个元素（每根柱子)，以它为高度的最大矩形，宽度可以向左右扩展。
 * 所以问题就转换为怎么确定左右边界。
 *
 * 我们使用了一个栈，从左到右每根柱子依次入栈。
 * 情形一：如果栈不空并且当前将要入栈的柱子比栈顶的柱子低，则有：
 *
 * 1. 栈顶柱子的右边界完全确定，其对应的局部最大矩形面积可求(下面说明了左边界在
 * 它入栈时已确定)。更新全局最大矩形面积后，栈顶柱子可以依次出栈，直到当前的栈
 * 顶柱子比当前要入栈的柱子低或者栈变为空栈。
 *
 * 2. 连续的出栈操作使得当前的栈顶柱子比当前要入栈的柱子低或者栈变为空栈, 这时
 * 候，当前要入栈的柱子的左边界也确定,可以入栈。情形二：如果栈为空或者当前要入栈的柱子比栈顶柱子高，
 * 则无出栈操作，且当前要入栈的柱子的左边界确定。
 *
 * 总结：
 * 1. 每个入栈操作, 如果入栈柱子低于栈顶柱子,则它确定了栈中比要入栈柱子高的那些柱子的右边界,
 * 可以对它们执行出栈操作。出栈的过程伴随着矩形面积的计算。
 * 2. 每个入栈操作，不论是否引起出栈操作,我们都可以确定当前要入栈柱子的左边界。
 * 3. 每次入栈后,栈内所剩柱子一定保持高度单调非递减的顺序。
 * 4. 可令最后一根柱子高度为-1, 保证必有出栈操作。
 * 5. 除了高度为-1的哑元柱子, 所有的柱子都入栈一次，出栈一次，复杂度为O(n)
 * 6. 对高度相同的两根柱子，我们可视后面的柱子比前面的柱子高。
 */
const int N = 100;
int getLargestRecInHistogram(int m[], int n) {
  int pos[N];
  int wid[N];
  int h[N+1];
  int top=-1;

  for (int i=0; i<n; i++) h[i]=m[i];
  h[n]=-1; //make sure the last element will pop all stacks
  
  int max, area, w;
  max = area = 0;

  for (int i=0; i<=n; ++i) {
    while(top !=-1 && h[i]<h[pos[top]]) {
      area = (i-pos[top]+wid[top])*h[pos[top]];
      if (area>max) max=area;
      top--;
    }
    if (top==-1)  w=i;
    else  w=i-pos[top]-1;
    top++;
    pos[top] = i;
    wid[top] = w;
  }

  return max;
}


int largestArea(int arr[], int len)
{
    int area[len]; //initialize it to 0
    int n, i, t;
    stack<int> St;  //include stack for using this #include<stack>
    bool done;

    for (i=0; i<len; i++)
    {
        while (!St.empty())
        {
            if(arr[i] <= arr[St.top()])
            {
                St.pop();
            }
            else
                break;
        }
        if(St.empty())
            t = -1;
        else
            t = St.top();
        //Calculating Li
        area[i] = i - t - 1;
        St.push(i);
    }

    //clearing stack for finding Ri
    while (!St.empty())
        St.pop();

    for (i=len-1; i>=0; i--)
    {
        while (!St.empty())
        {
            if(arr[i] <= arr[St.top()])
            {
                St.pop();
            }
            else
                break;
        }
        if(St.empty())
            t = len;
        else
            t = St.top();
        //calculating Ri, after this step area[i] = Li + Ri
        area[i] += t - i -1;
        St.push(i);
    }

    int max = 0;
    //Calculating Area[i] and find max Area
    for (i=0; i<len; i++)
    {
        area[i] = arr[i] * (area[i] + 1);
        if (area[i] > max)
            max = area[i];
    }

    return max;
}




int main() {
  // int a[] = {2,1,4,5,1,3,3};
  //int a[] = {2,1,4,5,1,5,5};
  //int a[] = {2,1,4,5,1,5,5};
  int a[] = {2,10,15,7,9,8,3};
  int n = sizeof(a)/sizeof(a[0]);
  // printArray(a, n);
  cout<<getLargestRecInHistogram1(a, n)<<endl;
  cout<<getLargestRecInHistogram2(a, n)<<endl;
  cout<<getLargestRecInHistogram(a, n)<<endl;
  cout<<largestArea(a, n)<<endl;
  return 1;
}
