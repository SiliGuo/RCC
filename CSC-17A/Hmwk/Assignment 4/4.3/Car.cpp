/* 
 * File:   Car.cpp
 * Author: siliguo
 * 
 * Created on November 17, 2016, 5:28 PM
 */

#include <iostream>
#include <string>
using namespace std;

#include "Car.h"

Car::Car(int y, string m) {
    yearModel = y;
    make = m;
    speed = 0;
}

int Car::getModel() const {
    return yearModel;
}

string Car::getMake() const {
    return make;
}

int Car::getSpeed() const {
    return speed;
}

int Car::accelerate() {
    speed += 5;
    return speed;
}

int Car::brake() {
    speed -= 5;
    return speed;
}