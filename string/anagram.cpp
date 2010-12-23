#include <iostream>
#include <string.h>

using namespace std;

bool isAnagram(char *str) {
  char *end = str + strlen(str) - 1;
  while(end>str) {
    cout<<*end<<endl;
    cout<<*str<<endl;
    if (*end-- != *str++) return false;
  }
  return true;
}

bool isAnagram(char *str1, char *str2) {
  int l1 = strlen(str1);
  int l2 = strlen(str2);
  if (l1 != l2) return false;
  for (int i=0; i<l1; ++i) {
    if (str1[i] != str2[l1-i-1]) return false;
  }
  return true;
}

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
  char str1[50];
  char str2[50];
  cin>>str1;
  cin>>str2;
  if (isAnagram(str1, str2)) {
    cout << "yes" << endl;
  }
  else {
    cout << "no" << endl;
  }
  testAnagram("abbacd", "aabbcf");
  return 1;
}
