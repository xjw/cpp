/**
 * Algorithms for Permutations and Combinations
 * http://www.cs.utexas.edu/users/djimenez/utsa/cs3343/lecture25.html 
 */
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

//////////////////////////////////////////////////////////////////////
// first solution from careercup book

string insert_into_string(char ch, string s, int pos) {
  if (pos < 0 || pos > s.size()) return "";
  string front = s.substr(0,pos);
  string back = s.substr(pos);
  return front + ch + back;
} 

vector<string> getPermutation(string s) {
  vector<string> v;

  if (s.empty()) {
    v.push_back("");
    return v;
  }

  char first = s.at(0);
  string remain = s.substr(1);
  vector<string> words = getPermutation(remain);

  for(vector<string>::iterator it=words.begin(); it!=words.end(); ++it) {
    for (int i=0; i<=(*it).size(); ++i) {
      v.push_back(insert_into_string(first, *it, i));
    }
  }

  return v;
}

/////////////////////////////////////////////////////////////////////////
// A much better solution from http://geeksforgeeks.org/?p=767
// which uses backtracking

void swap(char &a, char &b) {
  char c = a;
  a = b;
  b = c;
}

void printPermutation(string s, int start, int n) {
  if (start>=n) { 
    cout<<s<<endl;
    return;
  }
  for (int i=start; i<n; ++i) {
    if (s[i]==s[start] && (i!=start)) continue; // skip duplicate case
    swap(s[start], s[i]);
    printPermutation(s, start+1, n);
    swap(s[start], s[i]); //backtrack
  }
}
////////////////////////////////////////

// random generate permutation
void randPermutation(string s) {
  srand(time(NULL));
  int n = s.size();
  for (int i=n-1; i>0; i--) {
    int j = rand() % (i+1);
    char t = s[i];
    s[i] = s[j];
    s[j] = t;
  }
  cout<<s<<endl;
}


int main() {
  string s = "133";
  // randPermutation(s);
  printPermutation(s,0,s.size());
  // vector<string> v = getPermutation(s);
  // for(vector<string>::iterator it=v.begin(); it!=v.end(); ++it) {
    // cout<<*it<<endl;
  // }
  return 1;
}
