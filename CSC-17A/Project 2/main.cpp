/* 
 * File:   main.cpp
 * Author: siliguo
 *
 * Created on December 7, 2016, 9:46 AM
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

//Our Libraries
#include "Card.h"
#include "Player.h"
#include "PlyNum.h"
//#include "Player.h"

void wtFile(Player *, int);
void rdFile(Player *, int);
void addBet(Player *, bool&, bool&, bool&, int&, int);
void addBetAI(Player *, bool&, bool&, bool&, int&, int, int);
bool challenge(Player);

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int> (time(0)));

    //Declare variables
    int cardNum = 52;
    int number[cardNum];

    for (int i = 0; i < cardNum; i++) {
        number[i] = i;
    }

    //*******************************************************************************************************************
    //    //For test: Number array
    //    for (int i = 0; i < cardNum; i++) {
    //        cout << number[i] << " ";
    //        if (i % 13 == 12) cout << endl;
    //    }
    //    cout << endl;
    //*******************************************************************************************************************

    //Shuffle numbers
    int temp; //Temporarily hold the data of a card
    int r; //Hold a random number
    for (int i = 0; i < cardNum; i++) {
        //Randomly pick an card
        r = rand() % cardNum;
        //Replace cards between each two
        temp = number[r];
        number[r] = number[i];
        number[i] = temp;
    }

    //*******************************************************************************************************************
    //    //For test: Number array after shuffle
    //    for (int i = 0; i < cardNum; i++) {
    //        cout << number[i] << " ";
    //        if (i % 13 == 12) cout << endl;
    //    }
    //    cout << endl;
    //*******************************************************************************************************************

    //Promote the number of players from user
    int choice;
    do {
        cout << "Would you like to join in a 2 people game or 3 people game?" << endl;
        cout << "Enter 2 or 3 for your choice: ";
        cin >> choice;
        if (choice != 2 && choice != 3) {
            cout << "Invalid Input! Please enter a number between 2 and 3." << endl;
        }
    } while (choice != 2 && choice != 3);
    cout << endl;

    PlyNum *plyNum;
    plyNum = new PlyNum[choice];
    for (int i = 0; i < choice; i++) {
        for (int j = 0; j < 3; j++) {
            plyNum[i].num[j] = number[i * 3 + j];
        }
    }


    //*******************************************************************************************************************
    //    //For test: Numbers in players' hand
    //    for (int i = 0; i < choice; i++) {
    //        cout << "For player #" << i + 1 << ": " << endl;
    //        for (int j = 0; j < choice; j++) {
    //            cout << plyNum[i].num[j] << " ";
    //        }
    //        cout << endl;
    //    }
    //    cout << endl;
    //*******************************************************************************************************************

    int sort;
    bool mak;
    do {
        mak = false;
        for (int i = 0; i < choice; i++) {
            for (int j = 0; j < 2; j++) {
                if ((plyNum[i].num[j] % 13) > (plyNum[i].num[j + 1] % 13)) {
                    sort = plyNum[i].num[j];
                    plyNum[i].num[j] = plyNum[i].num[j + 1];
                    plyNum[i].num[j + 1] = sort;
                    mak = true;
                }
            }
        }
    } while (mak);

    //*******************************************************************************************************************
    //    //For test: Numbers in players' hand
    //    for (int i = 0; i < choice; i++) {
    //        cout << "For player #" << i + 1 << ": " << endl;
    //        for (int j = 0; j < choice; j++) {
    //            cout << plyNum[i].num[j] << " ";
    //        }
    //        cout << endl;
    //    }
    //    cout << endl;
    //    //Test #2: Card class output
    //        Player player;
    //        Card *test;
    //    
    //        player.setCard(plyNum[0]);
    //        test = player.getCard();
    //        for (int i = 0; i < 3; i++) {
    //            cout << test[i].getName();
    //        }
    //        cout << endl;
    //        for (int i = 0; i < 3; i++) {
    //            cout << test[i].getNum();
    //        }
    //        cout << endl;
    //        player.setRank();
    //        cout << player.getRank();
    //*******************************************************************************************************************

    //initialize players' card set
    Player *players;
    players = new Player[3];
    Card *plyCard1;
    for (int i = 0; i < choice; i++) {
        players[i].setCard(plyNum[i]);
        players[i].setRank();
    }

    //Write players info in binary file
    wtFile(players, choice);

    //Read the info from the file
    rdFile(players, choice);

    //Output player's card set
    cout << "Here is your card set: " << endl;
    plyCard1 = players[0].getCard();
    for (int i = 0; i < 3; i++) {
        cout << plyCard1[i].getSuit() << plyCard1[i].getName() << " ";
    }
    cout << endl << endl;

    //Randomly chose dealer to start the game
    int start = rand() % choice;

    //Set sign for different meaning
    bool over = false; //game over
    bool two_exit = false; //player 2 lose game and exit
    bool thr_exit = false; //player 3 lose game and exit

    //Set money limit for one round, and for the whole game
    int max_one = 100; //Each person maximumly bet 300 in one round
    int max = 1200; //If total bet reach $3000, force all players open their cards
    int round = 0; // sign for the first round

    //Loop the game till 
    do {
        switch (start) {
            case(0):
                if (!over) {//If game not over
                    addBet(players, over, two_exit, thr_exit, round, choice);
                }
                if (over) {
                    break;
                } else {
                    round++;
                }

            case(1):
                if (!over && !two_exit) {
                    addBetAI(players, over, two_exit, thr_exit, round, choice, 1);
                }
                if (over) {
                    break;
                } else {
                    round++;
                }
            case(2):
                if (choice == 3) {
                    if (!over && !thr_exit) {
                        addBetAI(players, over, two_exit, thr_exit, round, choice, 2);
                    }
                    if (over) {
                        break;
                    } else {
                        round++;
                    }
                }
        }//End block of switch case
        start = 0;
    } while (!over);

    //Output the status of player's money
    int money = players[0].getMoney() + players[0].getBet();
    cout << endl;
    if (money > 1000) {
        cout << "You win $" << money - 1000 << "." << endl;
    } else if (money < 1000) {
        cout << "You lose $" << 1000 - money << "." << endl;
    } else {
        cout << "You neither win or lose." << endl;
    }

    //Free memory
    delete [] plyNum;
    delete [] players;
    plyNum = 0;
    players = 0;

}

//Write the info into the file

void wtFile(Player *p, int n) {
    fstream output;
    cout << "Write to the file..." << endl;
    output.open("players.txt", ios::out | ios::binary);
    if (!output.fail()) {
        output.write(reinterpret_cast<char *> (p), sizeof (Player) * n);
    }
    output.close();
}

void rdFile(Player *p, int n) {
    fstream input;
    cout << "Read from the file..." << endl << endl;
    input.open("players.txt", ios::in | ios::binary);
    if (!input.fail()) {
        input.read(reinterpret_cast<char *> (p), sizeof (Player) * n);
    }
    input.close();
}

//Ask user if he wants to add bet

void addBet(Player *p, bool& o, bool& two, bool& thr, int& r, int n) {
    //Declare variables
    string ans;
    int choice, add, b;
    int moneyT[3] = {1000, 1000, 1000};
    int betT[3] = {0, 0, 0};
    bool tryAgain = true;

    Card * plyCard2, *plyCard3;
    plyCard2 = p[1].getCard();
    plyCard3 = p[2].getCard();

    //Display current bet
    cout << "The current bet is: $" << p[0].getTbet() << endl;

    //Ask user if he wants to discard
    do {
        cout << "Do you want to discard? (Y or N)" << endl;
        cin >> ans;

        //Check validation
        if (ans != "Y" && ans != "N" && ans != "y" && ans != "n") {
            cout << "Invalid Input! Please enter Y or N." << endl;
        }
    } while (ans != "Y" && ans != "N" && ans != "y" && ans != "n");
    cout << endl;

    if (ans == "Y" || ans == "y") {//If player discard, game over
        o = true;
        cout << "You discard your cards. Game over." << endl;
    } else if (ans == "N" || ans == "n") {//If player choose to continue play, ask him to add bet
        if (r == 0) {//For first round
            cout << "How many bets do you want to raise? (1 bet = $10)" << endl;
            cin >> add;
            while (tryAgain) {
                try {
                    p[0].setTbet(add);
                    tryAgain = false;
                } catch (Player::TooSmall) {
                    cout << "Invalid Input! You have to at least raise one bet." << endl;
                    cout << "How many bets do you want to raise? (1 bet = $10)" << endl;
                    cin >> add;
                } catch (Player::TooLarge) {
                    cout << "Invalid Input! You can at most raise 10 bets in one round." << endl;
                    cout << "How many bets do you want to raise? (1 bet = $10)" << endl;
                    cin >> add;
                }
            }
            b = p[0].getTbet();
            moneyT[0] = 1000 - b;
            betT[0] = b;
            p[0].setMoney(moneyT[0]);
            p[0].setBet(betT[0]);
            cout << endl;
        } else {//For other round
            cout << "Choice Menu:" << endl;
            cout << "1) to see" << endl;
            cout << "2) raise bet" << endl;
            cout << "3) challenge" << endl;
            cout << "Please make your choice (1, 2, or 3)" << endl;
            cin >> choice;
            cout << endl;

            //Use switch case for choice
            switch (choice) {
                case(1):
                    cout << "You choose to see." << endl << endl;
                    moneyT[0] -= p[0].getTbet();
                    betT[0] = p[0].getTbet();
                    p[0].setMoney(moneyT[0]);
                    p[0].setBet(betT[0]);

                    break;
                case(2):
                    cout << "How many bets do you want to raise? (1 bet = $10)" << endl;
                    cin >> add;
                    while (tryAgain) {
                        try {
                            p[0].setTbet(add);
                            tryAgain = false;
                        } catch (Player::TooSmall) {
                            cout << "Invalid Input! You have to at least raise one bet." << endl;
                            cout << "How many bets do you want to raise? (1 bet = $10)" << endl;
                            cin >> add;
                        } catch (Player::TooLarge) {
                            cout << "Invalid Input! You can at most raise 10 bets in one round." << endl;
                            cout << "How many bets do you want to raise? (1 bet = $10)" << endl;
                            cin >> add;
                        }
                    }
                    b = p[0].getTbet();
                    moneyT[0] -= b;
                    betT[0] = b;
                    p[0].setMoney(moneyT[0]);
                    p[0].setBet(betT[0]);
                    cout << endl;
                    break;
                case(3):
                    if (p[0].getMoney() < 2 * p[0].getTbet()) {
                        cout << "You do not have enough money to challenge others." << endl;
                        cout << endl;
                    } else {
                        cout << "You choose to challenge the previous player with double as bet on the table." << endl;
                        cout << endl;
                        //AI decision
                        if (n == 2) {
                            //If AI accept
                            if (challenge(p[1])) {
                                if (p[0] > p[1]) {
                                    o = true;
                                    moneyT[0] += 2 * p[0].getTbet();
                                    moneyT[1] -= p[0].getTbet();
                                    betT[1] = 0;
                                    p[0].setMoney(moneyT[0]);
                                    p[1].setMoney(moneyT[1]);
                                    p[1].setBet(betT[1]);

                                    cout << "Congratulation! You win the game!" << endl;
                                } else {
                                    o = true;
                                    moneyT[0] -= p[0].getTbet();
                                    betT[0] = 0;
                                    moneyT[1] += 2 * p[0].getTbet();
                                    p[0].setMoney(moneyT[0]);
                                    p[0].setBet(betT[0]);
                                    p[1].setMoney(moneyT[1]);
                                    cout << "Sorry, you lose the game." << endl;
                                }
                                cout << "The cards in player 2's hand are: " << endl;
                                for (int i = 0; i < 3; i++) {
                                    cout << plyCard2[i].getSuit() << plyCard2[i].getName() << " ";
                                }
                                cout << endl;
                            } else {
                                o = true;
                                moneyT[0] += p[0].getTbet();
                                betT[1] = 0;
                                p[0].setMoney(moneyT[0]);
                                p[1].setBet(betT[1]);
                                cout << "Player 2 discard. You win the game." << endl;
                            }
                        } else if (n == 3) {
                            if (!thr) {
                                if (challenge(p[2])) {
                                    if (p[0] > p[2]) {
                                        if (!two) {
                                            thr = true;
                                            cout << "Congratulation! You win the challenge!" << endl;
                                            cout << "Player 3 exit the game." << endl;
                                            cout << endl;
                                        } else {
                                            o = true;
                                            cout << "Congratulation! You win the game." << endl;
                                            cout << "The cards in player 3's hand are: " << endl;
                                            for (int i = 0; i < 3; i++) {
                                                cout << plyCard3[i].getSuit() << plyCard3[i].getName() << " ";
                                            }
                                            cout << endl;
                                        }
                                        moneyT[0] += 2 * p[0].getTbet();
                                        moneyT[2] -= p[0].getTbet();
                                        betT[2] = 0;
                                        p[0].setMoney(moneyT[0]);
                                        p[2].setMoney(moneyT[2]);
                                        p[2].setBet(betT[2]);
                                    } else {
                                        o = true;
                                        moneyT[0] -= p[0].getTbet();
                                        betT[0] = 0;
                                        moneyT[2] += 2 * p[0].getTbet();
                                        p[0].setMoney(moneyT[0]);
                                        p[0].setBet(betT[0]);
                                        p[2].setMoney(moneyT[2]);
                                        cout << "Sorry, you lose the game." << endl;
                                        cout << "The cards in player 3's hand are: " << endl;
                                        for (int i = 0; i < 3; i++) {
                                            cout << plyCard3[i].getSuit() << plyCard3[i].getName() << " ";
                                        }
                                        cout << endl;
                                    }
                                } else {
                                    if (!two) {
                                        thr = true;
                                        cout << "Player 3 discard, and exit the game." << endl;
                                        cout << endl;
                                    } else {
                                        o = true;
                                        cout << "Player 3 discard, and exit the game." << endl;
                                        cout << "Congratulation! You win the game." << endl;
                                    }
                                    moneyT[0] += p[0].getTbet();
                                    betT[2] = 0;
                                    p[0].setMoney(moneyT[0]);
                                    p[2].setBet(betT[2]);
                                }
                            } else {
                                if (challenge(p[1])) {
                                    if (p[0] > p[1]) {
                                        o = true;
                                        moneyT[0] += 2 * p[0].getTbet();
                                        moneyT[1] -= p[0].getTbet();
                                        betT[1] = 0;
                                        p[0].setMoney(moneyT[0]);
                                        p[1].setMoney(moneyT[1]);
                                        p[1].setBet(betT[1]);
                                        cout << "Congratulation! You win the game!" << endl;
                                    } else {
                                        o = true;
                                        moneyT[0] -= p[0].getTbet();
                                        betT[0] = 0;
                                        moneyT[1] += 2 * p[0].getTbet();
                                        p[0].setMoney(moneyT[0]);
                                        p[0].setBet(betT[0]);
                                        p[1].setMoney(moneyT[1]);

                                        cout << "Sorry, you lose the game." << endl;
                                    }
                                    cout << "The cards in player 2's hand are: " << endl;
                                    for (int i = 0; i < 3; i++) {
                                        cout << plyCard2[i].getSuit() << plyCard2[i].getName() << " ";
                                    }
                                    cout << endl;
                                } else {
                                    o = true;
                                    cout << "Player 2 discard, and exit the game." << endl;
                                    cout << "Congratulation! You win the game." << endl;
                                }
                            }
                        }
                    }

            }//End block of switch case
        }//Not the first round
    }//user choose to continue play
}

//Function for AI player 2

void addBetAI(Player *p, bool& o, bool & two, bool& thr, int& r, int n, int i) {
    //Declare variables
    int choice, b;
    string ans;
    int moneyT[3] = {p[0].getMoney(), p[1].getMoney(), p[2].getMoney()};
    int betT[3] = {p[0].getBet(), p[1].getBet(), p[2].getBet()};

    Card * plyCard2, *plyCard3;
    plyCard2 = p[1].getCard();
    plyCard3 = p[2].getCard();

    //Display current bet
    cout << "The current bet is: $" << p[0].getTbet() << endl;

    //AI decision: discard
    if (n == 3) {
        if (p[2].getRank() == 1) {
            if (rand() % 10 < 1) {
                thr = true;
                cout << "Player 3 discard, and exit game." << endl;
                cout << endl;
            }
        }
    }
    //AI decision: add Bet
    if (r == 0) {
        if (p[i].getRank() == 0 || p[i].getRank() == 1 || p[i].getRank() == 2) {
            if (rand() % 5 < 3) {
                cout << "Player " << i + 1 << " raise one bet." << endl;
                p[0].setTbet(1);
            } else {
                cout << "Player " << i + 1 << " raise five bets." << endl;
                p[0].setTbet(5);
            }
        } else if (p[i].getRank() == 3 || p[i].getRank() == 4) {
            if (rand() % 2 < 1) {
                cout << "Player " << i + 1 << " raise one bet." << endl;
                p[0].setTbet(1);
            } else {
                cout << "Player " << i + 1 << " raise three bets." << endl;
                p[0].setTbet(3);
            }
        } else {
            if (rand() % 5 < 2) {
                cout << "Player " << i + 1 << " raise three bet." << endl;
                p[0].setTbet(3);
            } else {
                cout << "Player " << i + 1 << " raise five bets." << endl;
                p[0].setTbet(5);
            }
        }
        cout << endl;
        moneyT[i] -= p[0].getTbet();
        betT[i] += p[0].getTbet();
        p[i].setMoney(moneyT[i]);
        p[i].setBet(betT[i]);
    } else { //For other round
        if (rand() % 5 < 1) {
            choice = 1;
        } else {
            if (rand() % 2 < 1) {
                choice = 2;
            } else {
                choice = 3;
            }
        }
        switch (choice) {
            case(1):
                cout << "Player " << i + 1 << " choose to see." << endl << endl;
                moneyT[i] -= p[0].getTbet();
                betT[i] += p[0].getTbet();
                p[i].setMoney(moneyT[i]);
                p[i].setBet(betT[i]);
                break;
            case(2):
                cout << "Player " << i + 1 << " choose to raise bet." << endl;
                if (p[i].getRank() == 0 || p[i].getRank() == 1 || p[i].getRank() == 2) {
                    if (rand() % 5 < 3) {
                        cout << "Player " << i + 1 << " raise one bet." << endl;
                        p[0].setTbet(1);
                    } else {
                        if (rand() % 4 < 3) {
                            cout << "Player " << i + 1 << " raise two bets." << endl;
                            p[0].setTbet(2);
                        } else {
                            cout << "Player " << i + 1 << " raise five bets." << endl;
                            p[0].setTbet(5);
                        }
                    }
                } else if (p[i].getRank() == 3 || p[i].getRank() == 4) {
                    if (rand() % 2 < 1) {
                        cout << "Player " << i + 1 << " raise two bet." << endl;
                        p[0].setTbet(2);
                    } else {
                        cout << "Player " << i + 1 << " raise three bets." << endl;
                        p[0].setTbet(3);
                    }
                } else {
                    if (rand() % 5 < 2) {
                        cout << "Player " << i + 1 << " raise three bet." << endl;
                        p[0].setTbet(3);
                    } else {
                        if (rand() % 6 < 5) {
                            cout << "Player " << i + 1 << " raise five bets." << endl;
                            p[0].setTbet(5);
                        } else {
                            cout << "Player " << i + 1 << "raise ten bets." << endl;
                            p[0].setTbet(10);
                        }
                    }
                }
                cout << endl;
                moneyT[i] -= p[0].getTbet();
                betT[i] = p[0].getTbet();
                p[i].setMoney(moneyT[i]);
                p[i].setBet(betT[i]);
                break;
            case(3):
                if (i == 1) {
                    if (n == 2) thr = true;
                    cout << "Player 2 choose to challenge you with double bet of the table." << endl << endl;
                    do {
                        cout << "Would you like to accept challenge with double bet? (Y or N)" << endl;
                        cout << "Remind if you refuse, you will lose game." << endl;
                        cin >> ans;
                        //Check validation
                        if (ans != "Y" && ans != "N" && ans != "y" && ans != "n") {
                            cout << "Invalid Input! Please enter Y or N." << endl;
                        }
                    } while (ans != "Y" && ans != "N" && ans != "y" && ans != "n");
                    cout << endl << endl;

                    if (ans == "N" || ans == "n") {
                        o = true;
                        moneyT[i] += p[0].getTbet();
                        betT[i - 1] = 0;
                        p[i].setMoney(moneyT[i]);
                        p[i - 1].setBet(betT[i - 1]);
                        cout << "You choose to discard." << endl;
                        cout << "Sorry, you lose the game." << endl;
                    } else {
                        if (p[i] > p[i - 1]) {
                            o = true;
                            moneyT[i] += 2 * p[0].getTbet();
                            moneyT[i - 1] -= p[0].getTbet();
                            betT[i - 1] = 0;
                            p[i].setMoney(moneyT[i]);
                            p[i - 1].setMoney(moneyT[i - 1]);
                            p[i - 1].setBet(betT[i - 1]);
                            cout << "Sorry, you lose the game." << endl;
                            cout << "The cards in player 2's hand are: " << endl;
                            for (int i = 0; i < 3; i++) {
                                cout << plyCard2[i].getSuit() << plyCard2[i].getName() << " ";
                            }
                            cout << endl;
                        } else {
                            if (!thr) {
                                two = true;
                                cout << "You win the challenge!" << endl;
                                cout << "Player 2 exit game." << endl;
                                cout << endl;
                            } else {
                                o = true;
                                cout << "Player 2 lose the challenge." << endl;
                                cout << "Congratulation! You win the game!" << endl;
                                cout << "The cards in player 2's hand are: " << endl;
                                for (int i = 0; i < 3; i++) {
                                    cout << plyCard2[i].getSuit() << plyCard2[i].getName() << " ";
                                }
                            }
                            moneyT[i] -= p[0].getTbet();
                            betT[i] = 0;
                            moneyT[i - 1] += 2 * p[0].getTbet();
                            p[i].setMoney(moneyT[i]);
                            p[i].setBet(betT[i]);
                            p[i - 1].setMoney(moneyT[i - 1]);
                        }
                    }
                }
                if (i == 2) {
                    if (!two) {
                        cout << "Player 3 choose to challenge player 2 with double bet as table." << endl;
                        cout << endl;
                        if (!challenge(p[1])) {
                            two = true;
                            moneyT[i] += p[0].getTbet();
                            betT[i - 1] = 0;
                            p[i].setMoney(moneyT[i]);
                            p[i - 1].setBet(betT[i - 1]);
                            cout << "Player 2 refuse challenge from player 3." << endl;
                            cout << "Player 2 exit game." << endl;
                            cout << endl;
                        } else {
                            if (p[i] > p[i - 1]) {
                                two = true;
                                moneyT[i] += 2 * p[0].getTbet();
                                moneyT[i - 1] -= p[0].getTbet();
                                betT[i - 1] = 0;
                                p[i].setMoney(moneyT[i]);
                                p[i - 1].setMoney(moneyT[i - 1]);
                                p[i - 1].setBet(betT[i - 1]);
                                cout << "Player 2 lose the challenge with player 3." << endl;
                                cout << "Player 2 exit the game." << endl;
                                cout << endl;
                            } else {
                                thr = true;
                                moneyT[i] -= p[0].getTbet();
                                betT[i] = 0;
                                moneyT[i - 1] += 2 * p[0].getTbet();
                                p[i].setMoney(moneyT[i]);
                                p[i].setBet(betT[i]);
                                p[i - 1].setMoney(moneyT[i - 1]);
                                cout << "Player 3 lose the challenge with player 2." << endl;
                                cout << "Player 3 exit the game." << endl;
                                cout << endl;
                            }
                        }
                    } else {
                        cout << "Player 3 choose to challenge you." << endl;
                        do {
                            cout << "Would you like to accept challenge with double bet? (Y or N)" << endl;
                            cout << "Remind if you refuse, you will lose game." << endl;
                            cin >> ans;
                            //Check validation
                            if (ans != "Y" && ans != "N" && ans != "y" && ans != "n") {
                                cout << "Invalid Input! Please enter Y or N." << endl;
                            }
                        } while (ans != "Y" && ans != "N" && ans != "y" && ans != "n");
                        if (ans == "N" || ans == "n") {
                            o = true;
                            moneyT[i] += p[0].getTbet();
                            betT[i - 2] = 0;
                            p[i].setMoney(moneyT[i]);
                            p[i - 2].setBet(betT[i - 2]);
                            cout << "You choose to discard." << endl;
                            cout << "Sorry, you lose the game." << endl;
                        } else {
                            if (p[i] > p[i - 2]) {
                                o = true;
                                moneyT[i] += 2 * p[0].getTbet();
                                moneyT[i - 2] -= p[0].getTbet();
                                betT[i - 2] = 0;
                                p[i].setMoney(moneyT[i]);
                                p[i - 2].setMoney(moneyT[i - 2]);
                                p[i - 2].setBet(betT[i - 2]);
                                cout << "Sorry, you lose the game." << endl;
                                cout << "The cards in player 3's hand are: " << endl;
                                for (int i = 0; i < 3; i++) {
                                    cout << plyCard3[i].getSuit() << plyCard3[i].getName() << " ";
                                }
                                cout << endl;
                            } else {
                                o = true;
                                moneyT[i] -= p[0].getTbet();
                                betT[i] = 0;
                                moneyT[i - 2] += 2 * p[0].getTbet();
                                p[i].setMoney(moneyT[i]);
                                p[i].setBet(betT[i]);
                                p[i - 2].setMoney(moneyT[i - 2]);
                                cout << "Player 3 lose the challenge." << endl;
                                cout << "Congratulation! You win the game!" << endl;
                                cout << "The cards in player 3's hand are: " << endl;
                                for (int i = 0; i < 3; i++) {
                                    cout << plyCard3[i].getSuit() << plyCard3[i].getName() << " ";
                                }
                                cout << endl;
                            }
                        }
                    }
                }
        }
    }
}

//Function of AI decision for challenge

bool challenge(Player p) {
    //Declare variables
    bool accept = false;

    Card *plyCard = p.getCard();

    //AI make decision
    //Rank 0: 1% accept
    if (p.getRank() == 0) {
        if (rand() % 100 < 1) accept = true;
    } else if (p.getRank() == 1) {//Rank 1
        if (plyCard[2].getValue() < 6) {//2~6, not accept
            accept = false;
        } else if (plyCard[2].getValue() >= 6 && plyCard[2].getValue() < 10) {//7~10, 20% accept
            if (rand() % 5 < 1) accept = true;
        } else {//>10, 40% accept
            if (rand() % 5 < 2) accept = true;
        }
    } else if (p.getRank() == 2) {//Rank 2
        if (plyCard[1].getValue() < 6) {//A pair of 1~7, 50% accept
            if (rand() % 2 < 1) accept = true;
        } else {//Otherwise, 60% accept
            if (rand() % 5 < 3) accept = true;
        }
    } else if (p.getRank() == 3) {//Rank 3
        if (plyCard[2].getValue() < 8) {//Straight under 7, 8, 9, 80% accept
            if (rand() % 5 < 4) accept = true;
        } else {//Otherwise, 90% open
            if (rand() % 10 < 9) accept = true;
        }
    } else {//If rank higher than 3, 100% accept
        accept = true;
    }
    return accept;
}