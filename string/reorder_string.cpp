#include <iostream>
#include <string.h>

using namespace std;

const int N=256;

void reorder_string(char * s, const char * m) {
    bool flag[N];
    int count[N];
    memset(count, 0, N*sizeof(int));
    memset(flag, 0, N*sizeof(bool));
    int i,j;
    int m_len = strlen(m);
    int s_len = strlen(s);

    for (i=0; i<m_len; i++)
        flag[m[i]] = true;
    for (i=0; i<s_len; i++) {
        if (flag[s[i]]) count[s[i]]++;
    }

    for (i=j=s_len; i>=0; i--) {
        if (!flag[s[i]]) s[j--]=s[i];
    }
    for (i=j=0; i<m_len; i++) {
        if (count[m[i]])
            memset(s+j, m[i], count[m[i]]);
        j += count[m[i]];
    }
}

int main() {
    char s[] = "ABBFKCEDG";
    const char m[] = "BAC";
    reorder_string(s, m);
    cout << s << endl;
    return 1;
}
