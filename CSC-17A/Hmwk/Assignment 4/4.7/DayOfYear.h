/* 
 * File:   DayOfYear.h
 * Author: siliguo
 *
 * Created on November 18, 2016, 11:06 AM
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
};

#endif /* DAYOFYEAR_H */

