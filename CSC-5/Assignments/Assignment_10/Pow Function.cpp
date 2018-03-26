/*
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: Pow Function
 *    PROBLEM DEFINITION: Suppose that we do not have the pow function and we
 *                        we need to declare pow functions of three implementations.
 *                        Prompt user to enter numbers to test this program.
 *                  DATE: 4/19/16
 *     SYSTEM - HARDWARE: Mac Pro
 *            - SOFTWARE: NetBeans IDE 8.1
 *         Input Devices: Keyboard
 *        Output Devices: Screen
 *                                                                          
 *   PROGRAM ASSUMPTIONS: The three implementations data types are long, float and double.
 *                                                              
 */

#include <iostream>
using namespace std;

// function prototypes for pow function as data types of long, float, and double
long pow(long, int);
float pow(float, int);
double pow(double, int);

// main function
int main()
{
    // declare two variables named a1 as long int type, and n1 as int type
    long a1;
    int n1;
    
    // prompt the user to enter the value of a1 and n1
    cout << "Enter a long integer number: ";
    cin >> a1;
    
    cout << "Enter an integer number for the power: ";
    cin >> n1;
    
    // declare two variables named a2 as floating point type, and n2 as int type
    float a2;
    int n2;
    
    // prompt the user to enter the value of a2 and n2
    cout << "Enter a floating point number: ";
    cin >> a2;
    
    cout << "Enter an integer number for the power: ";
    cin >> n2;
    
    // declare two variables named a3 as double type, and n3 as int type
    double a3;
    int n3;
    
    // prompt the user to enter the value of a3 and n3
    cout << "Enter a number as double type: ";
    cin >> a3;
    
    cout << "Enter an integer number for the power: ";
    cin >> n3;
    
    // calculate result by using the function we called
    long result = pow( a1, n1 );
    float result2 = pow( a2, n2 );
    double result3 = pow( a3, n3 );
    
    // output the results on the screen in formal
    cout << "The result of " << a1 << " to the power of " << n1 << " is " << result << endl;
    cout << "The result of " << a2 << " to the power of " << n2 << " is " << result2 << endl;
    cout << "The result of " << a3 << " to the power of " << n3 << " is " << result3 << endl;
    
    return 0;
}

// function implementation
long pow( long a, int n )
{
    // declare three variables in int type
    int count = n;
    long power = 1, power2 = a;
    
    while ( count!=0 ) // use while loop to calculate the power function 
    {
        if ( count%2 == 1 )
        {
            power *= power2;
            count--;
        } // end of if ( count%2 == 1 ) block
        
        power2 *= power2;
        count /= 2;
    } // end of while( count!=0 ) loop block
    
    return power; // return the result
}

float pow( float a, int n )
{
    // declare three variables in int type
    int count = n;
    float power = 1, power2 = a;
    
    while ( count!=0 ) // use while loop to calculate the power function 
    {
        if ( count%2 == 1 )
        {
            power *= power2;
            count--;
        } // end of if ( count%2 == 1 ) block
        
        power2 *= power2;
        count /= 2;
    } // end of while( count!=0 ) loop block
    
    return power; // return the result
}

double pow( double a, int n )
{
    // declare three variables in int type
    int count = n;
    double power = 1, power2 = a;
    
    while ( count!=0 ) // use while loop to calculate the power function 
    {
        if ( count%2 == 1 )
        {
            power *= power2;
            count--;
        } // end of if ( count%2 == 1 ) block
        
        power2 *= power2;
        count /= 2;
    } // end of while( count!=0 ) loop block
    
    return power; // return the result
}