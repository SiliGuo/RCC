/* 
 * File:   main.cpp
 * Author: siliguo
 *
 * Created on December 5, 2016, 8:15 PM
 */

#include <string>
#include <iostream>
using namespace std;

#include "MilTime.h"

int main(int argc, char** argv) {

    //Declare variables
    int milHours, milSeconds;

    //Promote info from user
    do {
        cout << "Please enter the hours in military (0~2359): ";
        cin >> milHours;
        //Check validation
        if (milHours < 0 || milHours > 2359)
            cout << "Invalid Input! Please enter a number between 0~2359." << endl;
    } while (milHours < 0 || milHours > 2359);
    
    do {
        cout << "Please enter the seconds in military (0~59): ";
        cin >> milSeconds;
        //Check validation
        if (milSeconds < 0 || milSeconds > 59)
            cout << "Invalid Input! Please enter a number between 0~59." << endl;
    } while (milSeconds < 0 || milSeconds > 59);
    
    //Declare a variable in MilTime class
    MilTime std(milHours, milSeconds);
    
    //Output standard time
    cout << "The standard time is: " << endl;
    cout << std.getStandHr() << endl;

    return 0;
}

