/* 
 * File:   main.cpp
 * Author: siliguo
 *
 * Created on November 17, 2016, 5:28 PM
 */

#include <iostream>
#include <string>
using namespace std;

#include "Car.h"

int main(int argc, char** argv) {

    //Declare variables
    int yearModel, speed;
    string make;
    
    //Prompt user for car info
    cout << "Please enter the year model of your car: ";
    cin >> yearModel;
    
    cout << "Please enter the make of your car: ";
    cin >> make;
    cout << endl;
    
    //Store appropriate value into variables
    Car car(yearModel, make);
    
    //Output Car info
    cout << "This is a " << car.getModel() << " " << car.getMake() << " car." << endl;
    cout << endl;
    
    string times[5]= {"first", "second", "third", "fourth", "fifth"};
    
    //Accelerate 5 times
    for (int i=0;i<5;i++){
        cout << "This is the " << times[i] << " acceleration, the current speed is " << car.accelerate() << " mph." << endl;
        cout << endl;
    }
    
    //Push brake 5 times
    for (int i=0;i<5;i++){
        cout << "This is the " << times[i] << " brake, the current speed is " << car.brake() << " mph." << endl;
        cout << endl;
    }

    return 0;
}

