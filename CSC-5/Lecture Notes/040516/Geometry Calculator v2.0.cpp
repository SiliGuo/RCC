/*
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: Geometry Calculator v2.0
 *    PROBLEM DEFINITION: Geometry Calculator program from Chapter 4? improved
 *                        with the use of the functions.
 *                  DATE: 4/5/2016
 *     SYSTEM - HARDWARE: Mac Pro
 *            - SOFTWARE: NetBeans 8.1
 *         Input Devices: Keyboard
 *        Output Devices: Terminal Screen
 *
 *   PROGRAM ASSUMPTIONS: Program will allow user to enter a choice of three 
 *                        shapes to calculate the area, demonstrating the use of functions.                                                            
 */

// All necessary include directives here
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//function prototypes - declare function headers heres, implement function logic after the main function.
int displayMenu(); // displays our program's menu to the terminal screen, returns the user's choice
float getAreaOfCircle(); // prompts user for radius of circle, computes the area, and returns the area
float getAreaOfRectangle(); // prompts user for length, width of rectangle, computes the area, and returns the area
float getAreaOfTriangle(); // prompts user for base and height of triangle, computes the area, and returns the area 
void outputArea( float area, string shape_name); // output the area of the shape and include the shape's name

// your main program goes here
const float PI = 3.14159; // declare a named constant for PI, and it has the value of 3.14159
const int FIELD_WIDTH = 12; // constant for width of our output field
const int DECIMAL_DIGITS = 2; // constant for decimal digits of our output field
        
// main function here
int main()
{
    do{
        int choice = displayMenu(); // call the display menu function to output our menu, returns the user's choice
        float area; // area of the shape
        if ( choice == 4 )
        {
            cout << "Good bye, thank you for using this program. See you again soon!\n";
            return 0;
        }
        
        if ( choice >= 1 && choice <= 3 )
        {
            switch(choice)
            {
                case 1: // choice 1
                    area = getAreaOfCircle();
                    outputArea(area,"circle");
                    break;
                    
                case 2: // choice 2
                    area = getAreaOfRectangle();
                    outputArea(area,"rectangle");
                    break;
                    
                case 3: // choice 3
                    area = getAreaOfTriangle();
                    outputArea(area,"triangle");
            }   
        }
        else
        {
            cout << "Invalid menu choice, try again!\n";
        }
    } while(true);
}

// future (chap. 6+): function implementations go here - delete this line if you are not using functions

//implementation of displayMenu
int displayMenu()
{
    int menuChoice;
    
    // display the menu, code borrowed from assignment #6
    cout << "Geometry Calculator" << endl;
	cout << endl; // put a blank line between program title and menu
	cout << "     1. Calculate the Area of a Circle" << endl;
	cout << "     2. Calculate the Area of a Rectangle" << endl;
	cout << "     3. Calculate the Area of a Triangle" << endl;
	cout << "     4. Quit" << endl;
	cout << endl;
	cout << "     Enter your choice (1-4): "; // the prompt
	
	// get menu choice from the user
	cin >> menuChoice;
        
        // return the user's menu choice to the calling statement/calling code
        return menuChoice;
}

// prompts user for radius of circle, computes the area, and returns the area
float getAreaOfCircle()
{
    do{
        // prompt user for radius of the circle
        cout << "Enter the radius of the circle (must be greater than zero): ";
		
        // get the radius from user
        float radius;
        cin >> radius;
		
        if ( radius > 0 ) // if radius greater than zero, calculate the area
        {
            // calculate the area as PI times radius times radius
            float area = PI * radius * radius;
            return area; // return the calculated area to the calling code statement
            
        } // end of radius > 0 is true code block
        else
        {
            // radius cannot be less than or equal to zero
            cout << "Invalid Entry: Radius cannot be less than or equal to zero!!!" << endl;
        } // end of radius > 0 is false code block
    } while(true);
}

// prompts user for length, width of rectangle, computes the area, and returns the area
float getAreaOfRectangle()
{
    float length;
    float width;
    float area;
   
    do{
        // prompt user for length of the rectangle
        cout << "Enter the length of the rectangle (must be greater than zero): ";
		
        // get the length from user;
        cin >> length;
        if ( length > 0 ) break;
            
        // length cannot be less than or equal to zero
        cout << "Invalid Entry: Length cannot be less than or equal to zero!!!" << endl;
    } while(true); // do while loop for getting length
        
    do{        
        // prompt for width of the rectangle
        cout << "Enter the width of the rectangle (must be greater than zero): ";
		
        // get the width from user
        cin >> width;
        if ( width > 0 ) break;
                
        // width cannot be less than or equal to zero
        cout << "Invalid Entry: Width cannot be less than or equal to zero!!!" << endl;
    } while(true); // do while loop for getting width
			
                
    // calculate the area as length times width
    area = length * width;
            
    return area; // return the calculated area to the calling code statement
            
}

// prompts user for base and height of triangle, computes the area, and returns the area
float getAreaOfTriangle()
{
    float base;
    float height;
    float area;
   
    do{
        // prompt user for base of the triangle
        cout << "Enter the base of the triangle (must be greater than zero): ";
		
        // get the length from user;
        cin >> base;
        if ( base > 0 ) break;
            
        // base cannot be less than or equal to zero
        cout << "Invalid Entry: Base cannot be less than or equal to zero!!!" << endl;
    } while(true); // do while loop for getting base
        
    do{        
        // prompt for height of the triangle
        cout << "Enter the height of the triangle (must be greater than zero): ";
		
        // get the height from user
        cin >> height;
        if ( height > 0 ) break;
                
        // height cannot be less than or equal to zero
        cout << "Invalid Entry: Height cannot be less than or equal to zero!!!" << endl;
    } while(true); // do while loop for getting height
			
                
    // calculate the area as length times width
    area = 0.5 * base * height;
            
    return area; // return the calculated area to the calling code statement
}

// output the area and name of shape to terminal screen
void outputArea( float area, string shape_name)
{
    // output the result, with nicely formatted output
    cout << "Area of the " << shape_name << " is ";
    cout << setw( FIELD_WIDTH ) << setprecision( DECIMAL_DIGITS ) << fixed << showpoint;
    cout << area << endl;
}