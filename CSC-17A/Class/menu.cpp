/*
 * File:   main.cpp
 * Author: Sili Guo
 * Created on September 27, 2016, 22:42 PM
 * Purpose: Assignment 1 (Gaddis_8th, Ch9.); Mean median mode problem
 */

#include <iostream>
using namespace std;

void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();

int main(int argv, char *argc[]) {
    int inN;
    do {
        Menu();
        inN = getN();
        switch (inN) {
            case 1: problem1();
                break;
            case 2: problem2();
                break;
            case 3: problem3();
                break;
            case 4: problem4();
                break;
            case 5: problem5();
                break;
            case 6: problem6();
                break;
            case 7: problem7();
                break;
            case 5: problem8();
                break;
            case 6: problem9();
                break;
            case 7: problem10();
                break;
            default: def(inN);
        }
    } while (inN > 0 && inN < 11);
    return 1;
}

void Menu() {
    cout << "********** Problem Menu **********" << endl;
    cout << "Type 1 for problem 1" << endl;
    cout << "Type 2 for problem 2" << endl;
    cout << "Type 3 for problem 3" << endl;
    cout << "Type 4 for problem 4" << endl;
    cout << "Type 5 for problem 5" << endl;
    cout << "Type 6 for problem 6" << endl;
    cout << "Type 7 for problem 7" << endl;
    cout << "Type 5 for problem 8" << endl;
    cout << "Type 6 for problem 9" << endl;
    cout << "Type 7 for problem 10" << endl;
    cout << "Type 0 to exit \n" << endl;
    cout << "Please choose a number: ";
}

int getN() {
    int inN;
    cin>>inN;
    return inN;
}

void problem1() {
    cout << "In problem # 1" << endl << endl;
    cout << endl << endl;
}

void problem2() {
    cout << "In problem # 2" << endl << endl;
    cout << endl << endl;
}

void problem3() {
    cout << "In problem # 3" << endl << endl;
    cout << endl << endl;
}

void problem4() {
    cout << "In problem # 4" << endl << endl;
    cout << endl << endl;
}

void problem5() {
    cout << "In problem # 5" << endl << endl;
    cout << endl << endl;
}

void problem6() {
    cout << "In problem # 6" << endl << endl;
    cout << endl << endl;
}

void problem7() {
    cout << "In problem # 7" << endl << endl;
    cout << endl << endl;
}

void problem8() {
    cout << "In problem # 8" << endl << endl;
    cout << endl << endl;
}

void problem9() {
    cout << "In problem # 9" << endl << endl;
    cout << endl << endl;
}

void problem10() {
    cout << "In problem # 10" << endl << endl;
    cout << endl << endl;
}

void def(int inN) {
    cout << "You typed " << inN << " to exit the program" << endl;
}