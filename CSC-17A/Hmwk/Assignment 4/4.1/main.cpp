/* 
 * File:   main.cpp
 * Author: siliguo
 *
 * Created on November 16, 2016, 1:29 AM
 */

#include <iostream>
using namespace std;

#include "Date.h"

int main(int argc, char** argv) {

    //Declare variables
    int year, month, day;

    //Promote year from user
    cout << "Please enter the year: ";
    cin >> year;
    cout << endl;

    //Promote month from user
    do {
        cout << "Please enter the month: ";
        cin >> month;
        //Check validation
        if (month < 1 || month > 12) {
            cout << "Invalid input for month! Please enter again." << endl;
        }
    } while (month < 1 || month > 12);
    cout << endl;

    //Promote day from user
    bool valid = true;
    int max[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    do {
        valid = true;
        cout << "Please enter the day: ";
        cin >> day;
        //Check validation
        if (day < 1 || day > max[month - 1]) valid = false;
        if (month == 2 && day == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 == 0))) valid = true;
        if (!valid) {
            cout << "Invalid input for day! Please enter again" << endl;
        }
    } while (!valid);
    cout << endl;
    
    //Store value in variables
    Date date(year, month, day);
    
    //Output result
    cout << "The date you input is: " << endl;
    date.output();
    
    return 0;
}

