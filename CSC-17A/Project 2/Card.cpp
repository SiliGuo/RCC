/* 
 * File:   Card.cpp
 * Author: siliguo
 * 
 * Created on December 7, 2016, 10:06 AM
 */

#include <iostream>
using namespace std;

#include "Card.h"

Card::Card() {
    number = 0;
    suit = ' ';
    name = ' ';
    value = 0;
}

void Card::setNum(int n) {
    number = n;
}

char Card::getSuit() {
    if (number < 13) {
        suit = 'D';
    } else if (number < 26) {
        suit = 'C';
    } else if (number < 39) {
        suit = 'H';
    } else {
        suit = 'S';
    }
    return suit;
}

char Card::getName() {
    char aName[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    name = aName[number % 13];
    return name;
}

int Card::getValue() {
    value = number % 13 + 1;
    return value;
}