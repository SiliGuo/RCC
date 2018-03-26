#include <iostream> // for cin, and cout
#include <iomanip> // for manipulators to handle io manipulation
using namespace std;

int main(int argc, char** argv) {
    // examples with integers
    int a=7, b=5, c = a+b;
    
    cout << "(" << setw(5) << a << ")" << endl; // set width to 5 spaces, output value of a, right justified.
    cout << "(" << setw(5) << left << a << ")" << endl; // set width to 5 spaces, output value of a, left justified.
    
    cout << endl; // extra blank line
    cout << setw(8) << right << a << endl; // set width to 8 and output the value of a
    //cout << b << endl; // output the value of b
    //cout << c << endl; // output the value of c
    cout << setw(8) << b << endl; // set width to 8 and output the value of b
    cout << setw(8) << c << endl; // set width to 8 and output the value of c
    cout << endl; // extra blank line
    
    // examples with floating point
    float pi=3.14159265;
    float x=6.354263;
    
    // demonstrate setw with floating point
    cout << "(" << setw(8) << pi << ")" << endl; // output pi with field width to 8.
    cout << "(" << setw(7) << pi << ")" << endl; // output pi with field width to 7.
    
    // same as above but with left justification
    cout << left << endl;
    cout << "(" << setw(8) << pi << ")" << endl; // output pi with field width to 8.
    cout << "(" << setw(7) << pi << ")" << endl; // output pi with field width to 7.
    cout << endl;
    
    // demonstrate setprecision, fixed, and showpoint
    // make sure we are right justified
    cout << right; // set justification back to right justified
    // next line sets width to 10, precision is 0 digits, display fixed, and show decimal point
    cout << setw(10) << setprecision(0) << fixed << showpoint << pi << endl;
    // next line sets width to 10, precision is 1 digits, display fixed, and show decimal point
    cout << setw(10) << setprecision(1) << fixed << showpoint << pi << endl;
    // next line sets width to 10, precision is 2 digits, display fixed, and show decimal point
    cout << setw(10) << setprecision(2) << fixed << showpoint << pi << endl;
    // next line sets width to 10, precision is 3 digits, display fixed, and show decimal point
    cout << setw(10) << setprecision(3) << fixed << showpoint << pi << endl;
    // next line sets width to 10, precision is 4 digits, display fixed, and show decimal point
    cout << setw(10) << setprecision(4) << fixed << showpoint << pi << endl;
    // next line sets width to 10, precision is 5 digits, display fixed, and show decimal point
    cout << setw(10) << setprecision(5) << fixed << showpoint << pi << endl;
    // next line sets width to 10, precision is 6 digits, display fixed, and show decimal point
    cout << setw(10) << setprecision(6) << fixed << showpoint << pi << endl;
    
    // next line sets width to 10, precision is 6 digits, display fixed, and show decimal point
    // "3" is an integer value, what happened?
    int three=3;
    float threePointZero=3.0;
    cout << setw(10) << setprecision(6) << fixed << showpoint << three << endl;
    // next line sets width to 10, precision is 6 digits, display fixed, and show decimal point
    cout << setw(10) << setprecision(6) << fixed << showpoint << threePointZero << endl;
    
    return 0;
}

