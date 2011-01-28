/**
 * http://en.wikipedia.org/wiki/Suffix_array 
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

string s;

int compare(const void *a, const void *b) {
    int len = s.size();
    int i1 = *(int *)a;
    int i2 = *(int *)b;
    string s1 = s.substr(i1, len-i1);
    string s2 = s.substr(i2, len-i2);
    return s1>s2;
    // return s1.compare(s2);
}

void buildSuffixArray(string s, int *suffix, int n) {
    for (int i=0; i<n; ++i) {
        suffix[i] = i;
    }
    qsort(suffix, n, sizeof(int), compare);
}

int isASubstringOfB(string a, string b, int *suffix, int n) {
    if (a.size() > b.size()) return -1;
    int len_a, len_b, len;
    len_a = a.size();
    len_b = b.size();
    int l, r, m, idx;
    l = 0;
    r = n-1;
    while(r>=l) {
        m = l + (r-l)/2;
        idx = suffix[m];
        if (idx+len_a>len_b) return -1;
        string t = b.substr(idx,len_a);
        if (t==a) return idx;
        if (a>t) l=m+1;
        else r=m-1;
    }
    return -1;
}

int main() {
    cin>>s;
    string s2 = s;
    s+="$";
    reverse(s2.begin(), s2.end());
    s = s+s2;
    int n = s.size();
    int *suffix = new int[n];
    buildSuffixArray(s, suffix, n);

    for (int i=0; i<n; ++i) {
        // cout<<suffix[i]<<endl;
        cout<<suffix[i]<<"-"<<s.substr(suffix[i],n-suffix[i])<<endl;
    }

    // string a;
    // cin>>a;
    // cout << isASubstringOfB(a, s, suffix, n) << endl;

    delete [] suffix;
    return 1;
}
