/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 28, 2016, 2:01 PM
 * Purpose:  Shortest Sort using Array Structure
 *          Version 1 no sorting
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random number generator Library
#include <ctime>     //Time Library
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants

//Function Prototypes
Array *fillAry(int);
void prntAry(Array *,int);
void destroy(Array *);

//Execution Begin Here!
int main(int argc, char** argv) {
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    int perLine=10;
    const int SIZE=100;
    
    //Input data
    Array *array=fillAry(SIZE);
    
    //Display initialization
    prntAry(array,perLine);
    
    //Destroy the array structure and its contents
    destroy(array);

    //Exit stage right!
    return 0;
}
void destroy(Array *a){
    delete [](*a).data;
    delete a;
}

void prntAry(Array *a,int perLine){
    cout<<endl;
    for(int i=0;i<(*a).size;i++){
        cout<<*((*a).data+1)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n){
    Array *a=new Array;
    (*a).size=n;
    (*a).data=new int[n];
    for(int i=0;i<n;i++){
        *((*a).data+i)=rand()%90+10;//Random 2 digit numbers
    }
    return a;
}