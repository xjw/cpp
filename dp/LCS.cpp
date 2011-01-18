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

string longestCommonSubstringQuiz(string a, string b) {
  int m = a.size();
  int n = b.size();
  int **c = new int*[m+1];
  for (int i=0; i<=m; ++i) {
    c[i] = new int[n+1];
  }
  for (int i=0; i<=m; ++i) {
    c[i][0] = 0;
  }
  for (int j=0; j<=n; ++j) {
    c[0][j] = 0;
  }

  int max, max_i;
  max=0;
  max_i=0;

  for (int i=1; i<=m; ++i) {
    for (int j=1; j<=n; ++j) {
      int p = i-1;
      int q = j-1;
      if (a[p]==b[q]) {
        c[i][j]=c[i-1][j-1]+1;
        if (c[i][j]>max) {
          max = c[i][j];
          max_i = p;
        }
      }
      else c[i][j]=0;
    }
  }

  for (int i=0; i<=m; ++i) {
    for (int j=0; j<=n; ++j) {
      cout << c[i][j] << " ";
    }
    cout << endl;
  }

  for (int i=0; i<=m; ++i) {
    delete [] c[i];
  }
  delete [] c;

  return a.substr(max_i-max+1, max);
}

int longestCommonSubsequence(string a, string b) {
  int i, j;
  int m = a.size();
  int n = b.size();
  int **c = new int*[m+1];
  for (int i=0; i<=m; ++i) {
    c[i] = new int[n+1];
  }
  for (i=0; i<=m; ++i) {
    c[i][0] = 0;
  }
  for (j=0; j<=n; ++j) {
    c[0][j] = 0;
  }

  for (i=1; i<=m; ++i) {
    for (j=1; j<=n; ++j) {
      if (a[i-1]==b[j-1])
        c[i][j]=c[i-1][j-1]+1;
      else
        c[i][j]=max(c[i-1][j], c[j-1][i]);
    }
  }

  for (i=0; i<=m; ++i) {
    for (j=0; j<=n; ++j) {
      cout << c[i][j] << " ";
    }
    cout << endl;
  }

  int v = c[m][n];

  for (int i=0; i<=m; ++i) {
    delete [] c[i];
  }
  delete [] c;

  return v;
}

int main() {
  string a,b;
  cin>>a;
  cin>>b;
  cout<<"longest common substring is "<<longestCommonSubstring(a,b)<<endl;
  cout<<"longest common substring is "<<longestCommonSubstringQuiz(a,b)<<endl;
  cout<<"longest common subsequence len is "<<longestCommonSubsequence(a,b)<<endl;

}
