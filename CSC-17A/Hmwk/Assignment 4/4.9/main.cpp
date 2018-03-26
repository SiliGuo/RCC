/* 
 * File:   main.cpp
 * Author: siliguo
 *
 * Created on November 18, 2016, 2:13 PM
 */

#include <iostream>
#include <string>
using namespace std;

#include "NumDays.h"

int main(int argc, char** argv) {

    NumDays day1(23);
    NumDays day2(11);
    NumDays day3(0);
    NumDays day4(0);
    
    //Output result
    cout << "The first person works " << day1.getHour() << " hours = " << day1.getDay() << " days." << endl;
    cout << "The second person works " << day2.getHour() << " hours = " << day2.getDay() << " days." << endl;
    day3 = day1 + day2;
    cout << "The third person works, as sum of the first two, " << day3.getHour() << " hours = " << day3.getDay() << " days." << endl;
    day4 = day1 - day2;
    cout << "The fourth person works, as difference between the first two, " << day4.getHour() << " hours = " << day4.getDay() << " days." << endl;
    cout << endl;
    
    cout << "Using ++ operator on first person." << endl;
    day1.operator ++();
    cout << "The first person works " << day1.getHour() << " hours = " << day1.getDay() << " days." << endl;
    cout << endl;
    
    cout << "Using -- operator on second person." << endl;
    day2.operator --();
    cout << "The second person works " << day2.getHour() << " hours = " << day2.getDay() << " days." << endl;
    cout << endl;
    return 0;
}

