/* 
 * File:   Absolute.h
 * Author: siliguo
 *
 * Created on December 5, 2016, 10:38 PM
 */

#ifndef ABSOLUTE_H
#define ABSOLUTE_H

template <class T>
int absolute(T num){
    if(num > 0) return num;
    else return -num;
}


#endif /* ABSOLUTE_H */

