/* 
 * File:   CircList.h
 * Author: Sili Guo
 * Created on March 22, 2017
 * Purpose: Assignment 2 --- Circularly Linked List
 */

#ifndef CIRCLIST_H
#define CIRCLIST_H

#include <iostream>
#include <iomanip>

template <class T>
class CircList {
private:

    struct Link {
        T data;
        struct Link *prev;
        struct Link *next;
    };

    Link *front;
    Link *last;
    int size;
public:
    CircList(T);
    ~CircList();
    void prntLst(int, int);
    void revrLst(int);
};

template <class T>
CircList<T>::CircList(T n) {
    size = n;
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
    last->next = front;
    front->prev = last;
}

template <class T>
CircList<T>::~CircList() {
    if (front == NULL)return; //Empty List? then leave
    do {
        Link *temp = front->next; //Traverse the list
        delete front; //Delete the front of the list
        front = temp; //Set the new front of the list
    } while (front != last); //Stop when we reach the end.
    delete front;
}

template <class T>
void CircList<T>::prntLst(int n, int perLine) {
    if (front == NULL) {
        cout << endl << "The list is empty." << endl << endl;
        return;
    }// Empty List? then leave
    int colCnt = 0; //Column counter
    Link *next = front; //Start at the front of the list
    cout << endl; //Put the beginning on a new line
    for (int i=0;i<size*n;i++){
        cout << setw(4) << next->data << " "; //Print the link
        if (colCnt++ % perLine == (perLine - 1))cout << endl;
        next = next->next; //Go to the next link
    } //Stop when your at the end
    cout << endl << endl;
}

template <class T>
void CircList<T>::revrLst(int perLine) {
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


#endif /* CIRCLIST_H */

