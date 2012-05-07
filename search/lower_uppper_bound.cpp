/**
 * http://www.cplusplus.com/reference/algorithm/upper_bound/ 
 * http://www.cplusplus.com/reference/algorithm/equal_range/
 * http://stackoverflow.com/questions/446296/where-can-i-get-a-useful-c-binary-search-algorithm
 * http://www.mitbbs.com/article_t/JobHunting/31730553.html
 *
 * notice the difference lower_bound vs upper_bound
 * lower_bound 1st one = x
 * upper_bound 1st one > x
 * if (lower_bound == upper_bound) then x does not exist
 */

#include <iostream>
// #include <algorithm>
#include <vector>

using namespace std;

int my_lower_bound(int a[], int n, int x) {
  int l, r, m;
  l = 0;
  r = n-1;
  while(r>=l) {
    m = l + (r-l)/2;
    if (a[m]<x) l = m+1;
    else r = m-1;
  }
  return l;
}

/**
 * not exactly the same !!!!! with above 
 * NONONOONONO THEY ARE NOT THE SAME
 *
 * BUT THE ONLY DIFFERENCE IS THE LARGEST RETURN
 * THIS ONE RETURN n-1 at most
 * THE ONE ABOVE RETURN n!!!!!!!!!!!!!!!!
 */
int my_lower_bound_2(int a[], int n, int x) {
  int l, r, m;
  l = 0;
  r = n-1;
  while(r>l) {
    m = l + (r-l)/2;
    if (a[m]<x) l = m+1;
    else r = m;
  }
  return l;
}

int my_upper_bound(int a[], int n, int x) {
  int l, r, m;
  l = 0;
  r = n-1;
  while(r>=l) {
    m = l + (r-l)/2;
    if (a[m]>x) r = m-1;
    else l = m+1;
  }
  return l;
}

/////////////
// from most recent

int lower_bound(int a[], int n, int x) {
    int l, u, m;
    l = 0;
    u = n-1;
    while(l<u) {
        m = l + (u-l)/2;
        if (a[m]<x) l = m+1;
        else u = m;
    }
    return l;
}

int upper_bound(int a[], int n, int x) {
    int l, u, m;
    l = 0;
    u = n-1;
    while(l<u) {
        m = l + (u-l)/2;
        if (a[m]>x) u=m;
        else l=m+1;
    }
    return l;
}


int main() {
  int a[] = {1,1,2,2,2,3,3,3,3,3,3, 3, 4, 4, 5, 6, 6};
  // int a[] = {1, 1, 3};
  // int a[] = {1, 2, 3};
  // int a[] = {1, 2};
  // int a[] = {1};
  int n = sizeof(a)/sizeof(a[0]);

  vector<int> v(a, a+n);
  int x;
  while(cin>>x && x!= -1) {
    // cout<<my_lower_bound(a, n, x)<<endl;
    // cout<<my_lower_bound_2(a, n, x)<<endl;
    cout<<lower_bound(a, n, x)<<endl;
    cout<<upper_bound(a, n, x)<<endl;
    // cout<<int(lower_bound(v.begin(), v.end(), x) - v.begin())<<endl;
    // cout<<my_upper_bound(a, n, x)<<endl;
    // cout<<int(upper_bound(v.begin(), v.end(), x) - v.begin())<<endl;
    cout<<endl;
  }

  return 1;
}
