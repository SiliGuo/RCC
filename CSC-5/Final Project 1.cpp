/*
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: Final Project 1
 *    PROBLEM DEFINITION: prompt user to enter the name of the file for write, 
 *                        and prompt for the number of the rows and columns, 
 *                        prompt for values, and store the array in the binary file
 *                  DATE: 06/08/2016
 *     SYSTEM - HARDWARE: Intel i7, 16GB, RAM
 *            - SOFTWARE: OS X El Capitan, NetBeans IDE 8.1
 *         Input Devices: Keyboard
 *        Output Devices: Screen                                                             
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    // declare two variables named rows and cols represent the rows and columns of an array
    int rows, cols;
    string filename; // declare a variable named filename of string type

    // prompt user for the rows and columns of the 2-D Array, and loop if user enter a negative number
    do {
        cout << "Enter the number of rows for your array (Must be a positive integer): ";
        cin >> rows;
        if (rows <= 0) cout << endl << "Invalid Input! Please enter a positive number!!!" << endl;
    } while (rows <= 0); // end of do while block

    do {
        cout << "Enter the number of columns for your array (Must be a positive integer): ";
        cin >> cols;
        if (rows <= 0) cout << endl << "Invalid Input! Please enter a positive number!!!" << endl;
    } while (cols <= 0); // end of do while loop

    // prompt user for the binary file name
    cout << "Enter the name of the output file you would like to create: ";
    cin >> filename;
    cout << "------------------------------------------------------------" << endl;

    // use pointer to point to the array's rows and columns as float type.
    float **ptr = new float*[rows];

    for (int r = 0; r < rows; r++) {
        *(ptr + r) = new float[cols];

        // prompt user for the value of the array
        for (int c = 0; c < cols; c++) {
            cout << "Enter a value of floating type for row #" << r + 1 << ", column # " << c + 1 << ": ";
            cin >> ptr[r][c];
        }
    }

    // declare a binary file named outputFile
    fstream outputFile;

    // open the file for write
    outputFile.open(filename, ios::binary | ios::out);
    // write the array in the file
    if (outputFile) {

        // write the size of the rows and columns of the array to the binary file
        outputFile.write(reinterpret_cast<char *> (&rows), sizeof (int));
        outputFile.write(reinterpret_cast<char *> (&cols), sizeof (int));
        // write out the actual array of float type
        for (int r = 0; r < rows; r++) {
            outputFile.write(reinterpret_cast<char *> (ptr[r]), sizeof (float)* cols);
        }
    }
    else {
        cout << "Could not open the file: " << filename << endl;
        return 1;
    }

    // if the file is written successfully
    cout << endl << "The file " << filename << " was successfully written." << endl;

    // close the binary file and delete the memory
    outputFile.close();
    for (int r = 0; r < rows; r++) {
        delete []ptr[r];
    }
    delete[]ptr;

    return 0;
}