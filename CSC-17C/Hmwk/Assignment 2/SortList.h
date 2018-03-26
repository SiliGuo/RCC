/* 
 * File:   SortList.h
 * Author: Sili Guo
 * Created on March 29, 2017
 * Purpose: Assignment 2 --- Sorted Linked List
 */

#ifndef SORTLIST_H
#define SORTLIST_H

#include <iostream>
#include <iomanip>
#include <cstdlib>

template <class T>
class SortList {
private:

    struct Link {
        T data;
        struct Link *linkPtr;
    };

    Link *front;
    Link *last;
    int size;
    void endLst();
    void swap(int, int);
public:
    SortList(T);
    ~SortList();
    void prntLst(int);
    void sort();
};

template <class T>
SortList<T>::SortList(T n) {
    size = n;
    front = new Link; //Create the front link
    Link *prev = front; //Set the front equal to the traversal link
    prev->data = rand() % 10; //Fill the front with data
    n--;
    prev->linkPtr = NULL; //Point the front to no where
    do {
        Link *end = new Link; //Create a new link
        end->data = rand() % 10; //Fill with data
        n--;
        end->linkPtr = NULL; //Point to no where
        prev->linkPtr = end; //Previous link will point to the end
        prev = end; //Move to the end
    } while (n > 0); //Repeat until filled
    last = NULL; //Set last element to NULL
}

template <class T>
SortList<T>::~SortList() {
    if (front == NULL)return; //Empty List? then leave
    do {
        Link *temp = front->linkPtr; //Traverse the list
        delete front; //Delete the front of the list
        front = temp; //Set the new front of the list
    } while (front != NULL); //Stop when we reach the end.
}

template <class T>
void SortList<T>::prntLst(int perLine) {
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
    cout << endl << endl;
}

template <class T>
void SortList<T>::endLst() {
    Link *lnk = front; //Start the link at the front to find the end
    do {
        last = lnk; //Are we at the end yet?
        lnk = lnk->linkPtr; //Traverse to the next link
    } while (lnk != NULL); //Finally found the end when NULL
}

template <class T>
void SortList<T>::sort() {
    Link *prev = front;
    Link *next = front->linkPtr;
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size;j++) {
            if (prev->data > next->data)
                swap(i, j);
            next = next->linkPtr;
        }
        prev = prev->linkPtr;
        next = prev->linkPtr;
    }
}

template <class T>
void SortList<T>::swap(int a, int b) {
    if (a < 0 || a > size - 2 || b < 1 || b > size - 1) return;
    Link *lnk1 = front;
    Link *lnk2 = front;
    T prev, next;
    for(int i=0;i<a;i++){
        lnk1 = lnk1->linkPtr;
    }
    prev = lnk1->data;
    for(int i=0;i<b;i++){
        lnk2 = lnk2->linkPtr;
    }
    next = lnk2->data;
    lnk1->data = next;
    lnk2->data = prev;



}
#endif /* SORTLIST_H */

