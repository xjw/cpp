#include <iostream>
#include <string.h>
using namespace std;

bool testAnagram(char *a, char *b) {
  if (strlen(a) != strlen(b)) {
    cout<<"len not equal"<<endl;
    return false;
  }

  int *charCount = new int[256];
  int uniqueChar=0;

  for(int i=0; i<strlen(a); i++) {
    int index = int(a[i]);
    if (charCount[index] == 0) {
      uniqueChar++;
    }
    charCount[index]++;
  }

  // for (int i=0;i<sizeof(charCount)/sizeof(int);i++) {
    // cout<<charCount[i];
  // }
  // cout<<endl;

  for(int j=0; j<strlen(b); j++) {
    int index = b[j];
    cout<<"current count:"<<charCount[index]<<endl;
    if (charCount[index] == 0) {
      cout<<"index=0"<<endl;
      return false;
    }
    charCount[index]--;
    if (charCount[index] == 0) {
      uniqueChar--;
    }

    if (uniqueChar<0) {
      cout<<"num of unique chars does not match"<<endl;
      return false;
    }
  }

  cout<<uniqueChar<<endl;
  cout<<"works"<<endl;
}

int main() {
  // int a[3];
  // char b = 'c';
  // a[b]=5;
  // for (int i=0;i<sizeof(a)/sizeof(int);i++) {
    // cout<<a[i]<<endl;
  // }
  // cout<<int(b);
  // cout<<a[b]<<endl;
  testAnagram("abbacd", "aabbcf");
  return 0;
}
