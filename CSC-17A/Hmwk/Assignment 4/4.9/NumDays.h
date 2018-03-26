/* 
 * File:   NumDays.h
 * Author: siliguo
 *
 * Created on November 18, 2016, 4:16 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays {
private:
    int hour;
    float day;
public:
    NumDays(int);
    void convert();
    int getHour() const;
    float getDay() const;
    NumDays operator+(const NumDays &);
    NumDays operator-(const NumDays &);
    NumDays operator++();
    NumDays operator--();
};

#endif /* NUMDAYS_H */

