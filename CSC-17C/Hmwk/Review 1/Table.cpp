/* 
 * File:   Table.cpp
 * Author: Sili Guo
 * Created on 03/01/2017
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "Table.h"

Table::Table(int r, int c) {
    szRow = r;
    szCol = c;
    records = new RowAray*[szRow];
    for (int i = 0; i < szRow; i++) {
        records[i] = new RowAray(szCol);
    }
}

Table::~Table() {
    for(int i=0;i<szRow;i++){
        delete records[i];
    }
    delete [] records;
}

int Table::getData(int r, int c){
    if(r >=0 && r < szRow && c >= 0 && c <= szCol){
        return records[r]->getData(c);
    } else{
        return 0;
    }
}