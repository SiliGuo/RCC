/* 
 * File:   Player.h
 * Author: gsl
 *
 * Created on October 28, 2016, 3:21 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

struct Player {
    Card *hold;
    int holdNum[3];
    int money;
    int bet;
    int rank;
};

#endif /* PLAYER_H */

