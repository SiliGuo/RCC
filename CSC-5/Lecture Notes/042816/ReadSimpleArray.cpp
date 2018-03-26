/*
 *
 * 
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: ReadSimpleArrayDemo
 *    PROBLEM DEFINITION: Reads into an array, a file names: scores.txt, and performs some statistical
 *                        computations, and reports the results.
 *                  DATE: 4/28/2016
 *     SYSTEM - HARDWARE: Intel i7, 16GB, RAM
 *            - SOFTWARE: OS x El Capitan, NetBeans IDE 8.1
 *         Input Devices: Keyboard, Hard Disk Drive
 *        Output Devices: Terminal Screen, Hard Disk Drive
 *                                                                          
 *   PROGRAM ASSUMPTIONS: Assumes the text file contains the correct number of values to read into array.
 *                                                              
 */

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// main function here
int main()
{
    // open the file named scores
    ifstream inFile;
    inFile.open("scores.txt");
    
    if ( inFile )
    {
        // read in the first value, which should be the number telling us the size of the array
        int array_size;
        inFile >> array_size;
        
        // initialize the array to the size of what was read in as first data element (size)
        int scores[ array_size ]; // declare an array named scores that will hold the scores
        
        // loop through all of the data elements
        for(int i=0;i<array_size;i++)
        {
            inFile >> scores[i]; // read in the data and store in the array at the specified index i
        }
        
        // close the file
        inFile.close();
        
        // do statistics on the data
        int min_value=scores[0];
        int max_value=scores[0];
        int sum=scores[0];
        
        for(int i=1;i<array_size;i++)
        {
            if ( scores[i] < min_value ) min_value = scores[i]; // if true, min_value is scores[i]
            if ( scores[i] > max_value ) max_value = scores[i]; // if true, min_value is scores[i]
            sum = sum + scores[i]; // add scores[i] to running sum variable
        }
        
        float average = sum / (float)array_size;
        
        // compute standard deviation
        float std_dev=0.0;
        
        for(int i=0;i<array_size;i++)
        {
            float difference=pow(scores[i]-average,2);
            if ( difference <0 ) difference = -difference; // absolute value of difference
            std_dev = std_dev + difference;
        }
        
        // divide by number of elements
        std_dev = std_dev / array_size;
        std_dev = sqrt(std_dev);
        
        // output some statistical data about our array
        cout << "Minimum score: " << min_value << endl;
        cout << "Maximum score: " << max_value << endl;
        cout << "Average score: " << average << endl;
        cout << "Standard deviation: " << std_dev << endl;
    }
    else
    {
        cout << "An error has occurred trying to write scores.txt" << endl;
        return 1; // signal to OS that an error occurred
    }
    
    return 0; // this line is optional
}