/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on September 20, 2016, 0:36 PM
 * Purpose:  C++ Review (Gaddis_8th, 4.10)
 */

//System Libraries
#include <iostream>
using namespace std;

//Execution Begin Here!

int main(int argc, char** argv) {
    //Declare two variables in floating point
    int month, year;

    //Input data
    cout << "Enter a month (1-12): ";
    cin >> month;
    cout << "Enter a year: ";
    cin >> year;

    // declare a variable of boolean that represent the leap years
    bool leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);

    // use if statement to separate choice by month, and output the days on screen 
    if (month == 2) {
        // if it is leap year, output 29 days, otherwise output 28 days.
        if (leap == true) {
            cout << "29 days" << endl;
        } else {
            cout << "28 days" << endl;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        cout << "30 days" << endl;
    } else {
        cout << "31 days" << endl;
    }

    //Exit stage right!
    return 0;
}