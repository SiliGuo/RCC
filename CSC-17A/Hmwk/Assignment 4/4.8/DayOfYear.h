/* 
 * File:   DayOfYear.h
 * Author: siliguo
 *
 * Created on November 18, 2016, 12:23 PM
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

class DayOfYear {
private:
    int day;
    static string format;
    static int num;
public:
    DayOfYear(int);
    void translate(int);
    static void print();
    DayOfYear operator++();
    DayOfYear operator--();
};

#endif /* DAYOFYEAR_H */