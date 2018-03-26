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
    bool monthAgain = true;
    bool dayAgain = true;

    //Declare a variable of Date class
    Date date;

    //Promote year from user
    cout << "Please enter the year: ";
    cin >> year;
    date.setYear(year);
    cout << endl;

    //Promote month from user
    cout << "Please enter the month: ";
    cin >> month;

    while (monthAgain) {
        try {
            date.setMonth(month);
            monthAgain = false;
        } catch (Date::InvalidMonth) {
            cout << "Please enter a valid value for month (1~12): ";
            cin >> month;
        }
    }
    cout << endl;

    //Promote day from user
    cout << "Please enter the day: ";
    cin >> day;

    while (dayAgain) {
        try {
            date.setDay(day);
            dayAgain = false;
        } catch (Date::InvalidDay) {
            cout << "Please enter a valid value for day (1~31): ";
            cin >> day;
        }
    }
    cout << endl;

    //Output result
    cout << "The date you input is: " << endl;
    date.output();

    return 0;
}

