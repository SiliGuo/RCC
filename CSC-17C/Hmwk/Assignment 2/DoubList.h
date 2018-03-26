/* 
 * File:   linkList.h
 * Author: Sili Guo
 * Created on March 29, 2017
 * Purpose: Assignment 2 --- Doubly Linked List
 */

#ifndef DOUBLIST_H
#define DOUBLIST_H

#include <iostream>
#include <iomanip>

template <class T>
class DoubList {
private:

    struct Link {
        T data;
        struct Link *prev;
        struct Link *next;
    };

    Link *front;
    Link *last;
public:
    DoubList(T);
    ~DoubList();
    void prntLst(int);
    void revrLst(int);
};

template <class T>
DoubList<T>::DoubList(T n) {
    front = new Link; //Create the front link
    Link *lnk = front; //Set the front equal to the traversal link
    lnk->data = n--; //Fill the front with data
    lnk->next = NULL; //Point the front to no where
    lnk->prev = NULL;
    do {
        Link *end = new Link; //Create a new link
        end->data = n--; //Fill with data
        end->next = NULL; //Point to no where
        end->prev = lnk;
        lnk->next = end; //Previous link will point to the end
        lnk = end; //Move to the end
    } while (n > 0); //Repeat until only 1 left
    last = lnk; //Set last element to last
}

template <class T>
DoubList<T>::~DoubList() {
    if (front == NULL)return; //Empty List? then leave
    do {
        Link *temp = front->next; //Traverse the list
        delete front; //Delete the front of the list
        front = temp; //Set the new front of the list
    } while (front != NULL); //Stop when we reach the end.
}

template <class T>
void DoubList<T>::prntLst(int perLine) {
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
        next = next->next; //Go to the next link
    } while (next != NULL); //Stop when your at the end
    cout << endl << endl;
}

template <class T>
void DoubList<T>::revrLst(int perLine) {
    if (last == NULL) {
        cout << endl << "The list is empty." << endl << endl;
        return;
    }// Empty List? then leave
    int colCnt = 0; //Column counter
    Link *next = last; //Start at the front of the list
    cout << endl; //Put the beginning on a new line
    do {
        cout << setw(4) << next->data << " "; //Print the link
        if (colCnt++ % perLine == (perLine - 1))cout << endl;
        next = next->prev; //Go to the next link
    } while (next != NULL); //Stop when your at the end
    cout << endl << endl;
}
#endif /* DOUBLIST_H */