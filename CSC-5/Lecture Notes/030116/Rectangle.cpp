/* Programmer: Sili Guo
 * Date: 3/1/16
 * Description: write a program to prompt the user to enter
 * the length and width of a rectangle. Compute the perimeter
 * and area of the rectangle. Output the results in a well worded
 * output to the terminal screen
 * 
 * Assumptions: inputs will be floating point, program is independent of
 * unit of measure (it is whatever the user choose it to be)
 * 
 * Variables: length    -length of rectangle
 *            width     -width of rectangle
 *            perimeter -perimeter of rectangle
 *            area      -area of rectangle
 */

#include <iostream>
using namespace std;

int main()
{
    float length, width, perimeter, area;
    cout << "Enter the length and width of the rectangle: ";
    cin >> length >> width;
    
    perimeter = 2 * length + 2 * width;
    area = length * width;
    
    cout << "Perimeter of rectangle is ";
    cout << perimeter << endl;
    
    cout << "Area of rectangle is ";
    cout << area << endl;
}