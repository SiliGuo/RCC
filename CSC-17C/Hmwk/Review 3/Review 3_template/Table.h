/* 
 * File:   Table.h
 * Author: Sili Guo
 * Created on March 15, 2017
 * Purpose: Review 3 - Template: Specification for the Table
 */

#ifndef TABLE_H
#define	TABLE_H

#include "RowAray.h"

template <class T>
class Table{
    private:
        int szRow;
        int szCol;
        RowAray<T> **records;
    public:
        Table(int,int);
        Table(const Table &);
        ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        T getData(int,int) const;
        Table<T> operator+(const Table &);
};

//Constructor
template <class T>
Table<T>::Table(int r, int c) {
    szRow = r;
    szCol = c;
    records = new RowAray<T> *[szRow];
    for (int i = 0; i < szRow; i++) {
        records[i] = new RowAray<T>(szCol);
    }
}

//Copy constructor
template <class T>
Table<T>::Table(const Table &obj) {
    szRow = obj.szRow;
    szCol = obj.szCol;
    records = new RowAray<T> *[szRow];
    for (int i = 0; i < szRow; i++) {
        records[i] = new RowAray<T>(szCol);
        for (int j = 0; j < szCol; j++) {
            
            records[i]->setData(j, (obj.records[i]->getData(j)));
        }
    }
}

//Destructor
template <class T>
Table<T>::~Table() {
    for(int i=0;i<szRow;i++){
        delete records[i];
    }
    delete [] records;
}

//Accessor
template <class T>
T Table<T>::getData(int r, int c) const{
    if(r >=0 && r < szRow && c >= 0 && c <= szCol){
        return records[r]->getData(c);
    } else{
        return 0;
    }
}

//Overload operator +
template <class T>
Table<T> Table<T>::operator +(const Table &right){
    Table temp(szRow,szCol);
    temp.szRow = right.szRow;
    temp.szCol = right.szCol;
    for(int i=0;i<szRow;i++){
        for(int j=0;j<szCol;j++){
        temp.records[i]->setData(j, (records[i]->getData(j)+right.records[i]->getData(j)));
        }
    }
    return temp;
}

#endif	/* TABLE_H */