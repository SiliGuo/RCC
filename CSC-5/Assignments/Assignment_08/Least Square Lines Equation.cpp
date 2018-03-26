/*
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: Least Square Lines Equation
 *    PROBLEM DEFINITION: Prompt the user to enter the route of the txt file, 
 *                        read the txt file, and divide into two lines x, and y.
 *                        Compute the sum of x, y, square of x, and product of 
 *                        x and y. Then compute the m and b, and output the 
 *                        Equation of least squares line.
 *                  DATE: 4/8/16
 *     SYSTEM - HARDWARE: Mac Pro
 *            - SOFTWARE: NetBeans IDE 8.1
 *         Input Devices: Keyboard
 *        Output Devices: Screen
 *
 *   PROGRAM ASSUMPTIONS: m, b, x, y, sum_x, sum_y, sum_xx, and sum_xy are float type
 *                        count is integer data type.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    // declare two variables named m and b as float type, and the variable filename of string
    float m, b;
    string filename;
	
	// prompt user for filename
	cout << "Enter name of file you want to read: ";
	getline(cin,filename,'\n');
	
	// declare an ifstream object for file input
	ifstream inputFile;
	
	// try to open the file
	inputFile.open(filename.c_str());
        
        if (inputFile) // if the complier read the numbers in the file
        {
            // declare 6 variables has value of 0 as float type, and count=1 as int type
            float input, x=0, y=0, sum_x=0, sum_y=0, sum_xx=0, sum_xy=0;
            int count=0;
            
            // use while loop to loop until read the end of the file
            while (!inputFile.eof())
            {
                if ( inputFile >> input )
                {
                    if ( count%2 == 0 ) // read the numbers in the left line
                    {
                        // calculate x, sum_x, sum_xx, count plus 1
                        x = input;
                        sum_x += x;
                        sum_xx += x*x;
                        count++;
                    } // end of if ( count%2 == 0 ) block
                    else // read the numbers in the right line
                    {
                        // calculate y, sum_y, sum_xy, count plus 1
                        y = input;
                        sum_y += y;
                        sum_xy += x*y;
                        count++;
                    }
                    
                } // end of if ((inputFile >> input)) block
                else break;
            } // end of while loop
            
            count/=2; // figure out how many numbers in a single line
            
            // calculate m and b in equation y=mx+b;
            m = (sum_xy-sum_x*(sum_y/count))/(sum_xx-sum_x*(sum_x/count));
            b = (sum_y/count)-m*(sum_x/count);
        } // end of if ( inputFile ) block
        
        // close the file
        inputFile.close();
        // output the result with precision of 5 dimension
        cout << setprecision(5) << showpoint << fixed << "Equation of least squares line: y = " << m << "x+" << b << endl;
} // end of main function block