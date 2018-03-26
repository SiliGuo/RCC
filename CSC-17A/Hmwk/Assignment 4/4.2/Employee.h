/* 
 * File:   Employee.h
 * Author: siliguo
 *
 * Created on November 17, 2016, 7:57 AM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
private:
    string name;
    int idNumber;
    string department;
    string position;
public:
    Employee(string, int, string, string);
    Employee(string, int);
    Employee();
    string getName() const;
    int getId() const;
    string getDep() const;
    string getPos() const;
};

#endif /* EMPLOYEE_H */

