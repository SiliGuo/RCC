/*
 *
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: Project Euler #6*
 *    PROBLEM DEFINITION: Project Euler Problem #6, with discussion on while loops
 *                        and do/while loops for CSC 5.
 *                  DATE: 3/22/16
 *     SYSTEM - HARDWARE: Apple Mac, OS X
 *            - SOFTWARE: NetBeans 8.1
 *         Input Devices: Keyboard
 *        Output Devices: Screen
 *                                                                          
 *   PROGRAM ASSUMPTIONS: User to enter an integer value between 1 and 100,000
 *                                                              
 */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // n is the number the use enters between 1 and 100,000
    // sum_sq is the sum of the squares from 1 to n
    // sum is the sum of the integers from 1 to n
    // difference is the difference between sum*sum and sum_sq
    // choice is the character that user enters if they want to continue program (Yy = Yes, any other character is No)
    long n, sum_sq, sum;
    double difference;
    char choice;
    
    do{
        bool isValidInput=false;
        do{
            // prompt user for n and get n from user
            cout << "Enter a value for N (must be between 1 and 100,000): ";
            cin >> n;
        
            isValidInput = ( n>=1 && n<=100000 );
        
            if ( !isValidInput ) cout << "Invalid value for N. Must be between 1 and 100000, try again!" << endl;
        } while ( !isValidInput ); // loop this do while loop until the user enters a value for N between 1 and 100,000
    
        // compute the sum of the squares
        int counter=1;
        sum_sq=0;
        
        while ( counter <= n ) // loop this loop while counter is less than or equal to n
        {
            sum_sq = sum_sq + (counter * counter); // sum_sq = sum_sq + counter squared
            counter = counter + 1; // increment our counter by 1
        }
        cout << "sum_sq= " << sum_sq << endl;
        
        // compute the sum of integers between 1 and n
        counter=1;
        sum=0;
        
        while ( counter <= n ) // loop this while counter is less than or equal to n
        {
            sum = sum + counter; // sum is the sum of integers from 1 to n
            counter = counter +1; // increment the counter by 1
        }
        cout << "sum squared= " << fixed << pow(sum,2) << endl;
        
        // compute the difference
        difference = pow(sum,2) - sum_sq;
        
        // output the result
        cout << "The difference of the square of sum and sum of squares for 1 to " << n << " is: " << fixed << difference << endl;
        cout << endl;
                
        // ask user if they would like to run this program again...
        cout << "Would you like to run this program again (Y or y for Yes, any other character to quit...)?" << endl;
        cin.ignore();
        cin.get(choice);
    } while ( choice == 'Y' || choice == 'y'); // main loop of program
}