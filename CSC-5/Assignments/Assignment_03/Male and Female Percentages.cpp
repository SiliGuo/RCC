/* Programmer: Sili Guo
 * Date: 3/3/16
 * Description: This is a program that prompt to the user
 * to enter the number of male students and female students.
 * Compute the male percentage and the female percentage in 
 * class. Output the result in a well worded output to the 
 * terminal screen. (Exercise 3.5, pg 142 in Gaddis Text)
 * 
 * Assumption: inputs will be floating point
 * 
 * Variables: male          -number of male students in class
 *            female        -number of female students in class
 *            total         -number of total students in class
 *            percentage1   -male percentage in class
 *            percentage2   -female percentage in class
 */

#include <iostream>
using namespace std;

int main()
{
    // Declare five variables of floating point type
    float male, female, total, percentage1, percentage2;
    
    // Get the number of male students and female students in class
    cout << "Enter the number of male student in class is: ";
    cin >> male;
    cout << "Enter the number of female student in class is: ";
    cin >> female;
    
    /* Calculate number of total students in class by adding number 
    of male students and number of female students, stored in total */
    total = male + female;
    
    // Display the number of total students in class on screen
    cout << "The number of total students in class is: " << total << endl;
    
    /* Calculate male percentage in class by dividing number of male
     students by number of total students in class, stored in percentage1 */
    percentage1 = 100 * (male / total);
   
    // Display the male percentage on screen
    cout << "The male percentage in class is: " << percentage1;
    cout << "%" << endl;
    
    /* Calculate female percentage in class by dividing number of female
     students by number of total students in class, stored in percentage2 */
    percentage2 = 100 * (female / total);
    
    // Display the female percentage on screen
    cout << "The female percentage in class is: " << percentage2;
    cout << "%" << endl;
}