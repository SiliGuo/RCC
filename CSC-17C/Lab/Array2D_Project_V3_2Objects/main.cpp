/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 15, 2017, 7:18 PM
 * Purpose:  Dynamic 2 D array object
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Array2D.h"

//Global Constants

//Function Prototypes

//Execution Begins here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    Array2D table(7,5);
    
    //Display outputs
    for(int row=0;row<table.getRow();row++){
        for(int col=0;col<table.getCol(row);col++){
            cout<<table.getRec(row,col)<<" ";
        }
        cout<<endl;
    }

    //Exit Stage right!
    return 0;
}
