/* 
 * File:   main.cpp
 * Author: siliguo
 *
 * Created on November 18, 2016, 12:31 AM
 */

#include <iostream>
#include <string>
using namespace std;

#include "Number.h"

int main(int argc, char** argv) {

    int number;

    //Prompt number from user
    do {
        cout << "Please enter a integer number between 0 to 9999: ";
        cin >> number;
        //Check invalidation
        if (number < 0 || number > 9999) cout << "Invalid input! Please enter a number in range (0~9999)." << endl;
    } while (number < 0 || number > 9999);

    //Create an object in class
    Number result(number);
    
    Number::print();
    
    return 0;
}

