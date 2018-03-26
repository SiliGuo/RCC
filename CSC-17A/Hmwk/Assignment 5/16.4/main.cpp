/* 
 * File:   main.cpp
 * Author: siliguo
 *
 * Created on December 5, 2016, 10:37 PM
 */

#include <iostream>
using namespace std;

#include "Absolute.h"

int main(int argc, char** argv) {
    
    //Declare a variable
    int number;
    
    //Promote number from user
    cout << "Please enter a number you like: ";
    cin >> number;
    
    //Output the result
    cout << "The absolute value of  the number you entered is:  " << absolute(number) << endl;

    return 0;
}

