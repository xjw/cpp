/**
 * http://www.cplusplus.com/doc/tutorial/typecasting/ 
 */

#include <iostream>

using namespace std;

class A {
 public:
    int a;
    virtual void dummp() {} // first mistake, virtual function is necessary for polymorphic 
};

class B : public A { // second mistake inherit public
    int b;
};

/*
	int a = 7;
	double* p1 = (double*) &a;			// ok (but a is not a double)
	double* p2 = static_cast<double*>(&a);	// error
	double* p2 = reinterpret_cast<double*>(&a);	// ok: I really mean it

	const int c = 7;
	int* q1 = &c;			// error
	int* q2 = (int*)&c;		// ok (but *q2=2; is still invalid code and may fail)
	int* q3 = static_cast<int*>(&c);	// error: static_cast doesn't cast away const
	int* q4 = const_cast<int*>(&c);	// I really mean it
    */

int main() {
    A a;
    B b;
    try {
        A *a = new A;

        A *b = new B; 
        // if no virtual function defined in A
        // error: cannot dynamic_cast ‘a’ (of type ‘class A*’) to type 
        // ‘class B*’ (source type is not polymorphic)

        B *c;
        c = dynamic_cast<B*>(a); // run time check to make sure completeness of object
        if (!c) cout << "null pointer on a->c" << endl;
        c = dynamic_cast<B*>(b);
        if (!c) cout << "null pointer on b->c" << endl;
        else cout << "succeed in casting b->c" << endl;
    }
    catch (exception& e) {
        cout << "Exception: " << e.what(); 
    }
    return 1;
}
