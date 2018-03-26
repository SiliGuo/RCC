/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   min_max.h
 * Author: siliguo
 *
 * Created on December 5, 2016, 10:35 PM
 */

#ifndef MIN_MAX_H
#define MIN_MAX_H

template <class T>
int minimum(T &val1, T &val2){
    T temp;
    if(val1 < val2) temp = val1;
    else temp = val2;
    return temp;
}
template <class T>
int maximum(T &val1, T &val2){
    T temp;
    if(val1 > val2) temp = val1;
    else temp = val2;
    return temp;
}

#endif /* MIN_MAX_H */

