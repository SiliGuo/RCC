/* 
 * File:   Triangle.h
 * Author: Sili
 * Created on 03/01/2017
 * Purpose:  Specification of a Triangular array from a Row Array
 */

#ifndef TRIANGLE_H
#define	TRIANGLE_H

#include "RowAray.h"

class Triangle{
    private:
        int szRow;
        RowAray **records;
    public:
        Triangle(int);
        ~Triangle();
        int getSzRow(){return szRow;}
        int getData(int,int);
};


#endif	/* TRIANGLE_H */
