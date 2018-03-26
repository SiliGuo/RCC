/* 
 * File:   PrioList.h
 * Author: Sili Guo
 * Created on March 29, 2017
 * Purpose: Assignment 2 --- Pirority Linked List and Pirority Queue
 */

#ifndef PRIOLIST_H
#define PRIOLIST_H

#include <iostream>
#include <iomanip>

template <class T>
class PrioList {
private:

    struct Link {
        T data;
        struct Link *linkPtr;
    };

    Link *front; //First element in linked list
    Link *last; //Last element in linked list
    void endLst(); //Find last element
public:
    PrioList();
    ~PrioList();
    void prntLst(int); //Output linked list
    void push(T); //Add value
    T dequeue(); //For queue
    void prior(T);
};

template <class T>
PrioList<T>::PrioList() {
    front = NULL; //Set first element to NULL
    last = NULL; //Set last element to NULL
}

template <class T>
PrioList<T>::~PrioList() {
    if (front == NULL)return; //Empty List? then leave
    do {
        Link *temp = front->linkPtr; //Traverse the list
        delete front; //Delete the front of the list
        front = temp; //Set the new front of the list
    } while (front != NULL); //Stop when we reach the end.
}

template <class T>
void PrioList<T>::prntLst(int perLine) {
    if (front == NULL) {
        cout << endl << "The list is empty." << endl << endl;
        return;
    }// Empty List? then leave
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

template <class T>
void PrioList<T>::endLst() {
    Link *lnk = front; //Start the link at the front to find the end
    do {
        last = lnk; //Are we at the end yet?
        lnk = lnk->linkPtr; //Traverse to the next link
    } while (lnk != NULL); //Finally found the end when NULL
}

template <class T>
void PrioList<T>::push(T value) {
    Link *lnk = new Link; //Create new link
    lnk->data = value; //Fill value in new link
    lnk->linkPtr = NULL; //Point to NULL
    if (front == NULL) front = lnk; //If the link is the first element, set to front
    else {
        endLst();
        last->linkPtr = lnk; //Else, point last element to the new link
    }
}

template <class T>
T PrioList<T>::dequeue() {
    T value; //Store the dequeue value
    if (front == NULL) return 0; //return 0 if nothing in list
    else if (front->linkPtr == NULL) {//If only 1 element in list
        value = front->data; // Dequeue the data
        front = NULL; //Set front to NULL
    } else {
        value = front->data; //Dequeue the front data
        front = front->linkPtr; //Set front to the link it point to
    }
    return value; //Return dequeue value
}

template <class T>
void PrioList<T>::prior(T val) {
    Link *comp = front;
    Link *temp;
    while (comp->data != val) {
        temp = comp;
        comp = comp->linkPtr;
        if (comp == NULL) {
            cout << endl << "Did not find the value." << endl;
            return;
        }
    }
    temp->linkPtr = comp->linkPtr;
    comp->linkPtr = front;
    front = comp;
}
#endif /* PRIOLIST_H */

