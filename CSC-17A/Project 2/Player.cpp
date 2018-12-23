/* 
 * File:   Player.cpp
 * Author: siliguo
 * 
 * Created on December 8, 2016, 11:08 AM
 */
#include <cstring>

#include "Player.h"

int Player::Tbet = 0;

Player::Player() {
    rank = 0;
    money = 1000;
    bet = 0;
    card = NULL;
}

void Player::setCard(PlyNum p) {
    card = new Card[3];

    for (int i = 0; i < 3; i++) {
        this->card[i].setNum(p.num[i]);
        card[i].setNum(p.num[i]);
    }
}

void Player::setRank() {
    char *suit = new char[3];
    int *val = new int[3];
    for (int i = 0; i < 3; i++) {
        suit[i] = card[i].getSuit();
        val[i] = card[i].getValue();
    }

    //Check for rank 0
    if (val[0] == 1 && val[1] == 2 && val[2] == 4) {
        rank = 0;
    }
    //Check for rank 1
    if (val[0] != val[1] && val[1] != val[2]) {
        rank = 1;
    }
    //Check for rank 2
    if ((val[0] == val[1] && val[1] != val[2]) ||
            (val[1] == val[2] && val[0] != val[1])) {
        rank = 2;
    }
    //Check for rank 3, 4, 5
    if (suit[0] == suit[1] && suit[1] == suit[2]) {
        if (val[0] + 1 == val[1] && val[1] + 1 == val[2]) {
            rank = 5;
        } else {
            rank = 4;
        }
    } else {
        if (val[0] + 1 == val[1] && val[1] + 1 == val[2]) {
            rank = 3;
        }
    }
    //Check for rank 6
    if (val[0] == val[1] && val[1] == val[2]) {
        rank = 6;
    }

    delete [] suit;
    delete [] val;

}

void Player::setTbet(int a) {
    if (a < 1) {
        throw TooSmall();
    } else if (a > 10) {
        throw TooLarge();
    } else {
        Tbet += a * 10;
    }
}

bool Player::operator>(const Player &right) {
    //Declare variables
    bool win = false;

    if (rank == 0 && right.rank == 6) {
        win = true;
    } else if (rank == 6 && right.rank == 0) {
        win = false;
    } else {
        if (rank > right.rank) {
            win = true;
        } else if (rank < right.rank) {
            win = false;
        } else {//Rank equals
            //If same cards
            if (card[0].getValue() == right.card[0].getValue() && card[1].getValue() == right.card[1].getValue() && card[2].getValue() == right.card[2].getValue()) {
                win = false;
            } else {//Not same cards
                if (rank == 3 || rank == 5 || rank == 6) {//Rank 3, 5, 6
                    if (card[2].getValue() > right.card[2].getValue()) {
                        win = true;
                    } else {
                        win = false;
                    }
                } else if (rank == 1 || rank == 4) {//Rank 2, 4
                    if (card[2].getValue() > right.card[2].getValue()) {
                        win = true;
                    } else if (card[2].getValue() < right.card[2].getValue()) {
                        win = false;
                    } else {
                        if (card[1].getValue() > right.card[1].getValue()) {
                            win = true;
                        } else if (card[1].getValue() < right.card[1].getValue()) {
                            win = false;
                        } else {
                            if (card[0].getValue() > right.card[0].getValue()) {
                                win = true;
                            } else {
                                win = false;
                            }
                        }
                    }
                } else if (rank == 2) {
                    if (card[1].getValue() > right.card[1].getValue()) {
                        win = true;
                    } else if (card[1].getValue() < right.card[1].getValue()) {
                        win = false;
                    } else {
                        if (card[2].getValue() > right.card[2].getValue()) {
                            win = true;
                        } else if (card[2].getValue() < right.card[2].getValue()) {
                            win = false;
                        } else {
                            if (card[1].getValue() > right.card[1].getValue()) {
                                win = true;
                            } else {
                                win = false;
                            }
                        }
                    }
                }
            }//Not same cards
        }//Rank equals
    }
    return win;
}