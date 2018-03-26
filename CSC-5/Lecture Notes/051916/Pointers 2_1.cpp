// Pointer Demo 5/19/16
// Compiled with C++ 11 Standard
// Make sure to have the compiler use the -std=c++11 command line option
#include <iostream>
using namespace std;

int main(){
    long double *p = nullptr; // nullptr is part of C++ 11 Standard
    
    long double arr[] = { 34,54,32,12,65,45,31 };
    
    cout << "Address of array:" << &arr << endl;
    cout << "sizeof(long double): " << sizeof(long double) << endl;
    cout << "sizeof(arr): " << sizeof(arr) << endl;
    
    p=arr; // set pointer p to address of array
    cout << "Address pointed by p: " << p << " (this is arr[0]), contains the value: ";
    cout << *p << endl;
    
    p++;
//    p=arr+1; // set pointer p to address of arr[1]
    cout << "Address pointed by p: " << p << " (this is arr[1]), contains the value: ";
    cout << *p << endl;
    
    p++;
//    p=arr+2; // set pointer p to address of arr[2]
    cout << "Address pointed by p: " << p << " (this is arr[2]), contains the value: ";
    cout << *p << endl;
    
    return 0;
}