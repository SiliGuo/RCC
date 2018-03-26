/* 
 * File:   Date.h
 * Author: siliguo
 *
 * Created on November 16, 2016, 10:48 PM
 */

#ifndef DATE_H
#define DATE_H

class Date {
private:
    int year; //year
    int month; //month
    int day; //day
public:
    Date (int, int, int);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    void output();
    
};

#endif /* DATE_H */

