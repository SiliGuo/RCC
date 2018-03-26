/* 
 * File:   Employee.cpp
 * Author: siliguo
 * 
 * Created on November 17, 2016, 7:57 AM
 */

#include <iostream>
#include <string>
using namespace std;

#include "Employee.h"

Employee::Employee(string n, int i, string d, string p) {
    name = n;
    idNumber = i;
    department = d;
    position = p;
}

Employee::Employee(string n, int i) {
    name = n;
    idNumber = i;
    department = " ";
    position = " ";
}

Employee::Employee() {
    name = " ";
    idNumber = 0;
    department = " ";
    position = " ";
}

string Employee::getName() const {
    return name;
}

int Employee::getId() const {
    return idNumber;
}

string Employee::getDep() const {
    return department;
}

string Employee::getPos() const {
    return position;
}