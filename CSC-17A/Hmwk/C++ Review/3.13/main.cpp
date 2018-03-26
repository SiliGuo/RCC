/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on September 19, 2016, 0:32 PM
 * Purpose:  C++ Review (Gaddis_8th, 3.13)
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Execution Begin Here!
int main(int argc, char** argv) {
    // Declare two constants of the currency exchange rate
    const float YEN_PER_DOLLAR = 98.93, EUROS_PER_DOLLAR = 0.74;
    
    //Declare three variables in floating point
    float dollar, yen, euros;
    
    //Input data
    cout << "Enter the amount of U.S. dollar you want to exchange: ";
    cin >> dollar;
    
    //Convert the U.S. dollars to Japanese yen
    yen = dollar * YEN_PER_DOLLAR;
    
    //Convert the U.S. dollars to euros
    euros = dollar * EUROS_PER_DOLLAR;
    
    //Display solution on screen
    cout << setprecision(2) << showpoint << fixed << dollar << " U.S. dollars equal to " << yen << " Japanese yen, equal to "<< euros << " euros." << endl;

    //Exit stage right!
    return 0;
}