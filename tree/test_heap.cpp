#include <iostream>
#include "heap.h"

using namespace std;

int main() {
    heap hp = heap(5);
    hp.push(3);
    hp.push(1);
    hp.push(2);
    while(!hp.empty()) {
        cout << hp.top() << endl;
        hp.pop();
    }
    return 1;
}
