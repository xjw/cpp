#include <iostream>

using namespace std;

/**
 * Find minimum number of characters that need to be inserted into a 
 * string (anywhere in the string) to make it a palindrome..
 * f(abbcba) = 1
 * f(abbcbaa) =2
 */

int find_minimum_insert(string s) {
    if (s.empty() || s.length()==1) return 0;
    int len = s.length();
    if (s[0]==s[len-1]) 
        return find_minimum_insert(s.substr(1,len-2));
    else
        return 1 + min (find_minimum_insert(s.substr(1)), 
                find_minimum_insert(s.substr(0, len-1)));
}

int main() {
    string s;
    cin>>s;
    cout << find_minimum_insert(s) << endl;
    return 1;
}
