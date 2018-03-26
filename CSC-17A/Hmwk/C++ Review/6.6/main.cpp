/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on September 21, 2016, 3:18 PM
 * Purpose:  C++ Review (Gaddis_8th, 6.6)
 */

//System Libraries
#include <iostream>
using namespace std;

// function prototypes
float kineticEnergy(float, float);

//Execution Begin Here!

int main(int argc, char** argv) {
    
    // declare two variables named mass and velocity, both are float type
    float mass, velocity;

    // get the numbers of mass and velocity from user.
    cout << "Enter the number of mass in kilograms: ";
    cin >> mass;
    cout << "Enter the number of velocity in meter/sec: ";
    cin >> velocity;

    // declare the variable energy as the function kineticEnergy() of mass and velocity
    float energy = kineticEnergy(mass, velocity);
    
    // output in formal
    cout << "kinetic energy= " << energy << "J" << endl;
    
    //Exit stage right!
    return 0;
}

float kineticEnergy(float mass, float velocity) {
    
    // declare a local variable named energy in float data type
    float energy;
    energy = (mass * velocity * velocity) / 2;

    return energy; // return the result value
}