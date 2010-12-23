/**
 *  http://blog.chinaunix.net/u3/105033/showart_2209043.html
 *  http://www.mitbbs.com/article_t1/JobHunting/31728173_0_4.html
 */

#include <iostream>
#include <queue>
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

using namespace std;

int a[] = {1, 3, -1, -3, 5, 3, 6, 7};
int n = ARRAY_SIZE(a);

class comp {
  bool flag;
  public:
  comp(const bool flagparam=false) : flag(flagparam) {}
  bool operator() (const int &x, const int &y) const {
    if (flag) return a[x]>a[y];
    else return a[x]<a[y];
  }
};

void slidingWindow(int a[], int n, int k) {
  priority_queue<int, vector<int>, comp> pq_max;
  priority_queue<int, vector<int>, comp> pq_min (comp(true));
  int i;
  for (i=0; i<k; ++i) {
    pq_max.push(i);
    pq_min.push(i);
  }
  cout<<a[pq_max.top()]<<" "<<a[pq_min.top()]<<endl;
  for (i=k; i<n; ++i) {
    pq_max.push(i);
    pq_min.push(i);
    while (!pq_max.empty() && pq_max.top()<=i-k) pq_max.pop();
    while (!pq_min.empty() && pq_min.top()<=i-k) pq_min.pop();
    cout<<a[pq_max.top()]<<" "<<a[pq_min.top()]<<endl;
  }
}

int main() {
  slidingWindow(a, n, 3);
  return 1;
}
