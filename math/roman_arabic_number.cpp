/**
 * http://en.wikipedia.org/wiki/Roman_numerals
 *
 * You can use M,C,X and I three times,but you can't do that with D, L and V.
 * largest ROMAN number 
 *
 * without overline: 
 * MMMDCCCLXXXVIII 3888
 * MMMCM
 *
 */

#include <iostream>
#include <string.h>

using namespace std;

string decimal2roman(int x) {
    string ret;
    string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X",
        "IX", "V", "IV", "I"};
    int dec[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    for (int i=0; i<13; ++i) {
        while (x>=dec[i]) {
            ret+=roman[i];
            x-=dec[i];
        }
    }
    return ret;
}

int main() {
    int x;
    while(cin>>x && x!= -1) {
        cout << decimal2roman(x) << endl;
    }
    return 1;
}
