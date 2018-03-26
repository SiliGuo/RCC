/* 
 * File:   RowAray.h
 * Author: Sili Guo
 * Created on 03/01/2017
 * Specification for the RowAray
 */

#ifndef ROWARAY_H
#define	ROWARAY_H

class RowAray{
    private:
        RowAray(){}
        int size;
        int *rowData;
    public:
        RowAray(int);
        ~RowAray();
        int getSize(){return size;}
        int getData(int i){return rowData[i];}
};

#endif	/* ROWARAY_H */