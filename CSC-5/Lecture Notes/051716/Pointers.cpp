// discussion on chapter 9 - pointers
#include <iostream>
using namespace std;

int main()
{
    int x = 12345; // x is assigned the value of 12345
    long a = 123; // a is assigned the value of 123
    int *ptr_x = &x;
    
    char y = 'a'; // y is assigned the value of 'a'
    char z = 'z'; // z is assigned the value of 'z'
    float f = 3.14; // f is assigned the value of 3.14
    
    // output ptr_x
    cout << "Value of ptr_x: " << (long)ptr_x << ", located at address: ";
    cout << (long)&ptr_x << ", " << sizeof(ptr_x) << " bytes in size." << endl;
    cout << "The content of address " << ptr_x << " is: " << *ptr_x << endl;
    
    // output the value of x, and also output the address of x, and size of x.
    cout << "Value of x: " << x << ", located at address: ";
    cout << (long)&x << ", " << sizeof(x) << " bytes in size." << endl;
    
    // output the value of y, and also output the address of y, and size of y.
    cout << "Value of y: " << y << ", located at address: ";
    cout << (long)&y << ", " << sizeof(y) << " bytes in size." << endl;
    
    // output the value of z, and also output the address of z, and size of z.
    cout << "Value of z: " << z << ", located at address: ";
    cout << (long)&z << ", " << sizeof(z) << " bytes in size." << endl;
    
     // output the value of a, and also output the address of a, and size of a.
    cout << "Value of a: " << a << ", located at address: ";
    cout << (long)&a << ", " << sizeof(a) << " bytes in size." << endl;
    
     // output the value of f, and also output the address of f, and size of f.
    cout << "Value of f: " << f << ", located at address: ";
    cout << (long)&f << ", " << sizeof(f) << " bytes in size." << endl;
    
    for(int i=0;i<32;i++)
    {
        cout << long(ptr_x+i) << ": " << *(ptr_x+i) << endl;
    }
    
    return 0;
}