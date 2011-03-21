/**
 * http://www.newty.de/fpt/fpt.html 
 * http://www.newty.de/fpt/functor.html#chapter4
 */

#include <iostream>
using namespace std;

int add (int x, int y) {return x+y;}

int op (int x, int y, int (*func_p) (int, int) ) {
    return (*func_p)(x, y);
    // equal to 
    // return func_p(x, y);
}

struct functor {
    int x;
    functor(int d) : x(d) {}
    int operator() (int y) {
        return x+y;
    }
};

int main() {
    int x = 1;
    int y = 2;
    cout << op(x, y, &add) << endl;

    functor ft(x);
    cout << ft(y) << endl;
    return 1;
}
