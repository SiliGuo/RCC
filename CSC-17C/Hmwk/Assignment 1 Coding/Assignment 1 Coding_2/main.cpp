/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on March 22, 2017
 * Purpose: Assignment 1 Coding_1: Linked List with template
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "LinkList.h"
//Global Constants

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
    LinkList <int> linkList(10);
    //Output original linked list
    cout << "Original linked list:" << endl;
    linkList.prntLst(5);

    //Add to the front
    linkList.addFrst(11);
    cout << "Add 0 to the end:" << endl;
    linkList.prntLst(5);

    //Add to the end
    linkList.addLast(0);
    cout << "Add 11 to the front:" << endl;
    linkList.prntLst(5);

    //Add before 
    linkList.addBefr(3, 12);
    cout << "Add 12 before 3rd element: " << endl;
    linkList.prntLst(5);

    //Add after
    linkList.addAftr(5, 13);
    cout << "Add 13 after 5th element: " << endl;
    linkList.prntLst(5);


    return 0;
}

