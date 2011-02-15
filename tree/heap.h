/**
 * http://sites.google.com/site/indy256/algo-en/binary_heap 
 */

#include <iostream>
using namespace std;

class heap {
    int *H;
    int SIZE;
    int idx;
 public:
    heap(int n);
    ~heap();
    bool empty();
    int top();
    void pop();
    void push(int data);
    void siftup(int pos);
    void siftdown(int pos);
};

heap::heap(int n) {
    try {
        SIZE = n;
        H = new int[SIZE];
        idx = 0;
        if (!H)
            throw "new failed";
    }
    catch (char *e){
        cout << "exception raised" << e << endl;
    }
}

heap::~heap() {
    if (H)
        delete [] H;
}

void heap::siftup(int pos) {
    int cur = pos;
    while(cur>0) {
        int parent = (cur-1)/2;
        if (H[cur]>=H[parent]) break; 
        swap(H[cur], H[parent]);
        cur = parent;
    }
}

void heap::siftdown(int pos) {
    int cur = pos;
    while(cur<idx/2) {
        int child = cur*2+1;
        if (child<idx-1 && H[child]>H[child+1]) child++; 
        if (H[cur]<H[child]) break;
        swap(H[cur], H[child]);
        cur = child;
    }
}

void heap::push(int data) {
    if (idx>=SIZE)
        throw "stack full";
    else {
        H[idx] = data;
        siftup(idx);
        idx++;
    }
}

bool heap::empty() {
    return idx==0;
}

int heap::top() {
    if (empty()) throw "empty";
    else return H[0];
}

void heap::pop() {
    if (empty()) throw "empty";
    H[0] = H[--idx]; //mmmmmmmmmade mistake........
    siftdown(0);
}
