/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on March 29, 2017
 * Purpose: Assignment 2
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "LinkList.h"
#include "DoubList.h"
#include "CircList.h"
#include "PrioList.h"
#include "SortList.h"
//Global Constants

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Random seed
    srand(static_cast<unsigned int> (time(0)));

    //***************** Stack and Queue ****************************************

    //Declare variables
    LinkList <int> linkList;
    const int PUSH = 5;
    const int POP = 5;

    //Output original linked list
    cout << "Original linked list:" << endl;
    linkList.prntLst(5);

    //Stack
    cout << "Stack: " << endl;
    cout << "-------------------------" << endl;

    //Push 5 random numbers to linked list
    cout << "Add 5 random values:" << endl;
    for (int i = 0; i < PUSH; i++)
        linkList.push(rand() % 90 + 10);
    linkList.prntLst(5);

    //Pop all values in linked list;
    cout << "Popping..." << endl;
    for (int i = 0; i < POP; i++)
        cout << linkList.pop() << endl;
    cout << endl << "After popping: " << endl;
    linkList.prntLst(5);

    //Queue
    cout << endl << endl << "Queue: " << endl;
    cout << "-------------------------" << endl;

    //Enqueue 5 random numbers to linked list
    cout << "Add 5 random values:" << endl;
    for (int i = 0; i < PUSH; i++)
        linkList.push(rand() % 90 + 10);
    linkList.prntLst(5);

    //Dequeue all values in Linked List
    cout << "Dequeuing..." << endl;
    for (int i = 0; i < POP; i++) {
        cout << linkList.dequeue() << endl;
    }
    cout << endl << "After dequeuing: " << endl;
    linkList.prntLst(5);

    //**************************************************************************
    //***************** Doubly Linked List *************************************

    //Declare variables
    DoubList<int> doub(10);

    //Output doubly linked list
    cout << endl << endl << "Doubly Linked List: " << endl;
    cout << "-------------------------" << endl;
    cout << "Original linked list:" << endl;
    doub.prntLst(5);
    cout << endl << "Reversed linked list: " << endl;
    doub.revrLst(5);

    //**************************************************************************
    //***************** Circularly Linked List *********************************

    //Declare variables
    CircList<int> circ(10);

    //Output circular linked list
    cout << endl << endl << "Circularly Linked List: " << endl;
    cout << "-------------------------" << endl;
    cout << "Original linked list:" << endl;
    circ.prntLst(1, 5);
    cout << "Print linked list twice: " << endl;
    circ.prntLst(2, 5);

    //**************************************************************************
    //***************** Priority Linked List ***********************************

    //Declare variables
    PrioList<int> prio;

    //Output priority linked list
    cout << endl << endl << "Priority Linked List: " << endl;
    cout << "-------------------------" << endl;
    cout << "Original linked list:" << endl;
    prio.prntLst(5);
    //Push 5 values to the list
    prio.push(5);
    prio.push(20);
    prio.push(13);
    prio.push(81);
    prio.push(200);
    cout << "Add 5 values to the list: " << endl;
    prio.prntLst(5);
    cout << "Find and put 81 at first:" << endl;
    prio.prior(81);
    prio.prntLst(5);

    //**************************************************************************
    //***************** Priority Queue *****************************************

    //Declare variables
    PrioList<int> prioQue;
    
    //Output priority queue
    cout << endl << endl << "Priority Queue: " << endl;
    cout << "-------------------------" << endl;
    cout << "Original linked list:" << endl;
    prioQue.prntLst(5);
    //Push 5 values to the list
    prioQue.push(8);
    prioQue.push(77);
    prioQue.push(120);
    prioQue.push(0);
    prioQue.push(69);
    cout << "Add 5 values to the list: " << endl;
    prioQue.prntLst(5);
    //Dequeue all values, while 0 has priority
    prioQue.prior(0);
    cout << "Dequeue while 0 has priority." << endl;
    cout << "Dequeuing..." << endl; 
    for(int i=0;i<5;i++){
        cout << prioQue.dequeue() << endl;
    }
    
    //**************************************************************************
    //***************** Sorted Linked List *************************************
    
    //Declare variables
    SortList<int> sort(10);
    
    //Output sorted linked list
    cout << endl << endl << "Sorted Linked List: " << endl;
    cout << "-------------------------" << endl;
    cout << "Original linked list:" << endl;
    sort.prntLst(5);
    cout << "Sorted Linked List:" << endl;
    sort.sort();
    sort.prntLst(5);
    
    //**************************************************************************

    //Exit stage
    return 0;
}

