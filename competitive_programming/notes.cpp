// my notes todat

/*

Types of initialisation

1. Direct initialisation uses ()
- no temporary objext is created
- allows narrowing conversion

2. Copt initialisation uses = 
- temoporary object is created
- then copy constructor is called

use explicit in constructor making to prevent thes ed.. Example 1




*/

// Example 1
#include <iostream>
using namespace std;

class Foo{
    int x;
public:
    explicit Foo(int x) : x{x}{}
    void print() {
        cout << x << endl;
    }

};

int main() {
    // Foo f1 = Foo(2);
    Foo f2 = 3;
    f2.print();
    return 0;
}