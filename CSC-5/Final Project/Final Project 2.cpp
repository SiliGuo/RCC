/*
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: Final Project 2
 *    PROBLEM DEFINITION: prompt user to enter the name of the file for write, 
 *                        and prompt for the number of the rows and columns, 
 *                        create random numbers, and store the array in the binary file
 *                  DATE: 06/08/2016
 *     SYSTEM - HARDWARE: Intel i7, 16GB, RAM
 *            - SOFTWARE: OS X El Capitan, NetBeans IDE 8.1
 *         Input Devices: Keyboard
 *        Output Devices: Screen                                                             
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    // declare two variables named rows and cols represent the rows and columns of an array
    int rows, cols;
    // declare a variable named max, stored the max value of the random number in it
    float max=100.0;
    string filename; // declare a variable named filename of string type

    // create a seed based on time for random number
    srand(static_cast<unsigned int> (time(0)));

    // prompt user for the rows and columns of the 2-D Array, and loop if user enter a negative number
    do {
        cout << "Enter the number of rows for your array (Must be a positive integer): ";
        cin >> rows;
    } while (rows <= 0); // end of do while block

    do {
        cout << "Enter the number of columns for your array (Must be a positive integer): ";
        cin >> cols;
    } while (cols <= 0); // end of do while block

    // prompt user for the binary file name
    cout << "Enter the name of the output file you would like to create: ";
    cin >> filename;

    // use pointer to point to the array's rows and columns as float type.
    float **ptr = new float*[rows];

    for (int r = 0; r < rows; r++) {

        *(ptr + r) = new float[cols];

        // create random numbers for the 2-D array
        for (int c = 0; c < cols; c++) {
            *(*(ptr + r) + c) = ((float)rand()/(float)(RAND_MAX)) * max;
        }
    }

    // declare a binary file named outputFile
    fstream outputFile;

    // open the file for write
    outputFile.open(filename, ios::binary | ios::out);
    
    if (outputFile) {

        // write the size of the rows and columns of the array
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
    for(int r=0;r<rows;r++) {
        delete []ptr[r];
    }
    delete[]ptr;
    
    return 0;
}