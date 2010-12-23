#include <iostream>
#include <string.h>
using namespace std;

void removeDuplicates(char *str) {
  if (str == NULL) return;
  int len = strlen(str);
  if (len < 2) return;

  int tail = 1;

  for (int i = 1; i < len; ++i) {
    int j;
    // find the position where duplicate are found
    for (j = 0; j < tail; ++j) {
      if (str[i] == str[j]) break;
    }
    cout<<"i is----"<<i<<endl;
    cout<<"j is----"<<j<<endl;
    cout<<"tail is-"<<tail<<endl;
    // only increase tail when j is tail
    // which means we need to copy over
    if (j == tail) {
      str[tail] = str[i];
      ++tail;
      cout<<"new tal-"<<tail<<endl;
      cout<<"new str-"<<str<<endl;
    }
    cout<<"------------"<<endl;

  }
  str[tail] = 0;
}

void removeDuplicates2(char *str) {
  if (NULL != str && '\0' != *str) {
    int prevIndex = 1;
    int len = strlen(str);
    for (int i=1; i<len; i++) {
      bool foundDup = false;
      for (int j=0; j<i; j++) {
        if (str[i] == str[j]) {
          foundDup = true;
          break;
        }
      }
      if (foundDup == false) {
        str[prevIndex++] = str[i];
      }
    }
    str[prevIndex] = '\0';
    cout<<str<<endl;
  }
}

void removeDuplicatesWithLittleSpace(char *str) {
  if (NULL == str || strlen(str)<=1) return;

  bool *hit = new bool[256];
  for (int i=0; i<255; i++) {
    cout<<hit[i];
  }
  cout<<endl;
  int len  = strlen(str);
  int tail = 0;

  for (int i=0; i<len; i++) {
    if (!hit[str[i]]) {
      hit[str[i]] = true;
      str[tail++] = str[i];
    }
  }

  str[tail] = '\0';
  cout<<str<<endl;
}

void encode(char *str) {

}


int main() {
  char a[100];
  cin>>a;
  cout<<"str is----"<<a<<endl;
  cout<<"------------"<<endl;
  removeDuplicatesWithLittleSpace(a);
  return 0;
}
