#include <iostream>
#include <vector>

using namespace std;
#define ARRAY(x, y) (a[x+n*y])

typedef vector<int> V1D;
typedef vector<V1D> V2D;

void multiDPrint(int **a, int m, int n) {
  for (int i=0; i<n; ++i) {
    for (int j=0; j<m; ++j) {
      cout<<a[i][j];
    }
    cout<<endl;
  }
  cout<<endl;
}

void multiDPrint2(int *a, int m, int n) {
  for (int i=0; i<n; ++i) {
    for (int j=0; j<m; ++j) {
      cout<<ARRAY(i,j);
    }
    cout<<endl;
  }
  cout<<endl;
}

void multiDInitArray1(int m, int n) {
  int **a;
  a = new int*[n];
  for (int i=0; i<n; ++i) {
    a[i] = new int[m];
  }
  multiDPrint(a, m, n);
  for (int i=0; i<n; ++i) {
    delete [] a[i];
  }
  delete [] a;
}

void multiDInitArray2(int m, int n) {
  int *a = new int[m*n];
  multiDPrint2(a, m, n);
  delete [] a;
}

void multiDInitVector1(int m, int n) {
  V2D v(n,V1D(m,0));
  for(V2D::iterator it=v.begin(); it!=v.end(); ++it) {
    V1D v1 = *it;
    for (V1D::iterator it1=v1.begin(); it1!=v1.end(); ++it1) {
      cout<<*it1;
    }
    cout<<endl;
  }
  cout<<endl;
}

void multiDInitVector2(int m, int n) {
  vector<vector<int> > v(n, vector<int>(m,0));
  for(vector<vector<int> >::iterator it1 = v.begin(); it1!=v.end(); ++it1) {
    vector<int> v2 = *it1;
    for (vector<int>::iterator it2=v2.begin(); it2!=v2.end(); ++it2) {
      cout<<*it2;
    }
    cout<<endl;
  }
  cout<<endl;
}

int main() {
  int m, n;
  m=3;
  n=3;
  multiDInitArray1(m, n);
  multiDInitArray2(m, n);
  multiDInitVector1(m, n);
  multiDInitVector2(m, n);
  return 1;
}
