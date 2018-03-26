/*
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: Final Project 4
 *    PROBLEM DEFINITION: read the binary file, bubblesort the array according to 
 *                        one column, and output the sorted array on screen
 *                  DATE: 06/08/2016
 *     SYSTEM - HARDWARE: Intel i7, 16GB, RAM
 *            - SOFTWARE: OS X El Capitan, NetBeans IDE 8.1
 *         Input Devices: Keyboard
 *        Output Devices: Screen                                                             
 */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// prototype for the function of bubblesort and outputArray
void bubblesort(float **, int, int, int);
void outputArray(float **, int, int);

int main() {
    // declare two variables named rows and cols represent the rows and columns of the array
    int rows, cols, column;
    string filename, newFilename; // declare a variable named filename

    // prompt user for the name of the file to read
    cout << "Enter the name of the input file you would like to read: ";
    cin >> filename;

    // declare a pointer point to 0
    float **ptr = 0;

    // declare a binary file named inputFile
    fstream inputFile;

    // open the binary file for read
    inputFile.open(filename.c_str(), ios::binary | ios::in);

    if (inputFile) // if successfully opened this will be true
    {

        // read the size of the rows and columns of the array
        inputFile.read(reinterpret_cast<char *> (&rows), sizeof (int));
        ptr = new float*[rows];
        inputFile.read(reinterpret_cast<char *> (&cols), sizeof (int));
        for (int r = 0; r < rows; r++) {
            *(ptr + r) = new float[cols];
        }

        // read in the actual array of float type
        for (int r = 0; r < rows; r++) {
            inputFile.read(reinterpret_cast<char *> (ptr[r]), sizeof (float)*cols);
        }

    } else {
        cout << "Could not open the file: " << filename << endl;
        return 1;
    }

    // if the file is successfully read, output the contents of the array
    cout << endl << "The file " << filename << " was successfully read." << endl << "Here are the contents of the array:" << endl << endl;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << setw(8) << left << ptr[r][c];
            if (c != cols - 1) cout << " ";
        }
        cout << endl;
    }

    cout << endl << "-----------------------------------------" << endl;
    // prompt user to enter the number of column for sort 
    do {
        cout << "Enter a number for column to sort: ";
        cin >> column;
        if (column <= 0 | column > cols) cout << "Invalid Input! Please enter again!" << endl;
    } while (column <= 0 | column > cols); // loop back if the number is less than zero or greater than the number of columns

    // bubblesort function
    bubblesort(ptr, rows, cols, column);

    // output the array after sorted
    cout << "The contents of sorted array are:" << endl << endl;

    // outputArray function
    outputArray(ptr, rows, cols);

    // prompt user for a new binary file name to write in the new array 
    cout << endl << "-----------------------------------------" << endl;
    cout << "Enter the name of the new output file you would like to create: ";
    cin >> newFilename;

    // declare a binary file named outputFile
    fstream outputFile;

    // open the file for write
    outputFile.open(newFilename, ios::binary | ios::out);
    // write the new array in the file
    if (outputFile) {

        // write the size of the rows and columns of the new array to the binary file
        outputFile.write(reinterpret_cast<char *> (&rows), sizeof (int));
        outputFile.write(reinterpret_cast<char *> (&cols), sizeof (int));

        // write out the actual array of float type
        for (int r = 0; r < rows; r++) {
            outputFile.write(reinterpret_cast<char *> (ptr[r]), sizeof (float)* cols);
        }
    } else {
        cout << "Could not open the file: " << newFilename << endl;
        return 1;
    }

    // if the file is written successfully
    cout << endl << "The file " << newFilename << " was successfully written." << endl;

    // close all the binary files and delete the memory
    outputFile.close();
    inputFile.close();
    for (int r = 0; r < rows; r++) {
        delete []ptr[r];
    }
    delete []ptr;

    return 0;
}

// implementation of the bubblesort function
void bubblesort(float *ptr[10], int rows, int cols, int column) {
    for (int i = 0; i < rows; i++) {
        for (int r = 0; r < rows - 1; r++) {
            if (ptr[r][column - 1] > ptr[r + 1][column - 1]) {
                for (int c = 0; c < cols; c++) {
                    float temp = ptr[r][c];
                    ptr[r][c] = ptr[r + 1][c];
                    ptr[r + 1][c] = temp;
                }
            }
        }
    }
}

// implementation of the outputArray function
void outputArray(float *ptr[10], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << setw(8) << left << ptr[r][c];
            if (c != cols - 1) cout << " ";
        }
        cout << endl;
    }
}