/* 
 * File:   PlusTab.h
 * Author: Sili Guo
 * Created on March 5, 2017
 * Purpose: Specification for the Table addition operator
 */

#ifndef PLUSTAB_H
#define	PLUSTAB_H

#include "Table.h"

class PlusTab:public Table{
    public:
        PlusTab(unsigned int r,unsigned int c):Table(r,c){};
        PlusTab operator+(const PlusTab &);
};

#endif	/* PLUSTAB_H */