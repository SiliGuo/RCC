/* 
 * File:   main.cpp
 * Author: siliguo
 *
 * Created on December 5, 2016, 9:32 PM
 */

#include <iostream>
using namespace std;

#include "min_max.h"

int main(int argc, char** argv) {
    
    //Declare variables
    int num1, num2;
    
    //Promote user to enter two numbers
    cout << "Please enter two numbers: ";
    cin >> num1 >> num2;
    
    //Compare and output the result
    cout << "The lesser number is " << minimum(num1, num2) << endl;
    cout << "The greater number is " << maximum(num1, num2) << endl;

    return 0;
}

