/*
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: AverageOfNumbersFile
 *    PROBLEM DEFINITION: Get a textfile name from the user
 *                  DATE: 3/29/16
 *     SYSTEM - HARDWARE: Mac Pro
 *            - SOFTWARE: NetBeans 8.1
 *         Input Devices: Keyboard, textfile from storage device
 *        Output Devices: Screen
 *                                                                          
 *   PROGRAM ASSUMPTIONS: The file specified by the user contains a list of integer values with
 *                        a sentinel value of -999999 signaling the end of the file
 *                                                              
 */

// All necessary include directives here
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// main function here
int main()
{
    string filename;
	
    // prompt user for filename
    cout << "Enter name of file you want to read: ";
    //cin >> filename;
    getline(cin,filename,'\n');
	
    // declare an ifstream object for file input
    ifstream inputFile;
	
    // try to open the file
    inputFile.open(filename.c_str());
	
    if (inputFile)
    {
        int input, sum=0, count=0;
        // read in all integer values in the file until -999999 encountered
        do 
        {
	if( (inputFile >> input) )
	{			
            cout << "Found the value: " << input << endl;
				
            if (input == -999999) break;
            sum=sum+input;
            count++;
	}
        else break;
			
        } while( input != -999999 );
		
        // clsoe the file when we are done
        inputFile.close();
		
        // output the average
        cout << "Average: " << sum/(float)count << endl;
		
    }
    else
    {
        cout << "File could not be opened for reading..." << endl;
        return 1;
    }
    return 0; // this line is optional
}