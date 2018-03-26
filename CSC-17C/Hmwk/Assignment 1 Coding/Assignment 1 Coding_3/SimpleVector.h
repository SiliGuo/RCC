/* 
 * File:   SimpleVector.h
 * Author: Sili Guo
 * Created on March 22, 2017
 * Purpose: Assignment 1 Coding_1: SimpleVector class template
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <iomanip>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector {
private:

    struct Link {
        T data;
        struct Link *linkPtr;
    };

    Link *front; // To point to the first element of linked list
    int arraySize; // Number of elements in the array
    Link *last; //To point to the last element of linked list
    void memError(); // Handles memory allocation errors
    void subError(); // Handles subscripts out of range
    void endLst(); //Find the last element in linked list

public:
    // Default constructor

    SimpleVector() {
        front = NULL;
        arraySize = 0;
    }

    // Constructor declaration
    SimpleVector(int);

    // Destructor declaration
    ~SimpleVector();

    // Accessor to return the array size

    int size() const {
        return (arraySize - 1);
    }

    // Accessor to return a specific element
    void prntLst(int);

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
    //    try {
    front = new Link; //Create the front link
    Link *prev = front; //Set the front equal to the traversal link
    prev->data = rand() % 10; //Fill the front with data
    s--;
    prev->linkPtr = NULL; //Point the front to no where
    do {
        Link *end = new Link; //Create a new link
        end->data = rand() % 10; //Fill with data
        s--;
        end->linkPtr = NULL; //Point to no where
        prev->linkPtr = end; //Previous link will point to the end
        prev = end; //Move to the end
    } while (s > 0); //Repeat until filled
    last = NULL; //Set last element to NULL
    //    } catch (bad_alloc) {
    //        memError();
    //    }
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector() {
    if (front == NULL)return; //Empty List? then leave
    do {
        Link *temp = front->linkPtr; //Traverse the list
        delete front; //Delete the front of the list
        front = temp; //Set the new front of the list
    } while (front != NULL); //Stop when we reach the end.
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
void SimpleVector<T>::prntLst(int perLine) {
    int colCnt = 0; //Column counter
    Link *next = front; //Start at the front of the list
    cout << endl; //Put the beginning on a new line
    do {
        cout << setw(4) << next->data << " "; //Print the link
        if (colCnt++ % perLine == (perLine - 1))cout << endl;
        next = next->linkPtr; //Go to the next link
    } while (next != NULL); //Stop when your at the end
    cout << endl;
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

//template <class T>
//T &SimpleVector<T>::operator[](const int &sub) {
//    if (sub < 0 || sub >= arraySize)
//        subError();
//    return aptr[sub];
//}

template <class T>
void SimpleVector<T>::endLst() {
    Link *lnk = front; //Start the link at the front to find the end
    do {
        last = lnk; //Are we at the end yet?
        lnk = lnk->linkPtr; //Traverse to the next link
    } while (lnk != NULL); //Finally found the end when NULL
}

template <class T>
void SimpleVector<T>::push_back(T value) {
    endLst();
    Link *nx2last = last; //Find the last link in the list
    Link *last = new Link; //Create a new last link
    last->data = value; //Fill with the value desire
    last->linkPtr = NULL; //Point the added link to no where
    nx2last->linkPtr = last; //Put the last link on the end
}

template <class T>
void SimpleVector<T>::pop_off() {
    Link *lnk = front;
    endLst();
    while (lnk->linkPtr != last) {
        lnk = lnk->linkPtr;
    }
    lnk->linkPtr = NULL;
}

#endif