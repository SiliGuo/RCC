/* 
 * File:   NumDays.cpp
 * Author: siliguo
 * 
 * Created on November 18, 2016, 4:16 PM
 */

#include <iostream>
#include <string>
using namespace std;

#include "NumDays.h"

NumDays::NumDays(int h) {
    hour = h;
    day = 0;
    convert();
}

void NumDays::convert() {
    day = hour / 8.0f;
}

int NumDays::getHour() const {
    return hour;
}

float NumDays::getDay() const {
    return day;
}

NumDays NumDays::operator +(const NumDays& right) {
    NumDays temp(0);
    temp.hour = hour + right.hour;
    temp.convert();
    return temp;
}

NumDays NumDays::operator -(const NumDays& right) {
    NumDays temp(0);
    temp.hour = hour - right.hour;
    temp.convert();
    return temp;
}

NumDays NumDays::operator ++() {
    hour++;
    convert();
    return *this;
}

NumDays NumDays::operator --() {
    hour--;
    convert();
    return *this;
}