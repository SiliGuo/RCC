/* 
 * File:   Triangle.cpp
 * Author: Sili Guo
 * Created on 03/01/2017
 */

#include "Triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle(int r) {
    szRow = r > 0 ? r : 1;
    records = new RowAray *[szRow];
    for (int i = 0; i < szRow; i++) {
        records[i] = new RowAray(i + 1);
    }
}

Triangle::~Triangle() {
    for (int i = 0; i < szRow; i++) {
        delete records[i];
    }
    delete [] records;
}

int Triangle::getData(int r, int c) {
    if (r >= 0 && r < szRow && c >= 0) {
        return records[r]->getData(c);
    } else {
        return 0;

    }
}
