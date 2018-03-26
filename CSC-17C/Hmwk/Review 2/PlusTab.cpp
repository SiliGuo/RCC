/* 
 * File:   PlusTab.cpp
 * Author: Sili Guo
 * Created on March 5, 2017
 * Purpose: Review 2, overload operator + to sum two 2-D array
 */

#include "PlusTab.h"
#include "AbsTabl.h"

//Overload operator +
PlusTab PlusTab::operator +(const PlusTab &right){
    PlusTab temp(szRow,szCol);
    temp.szRow = right.szRow;
    temp.szCol = right.szCol;
    for(int i=0;i<szRow;i++){
        for(int j=0;j<szCol;j++){
        temp.columns[i]->setData(j, (columns[i]->getData(j)+right.columns[i]->getData(j)));
        }
    }
    return temp;
}