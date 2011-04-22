#include <iostream>
#include <hash_map>

using namespace std;
using namespace __gnu_cxx;

/**
 * go over array, sum up for all elements upto the current one. put the result in a hashmap, 
 * if any value appear more than once, there's a subarray sums to 0 
 */
void find_sub_array_sum_to_zero(int a[], int n) {
    int *s = new int[n];
    s[0] = a[0];
    hash_map<int, int> M;
    M[s[0]] = 0;
    for (int i=1; i<n; i++) {
        s[i] = s[i-1]+a[i];
        if (M.find(s[i]) != M.end()) {
            cout << "sub array found from " << M[s[i]]+1 << " to " << i << endl;
        }
        else {
            M[s[i]] = i;
        }
    }
    delete [] s;
}

int main() {
    int a[] = {-5,1,-4,1,2,1};
    find_sub_array_sum_to_zero(a, sizeof(a)/sizeof(a[0]));
    return 1;
}
