/*
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: Final Project 3
 *    PROBLEM DEFINITION: read the binary file, and output the sorted array on screen
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

int main() {
    // declare two variables named rows and cols represent the rows and columns of the array
    int rows, cols;
    string filename; // declare a variable named filename

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

    }
    else {
        cout << "Could not open the file: " << filename << endl;
        return 1;
    }

    // if the file is successfully read, output the contents of the array
    cout << endl << "The file " << filename << " was successfully read." << endl << "Here are the contents of the array:" << endl;
    cout << "------------------------------------" << endl;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << setw(8) << left << ptr[r][c];
            if (c != cols - 1) cout << " ";
        }
        cout << endl;
    }
    // close the file and delete memory
    inputFile.close();
    for (int r = 0; r < rows; r++) {
        delete []ptr[r];
    }
    delete []ptr;

    return 0;
}