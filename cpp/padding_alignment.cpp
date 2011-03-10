#include <iostream>

using namespace std;

struct padding1 {
    char a;
    int b;
    char c;
};

struct padding2 {
    char a;
    char c;
    int b;
};

struct padding3 {
    int b;
    char a;
    char c;
};

int main() {
    cout << sizeof(padding1) << endl;
    cout << sizeof(padding2) << endl;
    return 1;
}
