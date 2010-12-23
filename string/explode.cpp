#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <stack>

using namespace std;

vector<string> explode(const string &str, const char ch) {
  string next = "";
  vector<string> v;

  for (string::const_iterator it = str.begin(); it != str.end(); ++it) {
    if (*it == ch) { 
      if (!next.empty()) v.push_back(next);
      next = "";
    }
    else {
      next += *it;
    }
  }

  if (!next.empty()) v.push_back(next);

  return v;
}

string getDir(string s, char d) {
  stack<string> st;
  string buf = "";
  for (string::iterator it=s.begin(); it!=s.end(); ++it) {
    if (*it != d) buf += *it;
    if (*it == d) {
      if (buf == ".." && !st.empty()) {
        st.pop();
      }
      else if (buf != "." && !buf.empty()) {
        st.push(buf);
      }
      buf = "";
    }
  }
  while(!st.empty()) {
    cout<<st.top()<<endl;
    st.pop();
  }
  return "";
}

vector<string> explode_using_getline(const string &str, const char ch) {
  vector<string> v;
  stringstream ss (str);
  string s;
  while (getline(ss, s, ch)) {
    v.push_back(s);
  }
  return v;
}

vector<string> explode_using_strtok(const string &str, char ch) {
  vector<string> v;
  char *cp = new char[str.size()+1];
  char delimiter[] = "\\";
  strcpy(cp, str.c_str());

  char *p = strtok(cp, delimiter);
  while (p) {
    string s = p;
    v.push_back(s);
    p = strtok(NULL, delimiter);
  }

  delete cp;
  return v;
}

int main() {
  // string s = "c:\\windows\\level";
  string s;
  while(cin>>s && s !="z") {
    cout<<getDir(s,'\\')<<endl;
  }
  return 1;
}
