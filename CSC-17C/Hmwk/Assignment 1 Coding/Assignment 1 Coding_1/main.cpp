/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on March 22, 2017
 * Purpose: Assignment 1 Coding_1: Singularly Linked List
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "Link.h"
//Global Constants

//Function Prototypes
Link *fillLst(int);
void prntLst(Link *, int);
void destLst(Link *);
Link *endLst(Link *);
void addFrst(Link *, int);
void addLast(Link *, int);
void addBefr(Link *, int, int);
void addAftr(Link *, int, int);

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    Link *lnkList;
    int howMany = 10, perLine = 5;

    //Input Data
    lnkList = fillLst(howMany);

    //Print the list
    cout << "Original linked list:" << endl;
    prntLst(lnkList, perLine);

    //Add to the end
    addLast(lnkList, 0);
    cout << "Add 0 to the end:" << endl;
    prntLst(lnkList, perLine);

    //Add to the front
    addFrst(lnkList, 11);
    cout << "Add 11 to the front:" << endl;
    prntLst(lnkList, perLine);

    //Add before
    addBefr(lnkList, 3, 12);
    cout << "Add 12 before 3rd element: " << endl;
    prntLst(lnkList, perLine);

    //Add after
    addAftr(lnkList, 5, 13);
    cout << "Add 13 after 5th element: " << endl;
    prntLst(lnkList, perLine);

    //Destroy the List
    destLst(lnkList);

    //Exit Stage Right
    return 0;
}

Link *fillLst(int n) {
    Link *front = new Link; //Create the front link
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
    return front; //Return the beginning of the Linked list
}

void prntLst(Link *front, int perLine) {
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

void destLst(Link *front) {
    if (front == NULL)return; //Empty List? then leave
    do {
        Link *temp = front->linkPtr; //Traverse the list
        delete front; //Delete the front of the list
        front = temp; //Set the new front of the list
    } while (front != NULL); //Stop when we reach the end.
}

Link *endLst(Link *front) {
    Link *lnk = front, *end; //Start the link at the front to find the end
    do {
        end = lnk; //Are we at the end yet?
        lnk = lnk->linkPtr; //Traverse to the next link
    } while (lnk != NULL); //Finally found the end when NULL
    return end;
}

void addFrst(Link *front, int val) {
    Link *first = new Link; //Create a new link
    first->data = front->data; //Set its data equal to front
    first->linkPtr = front->linkPtr; //Point it to the next link
    front->data = val; //Fill front with value
    front->linkPtr = first; //Point it to the new link
}

void addLast(Link *front, int val) {
    Link *nx2last = endLst(front); //Find the last link in the list
    Link *last = new Link; //Create a new last link
    last->data = val; //Fill with the value desire
    last->linkPtr = NULL; //Point the added link to no where
    nx2last->linkPtr = last; //Put the last link on the end 
}

void addBefr(Link *front, int pos, int val) {
    if (pos < 1) return; //Invalid position
    else if (pos == 1) addFrst(front, val); //pos == 1? Same as add to front
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

void addAftr(Link *front, int pos, int val) {
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