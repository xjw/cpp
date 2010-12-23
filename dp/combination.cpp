#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>

using namespace std;

int cccc=0;

void printCombination(int a[], int n) {
  n = pow(2, n);
  for (int i=1; i<n; i++) {
    int k=0;
    int j=i;
    while(j) {
      if (j&1) cout<<a[k];
      k++;
      j>>=1;
    }
    cout<<endl;
  }
}

void printCombination2(string s, string c, int start) {
  if (start >= s.length()) return;
  for (int i=start; i<s.length(); ++i) {
    string c1 = c;
    c += s.at(i);
    cout<<c<<endl;
    printCombination2(s, c, i+1);
    c = c1;
  }
}

///////////////////////////////////////////////////////////////////
// second time coding

void printVector(vector<int> v) {
  if (!v.empty()) {
    for (vector<int>::iterator it = v.begin(); it!=v.end(); ++it) {
      cout<<*it<<" ";
    }
    cout<<endl;
  }
}

/**
 * time cost 2^n 
 */
void printAllSubsetRecursive(vector<int> v, int a[], int start, int n) {
  if (start>=n) return;
  for (int i=start; i<n; ++i) {
    vector<int> v1(v);
    v.push_back(a[i]);
    printVector(v);
    printAllSubsetRecursive(v, a, i+1, n); // made a big mistake here!!!!
    v = v1;
  }
}

/**
 * time cost 2^n * k 
 */
void printAllSubsetIterative(int a[], int n) {
  int count = pow(2, n);
  for(int i=1; i<count; ++i) {
    for (int j=i, k=0; j>0; k++, j>>=1) {
      if (j & 1) cout<< a[k] << " ";
      cccc++;
    }
    cout<<endl;
  }
}

int main() {
  int a[] = {1, 2, 3};
  int n = sizeof(a)/sizeof(a[0]);
  vector<int> v;
  printCombination(a, n);
  printAllSubsetIterative(a, n);
  printAllSubsetRecursive(v, a, 0, n);

  string s = "abc";
  string c;
  printCombination2(s, c, 0);
  cout<<endl<<cccc<<endl;
  return 1;
}
