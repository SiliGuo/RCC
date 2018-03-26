/* 
 * File:   Table.h
 * Author: Sili Guo
 * Created on 03/01/2017
 * Specification for the Table
 */

#ifndef TABLE_H
#define	TABLE_H

#include "RowAray.h"

class Table{
    private:
        int szRow;
        int szCol;
        RowAray **records;
    public:
        Table(int,int);
        ~Table();
        int getSzRow(){return szRow;}
        int getSzCol(){return szCol;}
        int getData(int,int);
};

#endif	/* TABLE_H */