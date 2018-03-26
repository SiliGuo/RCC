/*
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 15, 2017, 7:18 PM
 * Purpose:  Specification for the 2D array structure
 */

#ifndef ARRAY2D_H
#define ARRAY2D_H

#include "Array1D.h"

struct Array2D{
    int row;
    Array1D *record;
};


#endif /* ARRAY2D_H */
