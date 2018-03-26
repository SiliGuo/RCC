/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on April 9, 2017
 * Purpose: Mastermind Game
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int randNum();

//Execution Begins here!

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int> (time(0)));

    //Declare Variables
    //Constants
    const int TOTAL = 8;
    const int SELCT = 4;

    int color[TOTAL] = {1, 2, 3, 4, 5, 6, 7, 8}; //8 colors
    int *select; //Select 4 colors
    int *guess; //Player's guess
    int *copy; //Copy of selection
    int start; //Game menu choice
    int choice; //Game mode choice
    int balls; //How many balls for guessing
    int turn; //Game turns
    int num; //# of balls in correct color
    int pos; //# of balls in correct color and in correct position
    char enter; //Clear screen signal
    bool same; //Check duplicates
    bool win; //Mark for win

    //Game menu
    do {
        system("clear");
        turn = 1;
        win = false;
        cout << endl << "   Mastermind Game" << endl << endl;
        cout << "   Game Menu:" << endl;
        cout << "   1. Start game" << endl;
        cout << "   2. Read rules" << endl;
        cout << "   0. Quit game" << endl;
        cout << "Please enter your choice (0~2): ";
        cin >> start;

        if (start != 1 && start != 2) {
            system("clear");
            cout << "You quit the game." << endl;
            break;
        }
        switch (start) {
            case 1:
                system("clear");
                cout << "\n   Game Mode-1:" << endl;
                cout << "   1. 4 balls" << endl;
                cout << "   2. 6 balls" << endl;
                cout << "   3. 8 balls" << endl;
                cout << "Please choose the game mode-1 (1~3):";
                cin >> balls;
                switch (balls) {
                    case 1:
                        balls = 4;
                        break;
                    case 2:
                        balls = 6;
                        break;
                    case 3:
                        balls = 8;
                        break;
                }
                select = new int[balls];
                guess = new int[balls];
                copy = new int[balls];

                system("clear");
                cout << "\n   Game Mode-2:" << endl;
                cout << "   1. Allow duplicates" << endl;
                cout << "   2. Not allow duplicates" << endl;
                cout << "Please choose game mode-2 (1 or 2):";
                cin >> choice;

                switch (choice) {
                    case 1://Allow duplicates
                        for (int i = 0; i < balls; i++)
                            //Randomly create # 1~8
                            select[i] = randNum();
                        //                        //For test
                        //                        for (int i = 0; i < balls; i++)
                        //                            cout << select[i] << " ";
                        //                        break;

                    default://Not allow duplicates
                        for (int i = 0; i < balls; i++) {
                            do {
                                //Randomly create # 1~8
                                select[i] = rand() % 8 + 1;
                                //                                //For test
                                //                                cout << "test " << i << ": " << select[i] << endl;
                                //Check for duplicates
                                if (i > 0) {
                                    same = false;
                                    for (int j = i - 1; j >= 0; j--) {
                                        if (select[i] == select[j]) {
                                            same = true;
                                            break;
                                        }
                                    }
                                }
                            } while (same); //Loop when duplicates
                        }
                }//End of swich case
                cout << endl;


                //Ask player for guess
                system("clear");
                //                //For test
                //                for (int i = 0; i < balls; i++)
                //                    cout << select[i] << " ";
                do {
                    num = 0;
                    pos = 0;
                    cout << "****************************************************" << endl;
                    cout << "\n Turn #" << turn << endl << endl;
                    cout << "Please enter your 4 guess in order (1~8)." << endl;
                    for (int i = 0; i < balls; i++) {
                        do {
                            cout << "Guess #" << i + 1 << ": ";
                            cin >> guess[i];
                        } while (guess[i] < 1 || guess[i] > 8);
                    }

                    //Copy the select array to enable for edit
                    for (int i = 0; i < balls; i++)
                        copy[i] = select[i];

                    //First check correct position
                    for (int i = 0; i < balls; i++) {
                        if (guess[i] == copy[i]) {
                            copy[i] = 0;
                            guess[i] = 9;
                            pos++;
                        }
                    }
                    //Then check for correct color
                    for (int i = 0; i < balls; i++) {
                        for (int j = 0; j < balls; j++) {
                            if (j != i) {
                                if (guess[i] == copy[j]) {
                                    num++;
                                    copy[j] = 0;
                                    break;
                                }
                            }
                        }
                    }

                    cout << "\nCorrect color:    " << num << endl;
                    cout << "Correct position: " << pos << endl << endl;
                    cout << "Press enter to continue." << endl;
                    cin.ignore();
                    do {
                        enter = getchar();
                    } while (enter != '\n');
                    //Check for win
                    if (pos == 4) win = true;

                    //Turns plus 1
                    turn++;
                } while (!win && enter == '\n');
                system("clear");
                cout << "Game Clear!" << endl;
                cout << "Congratulation! You win the game in " << turn - 1 << " steps." << endl;
                break;
            case 2:
                system("clear");
                //Output rules and menu
                cout << "\n *************** Mastermind Rules **********************************************" << endl;
                cout << "• There are 8 balls (1-8) in total, and 4/6/8 of them are chosen." << endl;
                cout << "• Two playing mode can be chosen: duplicates and non-duplicates." << endl;
                cout << "• In each turn, there will be a hint for current condition: " << endl;
                cout << "   # for correct balls" << endl;
                cout << "   # for correct balls in correct positions" << endl;
                cout << "• To win the game, player should get all 4/6/8 correct balls in correct positions." << endl;
                cout << "*************** Mastermind Rules **********************************************" << endl;
                break;
        }//End of switch case
        cout << "\n Press enter to go back to Game Menu." << endl;
        if (start == 2)
            cin.ignore();
        do {
            enter = getchar();
        } while (enter != '\n');
    } while (enter == '\n');

    //Exit Stage right!
    delete [] select;
    delete [] guess;
    delete [] copy;
    return 0;
}

int randNum() {
    return rand() % 8 + 1;
}