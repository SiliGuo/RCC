/* 
 * File:   Person.cpp
 * Author: siliguo
 * 
 * Created on November 17, 2016, 9:31 PM
 */

#include <iostream>
#include <string>
using namespace std;

#include "Person.h"

Person::Person(string n, string a, int ag, string p) {
    name = n;
    address = a;
    age = ag;
    phone = p;
}

string Person::getName() const {
    return name;
}

string Person::getAdd() const {
    return address;
}

int Person::getAge() const {
    return age;
}

string Person::getPhone() const {
    return phone;
}

void Person::ptnInfo() {
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Age: " << age << endl;
    cout << "Phone Number: " << phone << endl;
}

