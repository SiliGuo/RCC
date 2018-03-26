/*
 * 
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: WriteSimpleArrayDemo
 *    PROBLEM DEFINITION: Creates an integer array of 10 values, to store
 *                        assignment scores; and writes the array contents
 *                        to a file names: scores.txt
 *                  DATE: 4/28/2016
 *     SYSTEM - HARDWARE: Intel i7, 16GB, RAM
 *            - SOFTWARE: OS X El Capitan, NetBeans IDE 8.1
 *         Input Devices: Keyboard
 *        Output Devices: Screen
 *                                                                          
 *   PROGRAM ASSUMPTIONS: All scores entered must be between 0 to 100.
 *                                                              
 */

#include <iostream>
#include <fstream>
using namespace std;

// main function here
int main()
{
    const int NUM_SCORES = 10; // number of scores program will read
    
    int scores[NUM_SCORES]; // declare an array named scores that will hold the scores
    
    // prompt the user for the scores
    for(int i=0;i<NUM_SCORES;i++)
    {
        int input; // the user input from keyboard
        do
        {
            // our prompt
            cout << "Enter score # " << i+1 << ": ";
            cin >> input;
            
            // if input is between 0 and 100, break out of do-while loop
            if ( input >=0 && input <= 100) break; // break out of do-while loop if input is valid
            
            // input not in range of 0 to 100, so error message to user and try again
            cout << "Invalid input, must be between 0 and 100!" << endl << endl;
        } while(true); // this loop will run forever until the break keyword is encountered above
        
        scores[i]=input;
    }
    
    // output array data to file
    ofstream outFile;
    
    // open the file for writing
    outFile.open("scores.txt");
    
    
    if ( outFile ) // if this is "true" file is opened for writing, if not , then there was a problem
    {
        // write the size of the array to the file
        outFile << NUM_SCORES << "\r\n";
        
        // write the array data to file
        for(int i=0;i<NUM_SCORES;i++)
        {
            outFile << scores[i] << "\r\n";
        }
        
        // close file when done
        outFile.close();
    }
    else
    {
        cout << "An error has occurred trying to write scores.txt" << endl;
        return 1; // signal to OS that an error occurred
    }
    
    return 0; // this line is optional
}