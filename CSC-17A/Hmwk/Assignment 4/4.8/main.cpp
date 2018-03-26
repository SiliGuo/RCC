/* 
 * File:   main.cpp
 * Author: siliguo
 *
 * Created on November 18, 2016, 12:23 PM
 */

#include <iostream>
#include <string>
using namespace std;

#include "DayOfYear.h"

int main(int argc, char** argv) {

    //Declare variables
    int number;

    //Prompt number from user
    cout << "Please enter a number between 1~365: ";
    cin >> number;
    //Check validation
    if (number < 1 || number > 365) {
        cout << "Invalid input!" << endl;
    } else {
        DayOfYear date(number);
        date.translate(number);
        cout << "Today's date is: " << endl;
        date.print();
        cout << endl << endl;
        
        date.operator ++();
        cout << "Tomorrow's date is: " << endl;
        date.print();
        cout << endl << endl;
        
        date.operator --();
        date.operator --();
        cout << "Yesterday's date is: " << endl;
        date.print();
    }

    return 0;
}