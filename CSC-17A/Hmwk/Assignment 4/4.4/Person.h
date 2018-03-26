/* 
 * File:   Person.h
 * Author: siliguo
 *
 * Created on November 17, 2016, 9:31 PM
 */

#ifndef PERSON_H
#define PERSON_H

class Person {
private:
    string name;
    string address;
    int age;
    string phone;
public:
    Person(string, string, int, string);
    string getName() const;
    string getAdd() const;
    int getAge() const;
    string getPhone() const;
    void ptnInfo();

};

#endif /* PERSON_H */

