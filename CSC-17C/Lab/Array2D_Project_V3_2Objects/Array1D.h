/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 15, 2017, 7:18 PM
 * Purpose:  Specification for the 1D array Object
 */

#ifndef ARRAY1D_H
#define ARRAY1D_H

class Array1D{
    private:
        int col;
        int *field;
    public:
        Array1D(int);
        ~Array1D(){delete [] field;}
        int getCol(){return col;}
        int getField(int indx){return ((indx>=0&&indx<col)?field[indx]:0);}
};

#endif /* ARRAY1D_H */