/**
 * K-Way merge using priority queue  
 * part of external merge sort step
 * http://inder-gnu.blogspot.com/2008/01/merge-k-sorted-lists-of-size-n.html
 * http://robblog.javaeye.com/blog/566114
 */

#include <iostream>
#include <queue>

using namespace std;

#define SIZE(x) (sizeof(x)/sizeof(x[0]))

class Element {
 public:
  int data;
  int left;
  int *p;
  Element(int d, int *pt, int l) {data=d; p=pt; left=l;}
  bool operator<(const Element& rhs) const {return data>rhs.data;}
};

void k_way_merge(int a[], int n1, int b[], int n2, int c[], int n3, int d[], int n4, int e[], int n5, int r[], int n6) {
  priority_queue<Element> pq;
  pq.push(Element(*a, a, n1-1));
  pq.push(Element(*b, b, n2-1));
  pq.push(Element(*c, c, n3-1));
  pq.push(Element(*d, d, n4-1));
  pq.push(Element(*e, e, n5-1));

  while(!pq.empty()) {
    Element top = pq.top();
    *r++ = top.data;
    pq.pop();
    if (top.left>0) {
      int *nextp = top.p + 1;
      pq.push(Element(*nextp, nextp, top.left-1));
    }
  }
}

int main() {
  // int a[] = {5,4};
  // int b[] = {4,3};
  // int c[] = {6};
  // int d[] = {9,2,1};
  // int e[] = {8,2};

  int a[] = { 6, 19, 24, 31 };
  int b[] = { 2, 5, 9, 67 };
  int c[] = { 8, 20, 76, 389, 399 };
  int	d[] = { 266, 388, 736, 736, 3923 };
  int	e[] = { 38, 234, 1021, 7136, 39342 };

  int n6 = SIZE(a)+SIZE(b)+SIZE(c)+SIZE(d)+SIZE(e);
  int *f = new int [n6];
  k_way_merge(a, SIZE(a), b, SIZE(b), c, SIZE(c), d, SIZE(d), e, SIZE(e), f, n6);

  for  (int i=0; i<n6; ++i) {
    cout<<f[i]<<endl;
  }
  delete[] f;
  return 1;
}
