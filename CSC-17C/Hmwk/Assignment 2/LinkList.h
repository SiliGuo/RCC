/* 
 * File:   linkList.h
 * Author: Sili Guo
 * Created on March 29, 2017
 * Purpose: Assignment 2 --- Stack and Queue
 */

#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
#include <iomanip>

template <class T>
class LinkList {
private:

    struct Link {
        T data;
        struct Link *linkPtr;
    };

    Link *front; //First element in linked list
    Link *last; //Last element in linked list
    void endLst(); //Find last element
public:
    LinkList();
    ~LinkList();
    void prntLst(int); //Output linked list
    void push(T); //Add value
    T pop(); //For stack
    T dequeue(); //For queue
};

template <class T>
LinkList<T>::LinkList() {
    front = NULL; //Set first element to NULL
    last = NULL; //Set last element to NULL
}

template <class T>
LinkList<T>::~LinkList() {
    if (front == NULL)return; //Empty List? then leave
    do {
        Link *temp = front->linkPtr; //Traverse the list
        delete front; //Delete the front of the list
        front = temp; //Set the new front of the list
    } while (front != NULL); //Stop when we reach the end.
}

template <class T>
void LinkList<T>::prntLst(int perLine) {
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
void LinkList<T>::endLst() {
    Link *lnk = front; //Start the link at the front to find the end
    do {
        last = lnk; //Are we at the end yet?
        lnk = lnk->linkPtr; //Traverse to the next link
    } while (lnk != NULL); //Finally found the end when NULL
}

template <class T>
void LinkList<T>::push(T value) {
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
T LinkList<T>::pop() {
    T value; //Store the pop value
    if (front == NULL) return 0; //return 0 if nothing in list
    else if (front->linkPtr == NULL) {//If only 1 element in list
        value = front->data; // Pop the data
        front = NULL; //Set front to NULL
    } else {
        endLst(); //Find last element
        value = last->data; //Store data in last element
        Link *temp = front;
        while (temp->linkPtr != last) {
            temp = temp->linkPtr;
        }//Find the link before last element
        temp->linkPtr = NULL; //Point to 0
    }
    return value; //Return the pop value
}

template <class T>
T LinkList<T>::dequeue() {
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
#endif /* LINKLIST_H */

