/*
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: Final Project 5
 *    PROBLEM DEFINITION: read the binary file, bubblesort the array according to 
 *                        one column, search the value prompted by user,
 *                        and output the result on screen
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

void bubblesort(float **, int, int, int);
void outputArray(float **, int, int);
int binary_search(float **, int, int, float);

int main() {
    // declare two variables named rows and cols represent the rows and columns of the array
    int rows, cols, column;
    // declare a variable named search_value in float type
    float search_value;
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
        cout << "Enter the number for column to search: ";
        cin >> column;
        if (column <= 0 | column > cols) cout << "Invalid Input! Please enter again!" << endl;
    } while (column <= 0 | column > cols); // loop back if the number is less than zero or greater than the number of columns

    // bubblesort function
    bubblesort(ptr, rows, cols, column);

    // output the array after sorted
    cout << "The contents of sorted array are:" << endl << endl;
    
    // outputArray function
    outputArray(ptr, rows, cols);

    // prompt user to enter the value to search
    cout << endl << "-----------------------------------------" << endl;
    cout << "Enter a value to search: ";
    cin>>search_value;
    cout << endl; 
    
    int iterations = 0; // declare a variable named iterations to record how many iterations needed to find the value
    int index_found = binary_search(ptr, rows, column, search_value);
    bool found = index_found != -1; // if index_found = -1, then false, otherwise expression is true 

    // nice output 
    cout << endl << search_value << " was ";
    if (!found) cout << "not ";
    cout << "found";
    if (found) cout << " at row # " << index_found+1 << endl;
    else cout << "!" << endl;
    cout << "Took " << iterations << " iterations to execute." << endl;

    // close the file and delete memory
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

// implementation of binary_search function
int binary_search(float *ptr[10], int rows, int column, float search_value) {
    int first = 0, last = rows - 1, iterations = 0, mid;

    iterations++;
    while (first <= last) {
        mid = (first + last) / 2;
        // debug code below	 
        cout << "Iteration " << iterations << ": first=" << first << ", last=" << last << ", mid=" << mid << endl;

        if (ptr[mid][column - 1] == search_value) return mid;
        else if (ptr[mid][column - 1] < search_value) first = mid + 1;
        else last = mid - 1;

        iterations++;
    }
    return -1;
}