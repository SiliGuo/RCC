/* Programmer: Sili Guo
 * Date: 3/15/16
 * Tittle: Minimum/Maximum Values
 * Description: This is a program that prompt to the user to
 * enter any two numbers, compare two numbers to determine 
 * which number is larger and which number is the smaller, 
 * or if both numbers are equal. Output the result on the
 * terminal screen.
 * 
 * Assumption: inputs will be floating point
 * 
 * Variables: num1      -the first number
 *            num2      -the second number
 */

#include <iostream>
using namespace std;

int main()
{
    // Declare two variables in floating types.
    float num1, num2;
    
    // Enter the first number
    cout << "Enter the first number in your mind: ";
    cin >> num1;
    
    // Enter the second number
    cout << "Enter the second number in your mind: ";
    cin >> num2;
    
    // First compare if the first number is larger than the second one.
    if (num1 > num2)
        cout << "The first number you entered is larger than the second one." << endl;
    // Then compare if the first number is smaller than the second one.
    else if (num1 < num2)
        cout << "The first number you entered is smaller than the second one." << endl;
    // If these two numbers do not fit both conditions above, they are equal to each other.
    else
        cout << "The two numbers you entered are equal" << endl;
            
}