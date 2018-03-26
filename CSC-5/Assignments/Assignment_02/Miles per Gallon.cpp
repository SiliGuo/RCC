/* Programmer: Sili Guo
 * Date 3/1/16
 * Description: write a program to prompt the user to enter
 * the number of gallons of gas car tank can hold, and the
 * number of miles driven on full tank of gas. Compute the
 * rate (mpg) of this car. Output the result 
 * in a well worded output to the terminal screen.
 * (Exercise 3.1, pg 142 in Gaddis Text)
 * 
 * Assumptions:  inputs will be floating point
 * 
 * Variables: amount    -number of gallons of gas car tank can hold
 *            distance  -number of miles driven on full tank of gas
 *            rate      -miles per gallons
 */

#include <iostream>
using namespace std;

int main()
{
    // Declare three variables of floating point type
    float amount, distance, rate;
    // Get the number of gallons of gas, and miles can be driven.
    cout << "Enter the number of gallons of gas car tank can hold is: ";
    cin >> amount;
    
    cout << "Enter the number of miles driven on full tank of gas is: ";
    cin >> distance;
    
    // Compute the rate by divide amount by distance
    rate = distance / amount;
    
    // Display the result (rate) on screen
    cout << "The rate of the car is ";
    cout << rate;
    cout << " mpg" << endl;
}