/* 
 * File:   linkList.h
 * Author: Sili Guo
 * Created on March 22, 2017
 * Purpose: Assignment 1 Coding_1: Linked List with template
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

    Link *front;
    Link *last;
public:
    LinkList(T);
    ~LinkList();
    void prntLst(int);
    void endLst();
    void addFrst(T);
    void addLast(T);
    void addBefr(int, T);
    void addAftr(int, T);
};

template <class T>
LinkList<T>::LinkList(T n) {
    front = new Link; //Create the front link
    Link *prev = front; //Set the front equal to the traversal link
    prev->data = n--; //Fill the front with data
    prev->linkPtr = NULL; //Point the front to no where
    do {
        Link *end = new Link; //Create a new link
        end->data = n--; //Fill with data
        end->linkPtr = NULL; //Point to no where
        prev->linkPtr = end; //Previous link will point to the end
        prev = end; //Move to the end
    } while (n > 0); //Repeat until filled
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
void LinkList<T>::endLst() {
    Link *lnk = front; //Start the link at the front to find the end
    do {
        last = lnk; //Are we at the end yet?
        lnk = lnk->linkPtr; //Traverse to the next link
    } while (lnk != NULL); //Finally found the end when NULL
}

template <class T>
void LinkList<T>::addFrst(T val) {
    Link *first = new Link; //Create a new link
    first->data = front->data; //Set its data equal to front
    first->linkPtr = front->linkPtr; //Point it to the next link
    front->data = val; //Fill front with value
    front->linkPtr = first; //Point it to the new link
}

template <class T>
void LinkList<T>::addLast(T val) {
    endLst();
    Link *nx2last = last; //Find the last link in the list
    Link *last = new Link; //Create a new last link
    last->data = val; //Fill with the value desire
    last->linkPtr = NULL; //Point the added link to no where
    nx2last->linkPtr = last; //Put the last link on the end
}

template <class T>
void LinkList<T>::addBefr(int pos, T val) {
    if (pos < 1) return; //Invalid position
    else if (pos == 1) addFrst(val); //pos == 1? Same as add to front
    else {
        Link *lnk = front; //Create a new link
        for (int i = 0; i < pos - 2; i++) {
            lnk = lnk->linkPtr; //Point to next link till the position given
            if (lnk == NULL) return; //If point to last link, leave
        }
        Link *before = new Link; //Create a new link
        before->data = val; //Fill with value
        before->linkPtr = lnk->linkPtr; //Point to the position found
        lnk->linkPtr = before; //Connect the link from previous link
    }
}

template <class T>
void LinkList<T>::addAftr(int pos, T val) {
    if (pos < 1) return; // Invalid position
    Link *lnk = front; //Set a link equal to front
    for (int i = 0; i < pos - 1; i++) {
        lnk = lnk->linkPtr; //Point to next link till the position given
        if (lnk == NULL) return; //If point to last link, leave
    }
    Link *after = new Link; //Create a new link
    after->data = val; //Fill with value
    after->linkPtr = lnk->linkPtr; //Point to the next link
    lnk->linkPtr = after; //Let position found point to the new link
}
#endif /* LINKLIST_H */

