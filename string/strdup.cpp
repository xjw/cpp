#include <iostream>

using namespace std;

char *strdup (const char *s) {
  char *d = (char *)malloc(strlen(s)+1);
  if (d != NULL) {
    strcpy(d, s);
  }
  return d;
}

int main() {
  return 1;
}
