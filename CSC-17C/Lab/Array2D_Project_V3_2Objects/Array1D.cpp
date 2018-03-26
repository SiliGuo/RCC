/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 15, 2017, 7:18 PM
 * Purpose:  Implementation for the 1D array Object
 */

#include "Array1D.h"
#include <cstdlib>

Array1D::Array1D(int n){
    //Make sure this is an array
    col=n>1?n:1;
    //Size the array
    field=new int[col];
    //Fill the array
    for(int i=0;i<col;i++){
        field[i]=rand()%90+10;//Fill data with 2 digit numbers
    }
}