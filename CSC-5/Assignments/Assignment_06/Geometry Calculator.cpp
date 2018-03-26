/*
 *
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: Geometry Calculator
 *    PROBLEM DEFINITION: Write a program to display a Geometry Calculator (Exercise 4.23 in Gaddis Text)
 *                  DATE: 3/17/16
 *     SYSTEM - HARDWARE: Intel i-7, 16 gigs of ram
 *            - SOFTWARE: NetBeans on Mac
 *         Input Devices: Keyboard
 *        Output Devices: Standard Output
 *                                                                          
 *   PROGRAM ASSUMPTIONS: 1. variables for radius, length, width, base, and height are floating point
 *                        2. assume all lengths of measure must be greater than zero
 *                        3. input for menu choice is an integer in the range of 1 to 4
 *                        4. constant for PI is assumed to be 3.14159
 *                        5. assume output of result to be of width 12, and 2 digits of decimal precision
 * 
 */

// All necessary include directives here
#include <iostream>
#include <iomanip>

// optional using name space std goes here
using namespace std;

// main function here
int main()
{
    // your main program goes here
    const float PI = 3.14159; // declare a named constant for PI, and it has the value of  3.14159
    const int FIELD_WIDTH = 12; // constant for width of our output field
    const int DECIMAL_DIGITS = 2; // constant for decimal digits of our output field
    
    // declare our non constant variables
    float area, radius, length, width, base, height;
    int menuChoice;
    
    // next, we output our menu
    cout << "Geometry Calculator" << endl;
    cout << endl; // put a blank line between program title and menu
    cout << "     1. Calculate the Area of a Circle" << endl;
    cout << "     2. Calculate the Area of a Rectangle" << endl;
    cout << "     3. Calculate the Area of a Triangle" << endl;
    cout << "     4. Quit" << endl;
    cout <<"********************************************" << endl;
    cout << endl;
    cout << "     Enter your choice (1-4): "; // the prompt
    
    // get menu choice from the user
    cin >> menuChoice;
    cout << endl;
    
    // check the menu choice from user and execute the code that
    // corresponds to their choice
    if ( menuChoice==1 ) // if user choose option 1
    {
        // prompt user for radius of the circle
        cout << "Enter the radius of the circle (must be greater than zero): ";
        
        // get the radius from user
        cin >> radius;
        cout << endl;
        
        if ( radius > 0 ) // if radius greater than zero, calculate the area
        {
            // calculate the area as PI times radius times radius
            area = PI * radius * radius;
            
            // output the result
            cout << "Area of the circle is ";
            cout << setw( FIELD_WIDTH ) << setprecision( DECIMAL_DIGITS ) << fixed << showpoint;
            cout << area << endl;
        } // end of radius > 0 is true code block
        else
        {
            // radius cannot be less than or equal to zero
            cout << "Invalid Entry: Radius cannot be less than or equal to zero!!!" << endl;
        } // end of radius >0 is false code block
    } // end of menuChoice==1 code block
    
    else if ( menuChoice==2 ) // if user choose option 2
    {
        // prompt user for length of the rectangle
        cout << "Enter the length of the rectangle (must be greater than zero): ";
        
        // get the length from user
        cin >> length;
        cout << endl;
        
        if ( length > 0 ) // is length greater than zero
        {
            // prompt for width of the rectangle
            cout << "Enter the width of the rectangle (must be greater than zero): ";
            
            // get the width from user
            cin >> width;
            cout << endl;
            
            if ( width > 0 ) // is width >0
            {
               // calculate the area as length times width
                area = length * width;
            
                // out put the result
                cout << endl;
                cout << "Area of the rectangle is ";
                cout << setw( FIELD_WIDTH ) << setprecision( DECIMAL_DIGITS ) << fixed << showpoint;
                cout << area << endl; 
            }
            else
            {
                // width cannot be less than or equal to zero
                cout << "Invalid Entry: Width cannot be less than or equal to zero!!!" << endl;
            }
            
        } // end of length > 0 is true code block
        else
        {
            // length cannot be less than or equal to zero
            cout << "Invalid Entry: Length cannot be less than or equal to zero!!!" << endl;
        } // end of length >0 is false code block
    } // end of menuChoice==2 code block
    
    else if ( menuChoice==3 ) // if user choose option 3
    {
        // prompt user for base of the rectangle
        cout << "Enter the base of the triangle (must be greater than zero): ";
        
        // get the base from user
        cin >> base;
        cout << endl;
        
        if ( base > 0 ) // is base greater than zero
        {
            // prompt for height of the rectangle
            cout << "Enter the height of the triangle (must be greater than zero): ";
            
            // get the height from user
            cin >> height;
            cout << endl;
            
            if ( height > 0 ) // is height greater than zero
            {
               // calculate the area as base times height divided by 2
                area = ( base * height) / 2;
            
                // out put the result
                cout << "Area of the triangle is ";
                cout << setw( FIELD_WIDTH ) << setprecision( DECIMAL_DIGITS ) << fixed << showpoint;
                cout << area << endl; 
            }
            else
            {
                // height cannot be less than or equal to zero
                cout << "Invalid Entry: Height cannot be less than or equal to zero!!!" << endl;
            }
            
        } // end of height > 0 is true code block
        else
        {
            // base cannot be less than or equal to zero
            cout << "Invalid Entry: Base cannot be less than or equal to zero!!!" << endl;
        } // end of base >0 is false code block
    } // end of menuChoice==3 code block
    
    else if ( menuChoice==4 ) // if user choose option 4
    {
        // the program exit
        cout << "Program Exiting..." << endl;
    } // end of menuChoice==4 code block
    
    else // if user enter menuChoice other than 1-4
    {
        // output the following word
        cout << "Output Invalid Value. Please enter a number between 1 to 4. " << endl;
    } // end of else statement code block
    
    cout << endl; // extra blank line
    
    // output the following word on terminal screen
    cout << "Thank you for using Geometry Calculator." << endl;
}
