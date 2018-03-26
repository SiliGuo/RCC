/* 
 * File:   MilTime.cpp
 * Author: siliguo
 * 
 * Created on December 5, 2016, 8:17 PM
 */

#include <iostream>
#include <string>
using namespace std;

#include "MilTime.h"

MilTime::MilTime(int mh, int ms) {
    milHours = mh;
    milSeconds = ms;
    convert(mh, ms);
}

void MilTime::setTime(int mh,int ms) {
    milHours=mh;
    milSeconds=ms;
    convert(mh,ms);
}

string MilTime::getStandHr() const {
    string stdTime;
    stdTime = to_string(milHours/100)+":"+to_string(milHours%100)+":"+to_string(milSeconds);
    return stdTime;
}

void MilTime::convert(int mh,int ms) {
    hour=mh/100;
    min=mh%100;
    sec=ms;
}