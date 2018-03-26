/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on September 19, 2016, 0:18 PM
 * Purpose:  C++ Review (Gaddis_8th, 3.12)
 */

//System Libraries
#include <iostream>
using namespace std;

//Execution Begin Here!

int main(int argc, char** argv) {
    //Declare two variables in floating point
    float Cels, Fahr;

    //Input data
    cout << "Enter a number in Celsius temperature: ";
    cin >> Cels;

    //Convert the Celsius temperature to Fahrenheit temperature
    Fahr = 9 * Cels / 5 + 32;

    //Display solution on screen
    cout << "The temperature in Fahrenheit is: " << Fahr << "˚" << endl;

    //Exit stage right!
    return 0;
}