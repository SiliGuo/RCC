/*
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: 2D Array Operation
 *    PROBLEM DEFINITION: Write a program that creates a two-dimensional array
 *                        initialized with test data. The program should have
 *                        6 functions of getTotal, getAverage, getRowTotal, 
 *                        getColumnTotal, getHighestInRow, getLowestInRow.
 *                  DATE: 5/3/2016
 *     SYSTEM - HARDWARE: Intel i7, 16GB, RAM
 *            - SOFTWARE: OS X Capitan, NetBeans IDE 8.1
 *         Input Devices: Keyboard
 *        Output Devices: Screen
 *                                                                          
 *   PROGRAM ASSUMPTIONS: declare two constant named ROWS & COLS, stored the value of the number of rows and columns
 *                        declare an array m as int type.
 *                        declare seven functions, showArray as void, getAverage as float, others as int type.
 *                                                              
 */

#include <iostream>
using namespace std;

// declare two constant variables named ROWS and COLS
const int ROWS = 5;
const int COLS = 4;

// declare seven prototype below
void showArray(int [][COLS], int); // show the array on screen
int getTotal(int [][COLS]); // calculate the sum of the all the values in array
float getAverage(int [][COLS], int); // calculate the average of all the values in array
int getRowTotal(int [][COLS], int); // calculate the sum of all the values of each row
int getColumnTotal(int [][COLS], int); // calculate the sum of all the values of each column
int getHighestInRow(int [][COLS], int); // get the highest value of each row
int getLowestInRow(int [][COLS], int); // get the lowest value of each row

// main function
int main()
{
    // declare an 2-D array named m, stored values with ROWS rows and COLS columns
    int m[ROWS][COLS]={ {  8, 3,22,23 }, // row 0
                        { 29,10, 5,24 }, // row 1
                        { 20,19,12, 7 }, // row 2
                        { 17,18,11,14 }, // row 3
                        { 37,13,16,31 } }; // row 4
    
        
    // output all the results on screen
    // show the array m on screen
    cout << "The array m: " << endl;
    showArray(m,ROWS);
    cout << "----------------------------------------------------" << endl;
    
    // output the total of all the values in the array
    cout << "The total of all the values in the array is: " << getTotal(m) << endl << endl;
    
    // output the average of all the values in the array
    cout << "The average of all the values in the array is: " << getAverage(m,ROWS) << endl << endl;
    
    // output the total of all values in each row
    cout << "The total of all the values in each rows are: " << endl;
    for(int r=0;r<ROWS;r++) // use for loop to output the result of each row
    {
        cout << "row " << r << " is: " << getRowTotal(m,r) << endl;
    } // end of for loop block
    cout << endl; // extra blank line
    
    // output the total of all values in each column
    cout << "The total of all the values in each column are: " << endl;
    for(int c=0;c<COLS;c++) // use for loop to output the result of each column
    {
        cout << "column " << c << " is: " << getColumnTotal(m,c) << endl;
    } // end of for loop block
    cout << endl; // extra blank line
    
    // output the highest values in each row
    cout << "The highest values in each rows are: " << endl;
    for(int r=0;r<ROWS;r++) // use for loop to output the result of each row
    {
        cout << "row " << r << " is: " << getHighestInRow(m,r) << endl;
    } // end of for loop
    cout << endl;
    
    // output the lowest values in each row
    cout << "The lowest values in each rows are: " << endl;
    for(int r=0;r<ROWS;r++) // use for loop to output the result of each row
    {
        cout << "row " << r << " is: " << getLowestInRow(m,r) << endl;
    } // end of for loop
    
}
// function implementations
// function shows the array on screen
void showArray(int m[][COLS],int ROWS)
{
    for(int r=0;r<ROWS;r++)
    {
        for(int c=0;c<COLS;c++)
        {
            cout << m[r][c];
            if (c != COLS-1) cout << ", ";
        }
        cout << endl;
    }
}

// function calculate the sum
int getTotal(int m[][COLS])
{
    int sum=0; // declare a local variable named sum
    
    // use two for loop to calculate all the values in 2-D array
    for(int r=0;r<ROWS;r++)
    {
        for(int c=0;c<COLS;c++)
        {
            sum += m[r][c]; // calculate sum by adding array m[r][c] to itself
        } // end of for loop in block
    } // end of for loop out block
    return sum; // return result
} // end of function block

// function calculate the average
float getAverage(int m[][COLS], int ROWS)
{
    // declare two variables named sum and average as float type
    float sum=0.0;
    float average=0;
    
    // use two for loop to calculate all values in array
    for(int r=0;r<ROWS;r++)
    {
        for(int c=0;c<COLS;c++)
        {
            sum += m[r][c]; // calculate sum
            average = sum/(ROWS*COLS); // calculate average by dividing sum by (ROWS times COLS)
        } // end of for loop in block
    } // end of for loop out block
    return average; // return result
} // end of function block

// function calculate the sum of each row
int getRowTotal(int m[][COLS], int rw)
{
    // declare a variable named sum as int type
    int sum=0;
        
    // use for loop to calculate sum of each row
    for(int c=0;c<COLS;c++)
        {
            sum += m[rw][c]; // calculate sum
        } // end of for loop block
    return sum; // return result
} // end of function block

// function calculate the sum of each column
int getColumnTotal(int m[][COLS], int cl)
{
    // declare a variable named sum as int type
    int sum=0;
        
    // use for loop to calculate sum of each column
    for(int r=0;r<ROWS;r++)
        {
            sum += m[r][cl]; // calculate sum
        } // end of for loop block
        return sum; // return result
} // end of function block

// function get the highest value of each row
int getHighestInRow(int m[][COLS], int rm)
{
    // declare a variable named max, stored value of the first value of each row
    int max = m[rm][0];
    
    // use for loop to compare each value of the row with max, get the max value of the row
    for(int c=0;c<COLS;c++)
    {
        if ( m[rm][c] > max )
        {
            max = m[rm][c];
        } // end of if block 
    } // end of for loop block
    return max; // return result
} // end of function block

// function get the lowest value of each row
int getLowestInRow(int m[][COLS], int rm)
{
    // declare a variable named min, stored value of the first value of each row
    int min = m[rm][0];
    
    // use for loop to compare each value of the row with max, get the max value of the row
    for(int c=0;c<COLS;c++)
    {
        if ( m[rm][c] < min )
        {
            min = m[rm][c];
        } // end of if block
    } // end of for loop block
    return min; // return result
} // end of function block