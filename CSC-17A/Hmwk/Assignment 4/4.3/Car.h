/* 
 * File:   Car.h
 * Author: siliguo
 *
 * Created on November 17, 2016, 5:28 PM
 */

#ifndef CAR_H
#define CAR_H

class Car {
private:
    int yearModel;
    string make;
    int speed;
public:
    Car(int, string);
    int getModel() const;
    string getMake() const;
    int getSpeed() const;
    int accelerate();
    int brake();
};

#endif /* CAR_H */

