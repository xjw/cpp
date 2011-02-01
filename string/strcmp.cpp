#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

int mystrcmp(const char *str1, const char *str2) {
    assert (str1 && str2);
    while(*str1 && *str2 && *str1==*str2) {str1++; str2++;}
    if (*str1 == *str2) return 0;
    else if (*str1 > *str2) return 1;
    else return -1;
}

int main() {
    char a[50];
    char b[10];
    cin>>a;
    cin>>b;
    cout << strcmp(a, b) << endl;
    cout << mystrcmp(a, b) << endl;
    return 1;
}
