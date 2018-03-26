/* 
 * File:   Table.cpp
 * Author: Sili Guo
 * Created on March 5, 2017
 * Purpose: Review 2, create a 2-D array with random numbers, and copy to a new object
 */

#include <cstdlib>

#include "Table.h"

//Constructor
Table::Table(unsigned int r, unsigned int c) {
    szRow = r > 0 ? r : 1;
    szCol = c > 0 ? c : 1;
    columns = new RowAray *[szRow];
    for (int i = 0; i < szRow; i++) {
        columns[i] = new RowAray(szCol);
    }
}

//Copy constructor
Table::Table(const Table &obj) {
    szRow = obj.szRow;
    szCol = obj.szCol;
    columns = new RowAray *[szRow];
    for (int i = 0; i < szRow; i++) {
        columns[i] = new RowAray(szCol);
        for (int j = 0; j < szCol; j++) {
            
            columns[i]->setData(j, (obj.columns[i]->getData(j)));
        }
    }
}

//Destructor
Table::~Table() {
    for (int i = 0; i < szRow; i++) {
        delete columns[i];
    }
    delete [] columns;
}

//Accessor
int Table::getData(int r, int c) const {
    if (r >= 0 && r < szRow && c >= 0 && c < szCol) {
        return columns[r]->getData(c);
    } else {
        return 0;
    }
}

//Mutator
void Table::setData(int r, int c, int value) {
    columns[r]->setData(c, value);
}