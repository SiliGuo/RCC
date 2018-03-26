/*
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: Rainfall Statistics
 *    PROBLEM DEFINITION: Prompt user to enter the amount of rainfall of each
 *                        month. Calculate the sum and average of rainfall, and
 *                        figure out the months for the max and min rainfall
 *                        page 448, exercise 7.2
 *                  DATE: 04/26/16
 *     SYSTEM - HARDWARE: Intel i7, 16GB, RAM
 *            - SOFTWARE: OS X El Capitan, NetBeans IDE 8.1
 *         Input Devices: Keyboard
 *        Output Devices: Screen
 *                                                                          
 *   PROGRAM ASSUMPTIONS: the number of months stored in a variable of constant integer named ARRAY_SIZE
 *                        declare input, sum, average, minimum, and maximum as double data type
 *                                                              
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{   
    // declare 5 variables as double data type
    double input, sum=0, average, minimum, maximum;
    
    // declare two vectors
    vector<string> months {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    vector<double> rainfall;
    
    // prompt user to enter the amount for the rainfall for each month
    cout << "Please enter the numbers of total rainfall for each of " << months.size() << " months." << endl;
    cout << "(The numbers should not be less than zero!!!)" << endl;
    cout << endl;
    
    for (int i=0; i<months.size(); i++) // use for loop to let user enter numbers month by month
    {
        do // use do while to loop if user enter a negative number
        {
            cout << "Enter the values of rainfall for " << months[i] << ": ";
            cin >> input;
        } while (input<0); // loop back if user enter a negative number
        
        rainfall.push_back(input); 
    } // end of for loop block
    
    // calculate the total rainfall of the year
    for (int i=0; i<rainfall.size(); i++)
    {
        sum += rainfall[i];
    }
    
    // find the largest and smallest values in the array
    minimum=rainfall[0];
    maximum=rainfall[0];
    for(int i=1; i< rainfall.size(); i++)
    {
        // if rainfall[i] is smaller than minimum, set new minimum value to rainfall[i]
        if ( rainfall[i] < minimum )
        {
            minimum=rainfall[i];
        }
        
        // if rainfall[i] is bigger than maximum, set new maximum value to rainfall[i]
        if ( rainfall[i] > maximum )
        {
            maximum=rainfall[i];
        }
    } // end of for loop block
    
    average=sum / rainfall.size();
     
    // output the result on screen
    cout << "The amount of total rainfall for the year is: " << sum << endl;
    cout << "The amount of average monthly rainfall is: " << average << endl;
    cout << "Month with lowest rainfall: " << endl;
    for (int i=0; i<rainfall.size(); i++)
    {
        if (rainfall[i]==minimum)
        {
            cout << months[i] << endl;
        }
    }
    cout << "Month with highest rainfall: " << endl;
    for (int i=0; i<rainfall.size(); i++)
    {
        if (rainfall[i]==maximum)
        {
            cout << months[i] << endl;
        }
    }
}