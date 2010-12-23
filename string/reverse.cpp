#include <iostream>
#include <string.h>

using namespace std;

void reverse_words(char *str) {
  char *end = str + strlen(str) - 1;
  while(end>str) {
    char temp = *str;
    *str++ = *end;
    *end-- = temp;
  }
}

void reverse_words(char *start, char *end) {
  while(end>start) {
    char temp = *start;
    *start++ = *end;
    *end-- = temp;
  }
}

void reverse_sentence(char *str) {
  reverse_words(str);
  char *start, *end=str;
  while(*end) {
    if (*end != ' ') {
      start = end;
      while(*end && *end != ' ') end++;
      end--;
      reverse_words(start, end);
    }
    end++;
  }
}

int main() {
  char a[100];
  cin.getline(a,100);
  reverse_sentence(a);
  cout<<a<<endl;
  return 1;
}
