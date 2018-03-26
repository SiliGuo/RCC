/* 
 * File:   main.cpp
 * Author: siliguo
 *
 * Created on November 17, 2016, 7:57 AM
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Employee.h"

int main(int argc, char** argv) {

    //Declare variables
    string name, department, position;
    int idNumber;
    const int SIZE = 3;
    
    //Create an object of class
    Employee *info[SIZE];
    
    //Store appropriate value into the variables
    info[0] = new Employee("Susan Meyers", 47899, "Accounting", "Vice President");
    info[1] = new Employee("Mark Jones", 39119, "IT", "Programmer");
    info[2] = new Employee("Joy Rogers", 81774, "Manufacturing", "Engineer");
    
    //Output result
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << left << setw(20) << "Name" << setw(20) << "ID Number" << setw(20) << "Department" << setw(20) << "Position" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << setw(20) << info[i]->getName() << setw(20) << info[i]->getId() << setw(20) << info[i]->getDep() << setw(20) << info[i]->getPos() << endl;
    }
    cout << "--------------------------------------------------------------------------------" << endl;
    
    return 0;
}

