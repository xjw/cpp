#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>

using namespace std;

int char_comparator(const void* e1, const void* e2) {
  return *(char *)e1 - *(char *)e2;
}

string string_sort(string s) {
  qsort(&s[0], s.size(), sizeof(char), char_comparator);
  return s;
}

bool isvalidPartition(string s) {
  for (int i=0; i<s.size(); ++i) {
    if (s.substr(0, i) && s.substr())
  }
}

int main() {
  // qsort(in, strlen(in), sizeof(char), char_comparator);
  // cout<<in<<endl;

  // char d1[] = "hello";
  // char d2[] = "world";
  // char d3[] = "hi";
  // char d4[] = "dog";
  // char d5[] = "cat";
  // qsort(d1, strlen(d1), sizeof(char), char_comparator);
  // qsort(d2, strlen(d2), sizeof(char), char_comparator);
  // qsort(d3, strlen(d3), sizeof(char), char_comparator);
  // qsort(d4, strlen(d4), sizeof(char), char_comparator);
  // qsort(d5, strlen(d5), sizeof(char), char_comparator);

  string dict[]= {"hello","world","hi","dog","cat"};
  int n = sizeof(dict)/sizeof(dict[0]);
  map<string, string> d;
  for (int i=0; i<n; ++i) {
    string s = dict[i];
    d[string_sort(s)] = s;
  }

  string input = "hlleowlord";
  for (int i=0; i<input.size(); ++i) {
    string s = input.substr()
  }

  return 1;
}
