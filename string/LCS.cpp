#include <iostream>

using namespace std;

string longestCommonSubstring(string a, string b) {
  int m = a.size();
  int n = b.size();
  int max_len = 0;
  int max_i = 0;


  int **x = new int*[n];
  x[0] = new int[m*n];
  for (int i=1; i<n; ++i) {
    x[i] = x[i-1]+m;
  }

  int i,j;

  for (i=0; i<n; ++i) {
    for (j=0; j<m; ++j) {
      if (a[j] == b[i]) {
        if (i>0 && j>0) {
          x[i][j] = x[i-1][j-1]+1;
        }
        else {
          x[i][j] = 1;
        }
        if (x[i][j]>max_len) {
          max_len = x[i][j];
          max_i = i;
        }
      }
      else 
        x[i][j] = 0;
    }
  }

  cout<<endl;
  for (int i=0; i<n; ++i) {
    for (int j=0; j<m; ++j) {
      cout<<x[i][j];
    }
    cout<<endl;
  }
  cout<<endl;

  return b.substr(max_i-max_len+1, max_len);


  delete[] x[0];
  delete[] x;
    
  return "";
}

int main() {
  string a,b;
  cin>>a;
  cin>>b;
  cout<<"longest common substring is "<<longestCommonSubstring(a,b)<<endl;

}
