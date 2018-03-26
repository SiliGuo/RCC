/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 15, 2017, 7:18 PM
 * Purpose:  Specification for the 2D array Object
 */

#ifndef ARRAY2D_H
#define ARRAY2D_H

#include "Array1D.h"

class Array2D{
    private:
        int row;
        Array1D **record;
    public:
        Array2D(int,int);
        ~Array2D();
        int getRow(){return row;}
        int getCol(int row){return record[row>=0?row:0]->getCol();}
        int getRec(int,int);
};


#endif /* ARRAY2D_H */