/* 
 * File:   FeetInches.h
 * Author: siliguo
 *
 * Created on November 18, 2016, 5:02 PM
 */

#ifndef FEETINCHES_H
#define FEETINCHES_H

// The FeetInches class holds distances or measurements
// expressed in feet and inches.

class FeetInches {
private:
    int feet;
    int inches;
    void simplify();
public:
    // Constructor

    FeetInches(int f = 0, int i = 0) {
        feet = f;
        inches = i;
        simplify();
    }

    // Mutator functions 

    void setFeet(int f) {
        feet = f;
    }

    void setInches(int i) {
        inches = i;
        simplify();
    }
    //Accessor functions 

    int getFeet() const {
        return feet;
    }

    int getInches() const {
        return inches;
    }
    // Overloaded operator functions
    FeetInches operator+(const FeetInches &); // Overloaded + 
    FeetInches operator-(const FeetInches &); // Overloaded -
    bool operator<=(const FeetInches &); // Overloaded <=
    bool operator>=(const FeetInches &); // Overloaded >=
    bool operator==(const FeetInches &); // Overloaded !=
};
#endif