#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef vector< pair<int, int> > V;

struct comp {
    bool operator () (pair<int, int> p1, pair<int, int> p2) {
        return p1.first < p2.first;
    }
} mycomp;

void merge_overlap(V v) {
    sort(v.begin(), v.end(), mycomp);
    int s1, e1, c;
    int s2, e2;
    V v2;
    for (V::iterator it = v.begin(); it!=v.end(); it++) {
        s2 = (*it).first;
        e2 = (*it).second;
        if (it == v.begin()) {
            s1 = s2;
            e1 = e2;
            continue;
        }
        if (s2>e1) {
            v2.push_back(make_pair(s1,e1));
            s1 = s2;
            e1 = e2;
        }
        else {
            if (e2>e1) e1 = e2;
        }
    }

    v2.push_back(make_pair(s1,e1));

    for (V::iterator it = v2.begin(); it!= v2.end(); it++) {
        cout<< (*it).first << "-" << (*it).second << endl;
    }
}

int main() {
    V v;
    v.push_back(make_pair(1,3));
    v.push_back(make_pair(8,10));
    v.push_back(make_pair(2,6));
    v.push_back(make_pair(15,18));

    merge_overlap(v);
    return 1;
}
