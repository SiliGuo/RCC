// Pointer Demo 3 5/19/16
// Compiled with C++ 11 Standard
// Make sure to have the compiler use the -std=c++11 line option
#include <iostream>
using namespace std;

void sum(int, int, int *);

int main() {
    int x = 5, y = 3, z;

    cout << x << ", " << y << ", " << z << endl;
    sum(x, y, &z);
    cout << x << ", " << y << ", " << z << endl;

    return 0;
}

void sum(int a, int b, int *z) {
    *z = a + b;
}