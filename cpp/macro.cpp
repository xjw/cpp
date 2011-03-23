#include <iostream>

using namespace std;

// #define square(x) (x*x)
#define square(x) (x)*(x) // solve square(x)*(x)

int main() {
    int x = 2;
    cout << square(x) << endl;
    cout << square(x+1) << endl;
    cout << square(x++) << endl; //double incremented, can't be prevented using macro
    cout << x << endl;
    return 1;
}
