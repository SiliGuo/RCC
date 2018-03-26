/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on May 26, 2017
 * Purpose:Trees_II: Binary tree with insertion, deletion, balance, and print in 3 traversals
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "Tree.h"
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int ranDigt();
//Execution Begins here!

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int> (time(0)));
    //Declare Variables
    Tree tree;
    vector<int>randNum; //Hold random numbers
    int num; //A single random number
    //Randomly insert 10 numbers to tree
    cout << "\nInsertion: " << endl;
    for (int i = 0; i < 10; i++) {
        num = ranDigt();
        tree.insert(num);
        randNum.push_back(num);
        cout << "Insert " << num << " to the tree." << endl;
    }
    cout << endl;
    //Display outputs
    cout << "Print binary tree:" << endl;
    cout << "In-order: ";
    tree.inPrnt();
    cout << "\nPre-order: ";
    tree.prePrnt();
    cout << "\nPost-order: ";
    tree.postPrnt();
    cout << endl;
    //Delete 5 values in the tree
    cout << "\nDeletion: " << endl;
    for (int i = 0; i < 5; i++) {
        num = rand() % 10;
        cout << "Delete " << randNum[num] << " from the tree." << endl;
        tree.delet(randNum[num]);
    }
    cout << endl;
    //Display outputs
    cout << "Print binary tree:" << endl;
    cout << "In-order: ";
    tree.inPrnt();
    cout << "\nPre-order: ";
    tree.prePrnt();
    cout << "\nPost-order: ";
    tree.postPrnt();
    cout << endl;
    //Exit Stage right!
    return 0;
}

//Create a 2-digit random number

int ranDigt() {
    return rand() % 90 + 10;
}