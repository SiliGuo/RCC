/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on March 15, 2017
 * Purpose: Review 3 - Vector: SimpleVector class template
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector {
private:
    T *aptr; // To point to the allocated array
    int arraySize; // Number of elements in the array
    void memError(); // Handles memory allocation errors
    void subError(); // Handles subscripts out of range
    void sizeAdj(int);// Adjust array size(double or half)

public:
    // Default constructor

    SimpleVector() {
        aptr = 0;
        arraySize = 0;
    }

    // Constructor declaration
    SimpleVector(int);

    // Copy constructor declaration
    SimpleVector(const SimpleVector &);

    // Destructor declaration
    ~SimpleVector();

    // Accessor to return the array size

    int size() const {
        return (arraySize - 1);
    }

    // Accessor to return a specific element
    T getElementAt(int position);

    // Overloaded [] operator declaration
    T &operator[](const int &);
    
    //Add one new value
    void push_back(T);
    
    //Subtract one value
    void pop_off();
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s) {
    arraySize = s;
    // Allocate memory for the array.
    try {
        aptr = new T [s];
    } catch (bad_alloc) {
        memError();
    }

    // Initialize the array.
    for (int count = 0; count < arraySize - 1; count++)
        *(aptr + count) = rand() % 10;
    //Mark the last element in array
    aptr[arraySize - 1] = -1;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj) {
    // Copy the array size.
    arraySize = obj.arraySize;

    // Allocate memory for the array.
    aptr = new T [arraySize];
    if (aptr == 0)
        memError();

    // Copy the elements of obj's array.
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector() {
    if (arraySize > 0)
        delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError() {
    cout << "ERROR:Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError() {
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub) {
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub) {
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

template <class T>
void SimpleVector<T>::sizeAdj(int size) {
    //First copy the original array
    T *temp = new T[arraySize];
    for (int i = 0; i < arraySize; i++) {
        temp[i] = aptr[i];
    }

    //Then delete the original array, and create a new array with
    delete [] aptr;
    aptr = new T[size];
    for (int i = 0; i < (size < arraySize ? size : arraySize); i++) {
        aptr[i] = temp[i];
    }
    arraySize = size;
}

template <class T>
void SimpleVector<T>::push_back(T value) {
    if (aptr[5] == -1 || aptr[10] == -1 || aptr[20] == -1 || aptr[40] == -1 || aptr[80] == -1)
        sizeAdj(2 * arraySize - 1);
    for (int i = 0; i < arraySize; i++) {
        if (aptr[i] == -1) {
            aptr[i] = value;
            aptr[i + 1] = -1;
            break;
        }
    }
}

template <class T>
void SimpleVector<T>::pop_off() {
    for (int i = 0; i < arraySize; i++) {
        if (aptr[i] == -1) {
            aptr[i] = 0;
            aptr[i - 1] = -1;
            break;
        }
    }
    if (aptr[5] == -1 || aptr[10] == -1 || aptr[20] == -1 || aptr[40] == -1 || aptr[80] == -1)
        sizeAdj((arraySize - 1) / 2 + 1);
}

#endif