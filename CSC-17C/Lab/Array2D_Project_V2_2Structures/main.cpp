/*
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 15, 2017, 7:18 PM
 * Purpose:  Dynamic 2 D array structure
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
    Array2D table;
    
    //Initialize Variables
    table.row=7;
    table.record=new Array1D[table.row];
    for(int row=0;row<table.row;row++){
        table.record[row].col=row+1;
        table.record[row].field=new int[table.record[row].col];
    }
    
    //Map inputs to outputs
    for(int row=0;row<table.row;row++){
        for(int col=0;col<table.record[row].col;col++){
            table.record[row].field[col]=rand()%90+10;//2 digit numbers
        }
    }
    
    //Display outputs
    for(int row=0;row<table.row;row++){
        for(int col=0;col<table.record[row].col;col++){
            cout<<table.record[row].field[col]<<" ";
        }
        cout<<endl;
    }
    
    //Clean up
    for(int row=0;row<table.row;row++){
        delete []table.record[row].field;
    }
    delete []table.record;
    
    //Exit Stage right!
    return 0;
}
