/* 
 * File:   FeetInches.cpp
 * Author: siliguo
 * 
 * Created on November 18, 2016, 5:02 PM
 */

// Implementation file for the FeetInches class
#include <cstdlib> // Needed for abs()
#include "FeetInches.h"

//**************************************************************
// Definition of member function simplify. This function *
// checks for values in the inches member greater than *
// twelve or less than zero. If such a value is found, *
// the numbers in feet and inches are adjusted to conform *
// to a standard feet & inches expression. For example, *
// 3 feet 14 inches would be adjusted to 4 feet 2 inches and *
// 5 feet −2 inches would be adjusted to 4 feet 10 inches. *
//**************************************************************

void FeetInches::simplify() {
    if (inches >= 12) {
        feet += (inches / 12);
        inches = inches % 12;
    } else if (inches < 0) {
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}

//**********************************************
// Overloaded binary + operator. *
//**********************************************

FeetInches FeetInches::operator+(const FeetInches &right) {
    FeetInches temp;
    temp.inches = inches + right.inches;
    temp.feet = feet + right.feet;
    temp.simplify();
    return temp;
}
//**********************************************
// Overloaded binary - operator. *
//**********************************************

FeetInches FeetInches::operator-(const FeetInches &right) {
    FeetInches temp;
    temp.inches = inches - right.inches;
    temp.feet = feet - right.feet;
    temp.simplify();
    return temp;
}

bool FeetInches::operator<=(const FeetInches& right) {
    bool comp;
    if (feet < right.feet) {
        comp = true;
    } else {
        if (feet == right.feet && inches == right.inches) {
            comp = true;
        } else {
            comp = false;
        }
    }
    return comp;
}

bool FeetInches::operator>=(const FeetInches& right) {
    bool comp;
    if (feet > right.feet) {
        comp = true;
    } else {
        if (feet == right.feet && inches == right.inches) {
            comp = true;
        } else {
            comp = false;
        }
    }
    return comp;
}

bool FeetInches::operator==(const FeetInches& right) {
    bool comp;
    if (feet != right.feet) {
        comp = false;
    } else {
        if (inches != right.inches) {
            comp = false;
        } else {
            comp = true;
        }
    }
    return comp;
}