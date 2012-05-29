#include <iostream>
/*
 * http://olehuisha.wordpress.com/2011/04/06/wild-char-match/
 */
bool isMatch(const char *s, const char *p) {
    // Written by Jack Handy - jakkhandy@hotmail.com
    const char *cp = NULL, *mp = NULL;

    while ((*s) && (*p != '*')) {
        if ((*p != *s) && (*p != '?')) {
            return 0;
        }
        p++;
        s++;
    }

    while (*s) {
        if (*p == '*') {
            if (!*++p) {
                return 1;
            }
            mp = p;
            cp = s+1;
        } else if ((*p == *s) || (*p == '?')) {
            p++;
            s++;
        } else {
            p = mp;
            s = cp++;
        }
    }

    while (*p == '*') {
        p++;
    }
    return !*p;
}

int main() {

}

