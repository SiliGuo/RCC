/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on September 21, 2016, 2:20 PM
 * Purpose:  C++ Review (Gaddis_8th, 3.18)
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Execution Begin Here!

int main(int argc, char** argv) {
    // Declare five variables of floating point type
    float rate, times, principal, interest, amount;

    // Input data: the principal, rate, and times
    cout << "Enter the principal in your savings account is: ";
    cin >> principal;

    cout << "Enter the interest rate is: ";
    cin >> rate;

    cout << "Enter the number of times the interest is compounded is: ";
    cin >> times;

    // Calculate the amount, and stored in the variable amount
    amount = principal * pow((1 + rate / (100 * times)), times);
    interest = amount - principal; // Calculate the interest
    cout << endl; // extra blank line
    cout << "----------------------------------------" << endl; // to make the output looks format
    cout << endl; // extra blank line

    // Output the result in format
    cout << "Interest Rate: " << setw(19) << right << rate << "%" << endl;
    cout << "Times Compounded: " << setw(16) << right << times << endl;
    cout << "Principal:              $" << setw(9) << setprecision(2) << right << fixed << showpoint << principal << endl;
    cout << "Interest:               $" << setw(9) << setprecision(2) << right << fixed << showpoint << interest << endl;
    cout << "Amount in Savings:      $" << setw(9) << setprecision(2) << right << fixed << showpoint << amount << endl;

    //Exit stage right!
    return 0;
}