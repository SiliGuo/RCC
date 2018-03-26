/* 
 * File:   Card.h
 * Author: siliguo
 *
 * Created on December 7, 2016, 10:06 AM
 */

#ifndef CARD_H
#define CARD_H

#include <cstring>

#include "AbsCard.h"


class Card : public AbsCard{
private:
    int number;
    char suit;
    char name;
    int value;

public:
    Card();
    void setNum(int);

    int getNum() const {
        return number;
    }
    char getSuit();
    char getName();
    int getValue();
};

#endif /* CARD_H */


