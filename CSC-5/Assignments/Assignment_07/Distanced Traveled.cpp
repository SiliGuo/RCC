/*
 *
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: Distanced Traveled
 *    PROBLEM DEFINITION: Write a program to compute the distance a vehicle 
 *                        traveled, and display the output table with the
 *                        distance traveled in each hour. (Exercise 5.6, pg 294 in Gaddis Text)
 *                  DATE: 3/24/16
 *     SYSTEM - HARDWARE: Mac Pro, OS X
 *            - SOFTWARE: NetBeans 8.1
 *         Input Devices: Keyboard
 *        Output Devices: Screen
 *                                                                          
 *   PROGRAM ASSUMPTIONS: 1. variables for speed and distance as floating type
 *                        2. variable for time as integer type 
 *                        3. assume speed that user entered must not be negative numbers
 *                        4. assume time that user entered must not be less than 1 hour
 *                                                              
 */

#include <iostream> // for input and output
#include <iomanip> // for manipulators to handle io manipulation
using namespace std;

int main()
{
    // declare a variable named speed as floating point
    float speed;
    // declare a variable named time as integer
    int time;
    
    do{ // use do while loop to make sure speed is positive; otherwise, ask user to enter again
        // prompt user to enter a number of mph for speed
        cout << "What is the speed of the vehicle in mph? (Must be a non-negative number): ";
        cin >> speed;
        
        // if user entered a negative number, output "Invalid Value"
        if ( speed<0 ) cout << "Invalid value for speed. Must be a positive number, please try again!" << endl;
    } while ( speed<0 );
    
    do{ // use do while to make sure time is no less than 1; otherwise, ask user to enter again
        // prompt user to enter a number of hours for time
        cout << "How many hours has it traveled? (Must be an integer no less than 1): ";
        cin >> time;
        
        // if user entered an integer less than or equal to 1, output "Invalid Value"
        if ( time<1 ) cout << "Invalid value for time. Must be an integer no less than 1, please try again!" << endl;
    } while ( time <1 );
    
    // output the title of the table
    cout << "Hour  Distance Traveled" << endl;
    cout << "--------------------------------" << endl;
    
    // declare variable distance as floating point
    float distance = 0;
    
    for ( int count=1; count<=time; count++) // use for loop to calculate the distance
    {
        // calculate distance by multiplying speed and time
        distance = speed * count;
        
        // output the time and distance traveled in the table formally
        cout << setw(2) << right << count << setw(14) << distance << endl;
    }
}