// Pointer Demo 3 5/19/16
// Compiled with C++ 11 Standard
// Make sure to have the compiler use the -std=c++11 line option
#include <iostream>
using namespace std;

int main() {
    // creates an array of characters
    char s[] = {'h', 'e', 'l', 'l', 'o'};
    char *p = s;

    // *p= 'Z';

    cout << p << endl; // does this output 1234? NO!
    cout << p + 1 << endl;

    return 0;
}