/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 20, 2016, 7:10 PM
 * Purpose:  C++ Review (Gaddis_8th, 6.7)
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
float celsius(float);

//Execution Begin Here!

int main(int argc, char** argv) {

    //Output the table in format
    cout << setw(14) << left << "Fahrenheit" << "Celsius" << endl;
    cout << "-----------------------" << endl;
    
    //Use for loop to output Fahrenheit temperature from 1 to 20
    for (int f = 1; f <= 20; f++) {
        cout << setw(5) << " " << setw(8) << f << celsius(f) << endl;
    }
    //Exit stage right!
    return 0;
}

//Function implementation
float celsius(float fahr) {
    float cels;
    cels = 5 * (fahr - 32) / 9;

    //Return result to main function
    return cels;
}