// Pointer Demo 3 5/19/16
// Compiled with C++ 11 Standard
// Make sure to have the compiler use the -std=c++11 line option
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void sum(int, int, int *);
int input_integer();

int main() {
    int x, y = 2, z;

    //char s[100];
    char *s="12345";
    
    cout << "Enter a value for X: ";
    x = input_integer();

    //cout << "*s contains: " << s << endl;

    // try to convert to integer
    x = atoi(s);

    sum(x, y, &z);
    cout << x << ", " << y << ", " << z << endl;

    return 0;
}

int input_integer() {
    // get an integer from the user and check for invalid characters
    // and size of the input must not be out of range of integers
    char s[100];

    cin >> s;

    //cin.getline(s,'\n');
    
    int sz = strlen(s);
    
    cout << s << " has " << sz << " characters." << endl;

    return 0;
}

void sum(int a, int b, int *z) {
    *z = a + b;
}