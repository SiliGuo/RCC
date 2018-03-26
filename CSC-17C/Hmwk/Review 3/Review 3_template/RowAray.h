/* 
 * File:   RowAray.h
 * Author: Sili Guo
 * Created on March 15, 2017
 * Purpose: Review 3 - Template: Specification for the RowAray
 */

#ifndef ROWARAY_H
#define	ROWARAY_H
#include <cstdlib>

template <class T>
class RowAray{
    private:
        int size;
        T *rowData;
    public:
        RowAray(int);
        ~RowAray();
        int getSize(){return size;}
        T getData(int i){return rowData[i];}
        void setData(int,T);
};

//Constructor
template <class T>
RowAray<T>::RowAray(int s) {
    size = s > 0 ? s : 1;
    rowData = new T[size];
    //Fill in the array with random numbers
    for (int i = 0; i < size; i++) {
        rowData[i] = rand() % 90 + 10;
    }
}

//Destructor
template <class T>
RowAray<T>::~RowAray() {
        delete [] rowData;
}

//Mutator
template <class T>
void RowAray<T>::setData(int p, T value) {
    if (p >= 0 && p < size) {
        rowData[p] = value;
    }
}


#endif	/* ROWARAY_H */