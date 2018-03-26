/* 
 * File:   Number.h
 * Author: siliguo
 *
 * Created on November 18, 2016, 12:31 AM
 */

#ifndef NUMBER_H
#define NUMBER_H

class Number {
private:
    int number;
    static string eng;
    static void translate(int);
public:
    Number(int);
    static void print();
};

#endif /* NUMBER_H */

