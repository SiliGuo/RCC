/* 
 * File:   Date.cpp
 * Author: siliguo
 * 
 * Created on November 16, 2016, 11:46 PM
 */

#include <iostream>
#include <string>
using namespace std;

#include "Date.h"

Date::Date() {
    year = 0;
    month = 0;
    day = 0;
}

void Date::setYear(int y) {
    year = y;
}

void Date::setMonth(int m) {
    if (m < 1 || m > 12)
        throw InvalidMonth();
    else
        month = m;
}

void Date::setDay(int d) {
    int max[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d < 1 || d > max[month - 1])
        throw InvalidDay();
    else
        day = d;

    //    if (d < 1 || d > 31)
    //        throw InvalidMonth();
    //    else
    //        day = d;
}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

void Date::output() {
    string mon;
    string strMonth[12] = {"January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    mon = strMonth[month - 1];

    //Output result
    cout << month << "/" << day << "/" << year << endl;
    cout << mon << " " << day << ", " << year << endl;
    cout << day << " " << mon << " " << year << endl;

}