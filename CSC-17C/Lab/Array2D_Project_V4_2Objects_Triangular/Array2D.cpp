/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 15, 2017, 7:18 PM
 * Purpose:  Implementation for the 2D array Object
 */

#include "Array2D.h"

Array2D::Array2D(int row,int col){
    //Set the row size
    this->row=row>0?row:1;
    //Declare the record array
    record=new Array1D*[this->row];
    //Size each row
    int allCol=col>0?col:1;
    //Create the record arrays
    for(int i=0;i<this->row;i++){
        record[i]=new Array1D(allCol);
    }
}

Array2D::~Array2D(){
    //Delete each record
    for(int i=0;i<this->row;i++){
        delete record[i];
    }
    delete []record;
}
        
int Array2D::getRec(int row,int col){
    if(row>=0&&row<this->row&&col>=0&&col<record[row]->getCol()){
        return record[row]->getField(col);
    }else{
        return 0;
    }
}