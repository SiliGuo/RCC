/* 
 * File:   MilTime.h
 * Author: Sili Guo
 *
 * Created on December 5, 2016, 8:17 PM
 */

#ifndef MILTIME_H
#define MILTIME_H

#include "Time.h"

class MilTime : public Time {
private:
    void convert(int, int);
protected:
    int milHours;
    int milSeconds;
public:
    MilTime(int, int);
    void setTime(int, int);
    int getHour() const;
    string getStandHr() const;


};

#endif /* MILTIME_H */

