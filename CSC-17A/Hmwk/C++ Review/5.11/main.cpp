/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on September 20, 2016, 6:37 PM
 * Purpose:  C++ Review (Gaddis_8th, 5.11)
 */

//System Libraries
#include <iostream>
using namespace std;

//Execution Begin Here!

int main(int argc, char** argv) {
    //Declare two variables as integer
    int size, days;
    //Declare a variable in floating point
    float increase;

    //Use do while loop to input data with limitation: starting size, daily increase and the days
    do {
        cout << "Enter a starting number of organisms (cannot be less than 2): ";
        cin >> size;
    } while (size < 2);

    do {
        cout << "Enter the average daily population increase percentage (cannot be negative): ";
        cin >> increase;
    } while (increase < 0);

    do {
        cout << "Enter the number of days organisms multiply (cannot be less than 1): ";
        cin >> days;
    } while (days < 1);

    //Use for loop to calculate and output the size after each day
    for (int i = 0; i < days; i++) {
        size = size * (1+ increase);
        
        //Output the result on screen
        cout << "The size of population on day " << i+1 << " is: " << size << endl;
    }
    //Exit stage right!
    return 0;
}