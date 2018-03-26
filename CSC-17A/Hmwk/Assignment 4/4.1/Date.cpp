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

Date::Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
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
    mon = strMonth[month-1];
    
    //Output result
    cout << month << "/" << day << "/" << year << endl;
    cout << mon << " " << day << ", " << year << endl;
    cout << day << " " << mon << " " << year << endl;
    
}