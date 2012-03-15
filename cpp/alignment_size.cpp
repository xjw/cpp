#include <iostream>

using namespace std;

struct S {
    char a;
    int b;
    void *c;
    long long d;
};

int main() {
    cout << sizeof(S) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(void *) << endl;
    cout << sizeof(size_t) << endl;
    cout << sizeof(long) << endl;
    
    return 1;
}
