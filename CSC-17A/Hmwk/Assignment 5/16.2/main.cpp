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
    bool tryAgain = true;

    //Declare a variable in MilTime class
    MilTime std;

    //Promote info from user
    cout << "Please enter the hours in military (0~2359): ";
    cin >> milHours;

    cout << "Please enter the seconds in military (0~59): ";
    cin >> milSeconds;

    while(tryAgain){
            try {
                std.setTime(milHours, milSeconds);
                tryAgain = false;
            }
            catch(MilTime::BadHour) {
                cout << "For hours, please enter a number between 0~2359: ";
                cin >> milHours;
            }
            catch(MilTime::BadSeconds) {
                cout << "For seconds, please enter a number between 0~59: ";
                cin >> milSeconds;
            }
        }

    //Output standard time
    cout << "The standard time is: " << endl;
    cout << std.getStandHr() << endl;

    return 0;
}

