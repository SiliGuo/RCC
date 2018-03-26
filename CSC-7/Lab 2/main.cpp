/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on March 14, 2017
 * Purpose: Lab 2 Luhn Algorithm
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Enumerated type variable
enum CrdCard { AMEREXP, VISA, MASTCRD, DISCOVER, ALL };

//Function Prototypes
char rndDgit();
void prpAmex(char [], int);
void prpVisa(char [], int);
void prpMast(char [], int);
void prpDisc(char [], int);
bool Valid(char []);
char Double(char);
void genCC(CrdCard, char []);
void flipDig(char []);

//Execution Begins here!

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int> (time(0)));

    //Constant variables
    const int AME = 15;
    const int OTH = 16;

    //Declare Variables
    int choice, valid, invalid;
    char *crdCard;

    //Menu for type of credit cards
    do {
        cout << "Credit Cards Menu" << endl;
        cout << "1. American Express" << endl;
        cout << "2. Visa" << endl;
        cout << "3. Master Card" << endl;
        cout << "4. Discover" << endl;
        cout << "5. All" << endl;
        cout << "Which type of credit card do you want to test?" << endl;
        cout << "Please enter the number (1~5): ";
        cin >> choice;
        //Check validation
        if (choice < 1 || choice > 5)
            cout << "Invalid Input! Please enter a number from 1~5." << endl;
    } while (choice < 1 || choice > 5);
    cout << endl;
    
    //Loop 10,000 times
    for (int i = 0; i < 10000; i++) {
        switch (choice) {
                //American Express
            case 1:
                crdCard = new char[AME];
                //Get a valid card number
                do {
                    genCC(AMEREXP, crdCard);
                } while (!Valid(crdCard));
                break;
            case 2:
                crdCard = new char[OTH];
                do {
                    genCC(VISA, crdCard);
                } while (!Valid(crdCard));
                break;
            case 3:
                crdCard = new char[OTH];
                do {
                    genCC(MASTCRD, crdCard);
                } while (!Valid(crdCard));
                break;
            case 4:
                crdCard = new char[OTH];
                do {
                    genCC(DISCOVER, crdCard);
                } while (!Valid(crdCard));
                break;
            default:
                crdCard = new char[OTH];
                do {
                    genCC(ALL, crdCard);
                } while (!Valid(crdCard));
        }
        
        //Flip 1 digit
        flipDig(crdCard);
        
        //Check validation again
        if (Valid(crdCard)) valid++;
        else invalid++;
    }
    
    //Display outputs
    switch(choice){
        case 1:
            cout << "American Express Result:" << endl;
            break;
        case 2:
            cout << "Visa Result:" << endl;
            break;
        case 3:
            cout << "Master Card Result:" << endl;
            break;
        case 4:
            cout << "Discover Result:" << endl;
            break;
        default:
            cout << "All Result:" << endl;
        }
    cout << "Valid: " << valid << endl;
    cout << "Invalid: " << invalid << endl;
    
    //Exit Stage right!
    delete [] crdCard;
    
    return 0;
}

void flipDig(char cc[]){
    cc[rand()%15] = rndDgit();
}

void genCC(CrdCard card, char cc[]) {
    int temp = rand() % 4;
    switch (card) {
        case 0:
            prpAmex(cc, 15);
            break;
        case 1:
            prpVisa(cc, 16);
            break;
        case 2:
            prpMast(cc, 16);
            break;
        case 3:
            prpDisc(cc, 16);
            break;
        default:
            if (temp == 0) prpAmex(cc, 15);
            else if (temp == 1) prpVisa(cc, 16);
            else if (temp == 2) prpMast(cc, 16);
            else prpDisc(cc, 16);
    }
}

char Double(char c) {
    if (c <= '4') {
        c = ((c - '0') * 2) + '0';
    } else {
        c = (c - '0') * 2 - 9 + '0';
    }
    return c;
}

bool Valid(char cc[]) {
    int n = 16;
    //Copy to a new char array
    char luhn[n];
    for (int i = 0; i < n; i++) {
        luhn[i] = cc[i];
    }

    //Double every second digit,
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            luhn[i] = Double(luhn[i]);
        }
    }

    //Sum all digits, times 9, modulo 10 to get the check digit
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += luhn[i] - '0';
    }

    //Get the check digit
    char check;
    check = (sum * 9) % 10 + '0';
    //    cout << endl << check;

    //Check Validation
    if (check == '0') return true;
    else return false;
}

void prpDisc(char cc[], int n) {
    cc[0] = 54;
    cc[1] = 48;
    cc[2] = 49;
    cc[3] = 49;
    //Create a random cc in prep for Luhn checksum
    for (int i = 4; i < n; i++) {
        cc[i] = rndDgit();
    }
    //Put null terminator at the end
    for (int i = n; i < n + 1; i++) {
        cc[i] = '\0';
    }
}

void prpMast(char cc[], int n) {
    int temp = rand() % 2;
    cc[0] = 53;
    if (temp == 0) cc[1] = 49;
    else cc[1] = 53;
    //Create a random cc in prep for Luhn checksum
    for (int i = 2; i < n; i++) {
        cc[i] = rndDgit();
    }
    //Put null terminator at the end
    for (int i = n; i < n + 1; i++) {
        cc[i] = '\0';
    }
}

void prpVisa(char cc[], int n) {
    int temp = rand() % 3;
    cc[0] = 52;
    if (temp == 0) cc[1] = 48;
    else if (temp == 1) cc[1] = 49;
    else cc[1] = 50;
    //Create a random cc in prep for Luhn checksum
    for (int i = 2; i < n; i++) {
        cc[i] = rndDgit();
    }
    //Put null terminator at the end
    for (int i = n; i < n + 1; i++) {
        cc[i] = '\0';
    }
}

void prpAmex(char cc[], int n) {
    cc[0] = 51;
    cc[1] = 55;
    //Create a random cc in prep for Luhn checksum
    for (int i = 2; i < n; i++) {
        cc[i] = rndDgit();
    }
    //Put null terminator at the end
    for (int i = n; i < n + 1; i++) {
        cc[i] = '\0';
    }
}

char rndDgit() {
    return rand() % 10 + 48;
}