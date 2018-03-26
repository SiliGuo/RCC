/* 
 * File:   RowAray.cpp
 * Author: Sili Guo
 * Created on March 5, 2017
 * Purpose: Review 2, create a single row of data
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "RowAray.h"

//Constructor
RowAray::RowAray(unsigned int s) {
    size = s > 0 ? s : 1;
    rowData = new int[size];
    for (int i = 0; i < size; i++) {
        rowData[i] = rand() % 90 + 10;
    }
}

//Destructor
RowAray::~RowAray() {
    delete [] rowData;
}

//Mutator
void RowAray::setData(int p, int value) {
    if (p >= 0 && p < size) {
        rowData[p] = value;
    }
}