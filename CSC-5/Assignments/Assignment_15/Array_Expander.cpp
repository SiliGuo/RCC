/*
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: Array Expander
 *    PROBLEM DEFINITION: write an array, and use function to double its size,
 *                        initialize all other items as zero
 *                  DATE: 05/24/2016
 *     SYSTEM - HARDWARE: Intel i7, 16GB, RAM
 *            - SOFTWARE: OS X El Capitan, NetBeans IDE 8.1
 *         Input Devices: Keyboard
 *        Output Devices: Screen
 *                                                                          
 *   PROGRAM ASSUMPTIONS: declare array as int type
 *                        the function is declared as int type
 *                                                              
 */
#include <iostream>
using namespace std;

//prototype of arrayExpand function
int* arrayExpand(int*, int);

int main() {
    // declare a constant of the array size
    const int SIZE = 10;
    // declare an array of the int type
    int arr [SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //point arr to *ptr
    int* ptr = arr;

    // use for loop to output array to the screen
    for (int i = 0; i < SIZE; i++)
        cout << *(ptr + i) << " ";

    cout << endl;

    ptr = arrayExpand(arr, SIZE); //Used to assign ptr to the memory location of the return

    // use for loop to output the new array 
    for (int i = 0; i < SIZE * 2; i++)
        cout << *(ptr + i) << " ";
    cout << endl;

    return 0;
}

//  implementation of the arrayExpand function 
int* arrayExpand(int* arr, int size) {
    //double the original size and stored in sizeExpand
    int* sizeExpand = new int[size * 2];

    // use for loop to get the data from original array
    for (int i = 0; i < size; i++)
        *(sizeExpand + i) = *(arr + i);

    //initialize all unused data to 0
    for (int i = size; i < size * 2; i++)
        *(sizeExpand + i) = 0;

    // return the new array
    return sizeExpand;
}
