/*
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: Kinetic Energy
 *    PROBLEM DEFINITION: Implement the kineticEnergy function in C++.
 *                        (Exercise 6.6, pg 368 in Gaddis Text)
 *                  DATE: 04/07/16
 *     SYSTEM - HARDWARE: Mac Pro
 *            - SOFTWARE: NetBeans 8.1
 *         Input Devices: Keyboard
 *        Output Devices: Screen
 *                                                                          
 *   PROGRAM ASSUMPTIONS: Two parameters are named mass and velocity, both are float data type.
 *                                                              
 */

#include <iostream>
using namespace std;

// function prototypes
float kineticEnergy(float, float);

// main function here
int main()
{
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
    
    return 0;    
}

// Compute energy by the function of mass and velocity, return the result to the calling code
float kineticEnergy(float mass, float velocity)
{
    // declare a local variable named energy in float data type
    float energy;
    energy = (mass*velocity*velocity)/2;
    
    return energy; // return the result value
}