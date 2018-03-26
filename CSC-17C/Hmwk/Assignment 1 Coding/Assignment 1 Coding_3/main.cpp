/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on March 22, 2017
 * Purpose: Assignment 1 Coding_1: SimpleVector class template
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "SimpleVector.h"

//Function Prototypes
template <class T>
void display(SimpleVector<T>); //Display the array

//Execution Begins here!

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int> (time(0)));

    //Declare Variables
    int size = 10;
    SimpleVector<int> array(size);

    //Display array and size
    cout << "Original array:" << endl;
    array.prntLst(5);
//    cout << "Size: " << array.size() << endl << endl;

    //Add 11 new values, then display array and size
    for (int i = 0; i < 11; i++)
        array.push_back(rand()%10);
    
    cout << "Add 11 values to array:" << endl;
    array.prntLst(5);
//    cout << "Size: " << array.size() << endl << endl;

    //Subtract 16 values, then display array and size
    for (int i=0;i<16;i++)
    array.pop_off();
    
    cout << "Subtract 16 values to array: " << endl;
    array.prntLst(5);
//    cout << "Size: " << array.size() << endl << endl;

    return 0;
}

//template <class T>
//void display(SimpleVector<T> ary) {
//    for (int i = 0; i < ary.size() + 1; i++) {
//        if (ary.getElementAt(i) != -1) cout << ary.getElementAt(i) << " ";
//        else break;
//        if (i%10 == 9) cout << endl;
//    }
//    cout << endl;
//}