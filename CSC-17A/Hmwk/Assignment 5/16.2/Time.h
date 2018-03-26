/* 
 * File:   Time.h
 * Author: siliguo
 *
 * Created on December 5, 2016, 8:18 PM
 */

#ifndef TIME_H
#define TIME_H

class Time {
protected:
    int hour;
    int min;
    int sec;
public:
    // Default constructor

    Time() 
        { hour = min = sec = 0; }

    // Constructor

    Time(int h, int m, int s) 
        { hour = h; min = m; sec = s; }

    // Accessor Functions

    int getHour() const 
        { return hour; }

    int getMin() const 
        { return min; }

    int getSec() const 
        { return sec; }
};

#endif /* TIME_H */

