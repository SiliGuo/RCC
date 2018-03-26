/* 
 * File:   DayOfYear.cpp
 * Author: siliguo
 * 
 * Created on November 18, 2016, 12:23 PM
 */

#include <iostream>
#include <string>
using namespace std;

#include "DayOfYear.h"

string DayOfYear::format = " ";
int DayOfYear::num = 0;

DayOfYear::DayOfYear(int d) {
    day = d;
}

void DayOfYear::translate(int d) {
    string month[12] = {"January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};

    format = " ";
    num = d;
    
    if (d <= 31) {
        format += month[0];
    } else if (d <= 31 + 28) {
        format += month[1];
        num -= 31;
    } else if (d <= 31 + 28 + 31) {
        format += month[2];
        num -= (31 + 28);
    } else if (d <= 31 + 28 + 31 + 30) {
        format += month[3];
        num -= (31 + 28 + 31);
    } else if (d <= 31 + 28 + 31 + 30 + 31) {
        format += month[4];
        num -= (31 + 28 + 31 + 30);
    } else if (d <= 31 + 28 + 31 + 30 + 31 + 30) {
        format += month[5];
        num -= (31 + 28 + 31 + 30 + 31);
    } else if (d <= 31 + 28 + 31 + 30 + 31 + 30 + 31) {
        format += month[6];
        num -= (31 + 28 + 31 + 30 + 31 + 30);
    } else if (d <= 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31) {
        format += month[7];
        num -= (31 + 28 + 31 + 30 + 31 + 30 + 31);
    } else if (d <= 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30) {
        format += month[8];
        num -= (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31);
    } else if (d <= 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31) {
        format += month[9];
        num -= (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30);
    } else if (d <= 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30) {
        format += month[10];
        num -= (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31);
    } else {
        format += month[11];
        num -= (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30);
    }
}

void DayOfYear::print() {
    cout << format << " " << num;
}

DayOfYear DayOfYear::operator++() {
    day++;
    if(day>365) day%=365;
    translate(day);
}

DayOfYear DayOfYear::operator--() {
    day--;
    if(day>365) day%=365;
    translate(day);
}