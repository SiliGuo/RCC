// Pointer Demo 5/19/16
// Compiled with C++ 11 Standard
// Make sure to have the compiler use the -std=c++11 command line option
#include <iostream>
using namespace std;

int main() {
    short *p = nullptr; // nullptr is part of C++ 11 Standard

    short arr[] = {34, 54, 32, 12}; // , 65, 45, 31, 134, 254, 332, 412, 565, 645, 731};

    cout << "Address of array:" << &arr << endl;
    cout << "sizeof(short): " << sizeof (short) << endl;
    cout << "sizeof(arr): " << sizeof (arr) << endl;

    // number of elements in implicitly declared array
    int ele = sizeof (arr) / sizeof (short);

    p = arr; // set pointer p to address of array
//    cout << "Address pointed by p: " << p << " (this is arr[0]), contains the value: ";
//    cout << *p << endl;

    for (int i; i < ele; i++) {
        cout << "Address pointed by p: " << p << "(this is arr[";
        cout << i << "]), contains the value: ";
        cout << *p++ << endl;

        p++;
    }
    return 0;
}