/* 
 * File:   Number.cpp
 * Author: siliguo
 * 
 * Created on November 18, 2016, 12:31 AM
 */

#include <iostream>
#include <string>
using namespace std;

#include "Number.h"

Number::Number(int n) {
    number = n;
    translate(number);
}

string Number::eng = " ";


void Number::translate(int n) {
    string lessThan20[20] = {"zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen",
        "sixteen", "seventeen" "eighteen", "nineteen"};
    string tens[8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string hundred = "hundred";
    string thousand = "thousand";
    int a, b, c, d, e, f;

    a = n / 1000;
    b = n % 1000;
    c = b / 100;
    d = b % 100;
    e = d / 10;
    f = d % 10;

    //Translate
    if (a != 0) eng = eng + lessThan20[a] + " " + thousand + " ";
    if (c != 0) eng = eng + lessThan20[c] + " " + hundred + " ";
    if (e < 2) eng = eng + lessThan20[d];
    else eng = eng + tens[e - 2] + " " + lessThan20[f];

}

void Number::print() {
    cout << "The number translate into English is: " << endl;
    cout << eng << endl;
}