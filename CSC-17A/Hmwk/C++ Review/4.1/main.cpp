/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on September 21, 2016, 2:52 PM
 * Purpose:  C++ Review (Gaddis_8th, 4.1)
 */

//System Libraries
#include <iostream>
using namespace std;

//Execution Begin Here!

int main(int argc, char** argv) {
    // Declare two variables in floating types.
    float num1, num2;

    // Enter the first number
    cout << "Enter the first number in your mind: ";
    cin >> num1;

    // Enter the second number
    cout << "Enter the second number in your mind (different with the first one): ";
    cin >> num2;

    // Use conditional operator to compare two numbers
    num1 > num2 ? (cout << "The first number you entered is larger than the second one.") : (cout << "The first number you entered is smaller than the second one.");
    
    //Exit stage right!
    return 0;
}