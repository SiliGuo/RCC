/* 
 * File:   RowAray.cpp
 * Author: Sili Guo
 * Created on 03/01/2017
 */

#include <cstdlib>

#include "RowAray.h"

RowAray::RowAray(int s) {
    size = s > 0 ? s : 1;
    rowData = new int[size];
    //Fill in the array with random numbers
    for (int i = 0; i < size; i++) {
        rowData[i] = rand() % 90 + 10;
    }
}

RowAray::~RowAray() {
        delete [] rowData;
}

