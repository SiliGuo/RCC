/* 
 * File:   main.cpp
 * Author: siliguo
 *
 * Created on November 18, 2016, 11:05 AM
 */

#include <iostream>
#include <string>
using namespace std;

#include "DayOfYear.h"

int main(int argc, char** argv) {

    //Declare variables
    int number;

    //Prompt number from user
    do {
        cout << "Please enter a number between 1~365: ";
        cin >> number;
        //Check validation
        if (number < 1 || number > 365) cout << "Invalid input! Please enter a number between 1~365." << endl;
    } while (number < 1 || number > 365);
    
    DayOfYear date(number);
    
    date.translate(number);
    
    date.print();
    
    return 0;
}