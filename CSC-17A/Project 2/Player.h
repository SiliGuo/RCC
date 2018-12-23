/* 
 * File:   Player.h
 * Author: siliguo
 *
 * Created on December 8, 2016, 11:08 AM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "PlyNum.h"

class Player : public Card {
private:
    Card *card;
    int rank;
    int money;
    int bet;
    static int Tbet;

public:

    class TooSmall {
    };

    class TooLarge {
    };
    Player();

    ~Player() {
    }
    void setCard(PlyNum);
    void setRank();

    void setMoney(int m) {
        money = m;
    }

    void setBet(int b) {
        bet = b;
    }

    static void setTbet(int);

    Card *getCard() const {
        return card;
    }

    int getRank() const {
        return rank;
    }

    int getMoney() const {
        return money;
    }

    int getBet() const {
        return bet;
    }

    static int getTbet() {
        return Tbet;
    }
    bool operator>(const Player &); //Overload > operator

};

#endif /* PLAYER_H */

