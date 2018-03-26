/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on 03/01/2017
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
char rndDgit();
void prpLuhn(char[], int);
void Luhn(char[], int);
char Double(char);
void valid(char);

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int> (time(0)));
    
    //Declare variables
    const int SIZE = 12;
    char crdCard[SIZE];
    
    //Prepare for Luhn encoding
    cout << "A random number created in Prep for Luhn Digit" << endl;
    prpLuhn(crdCard, SIZE - 2);
    
    //Output the preLuhn credit card
    cout << crdCard << endl << endl;

    //Now create a function that fills the last digit
    //using the Luhn Algorithm
    Luhn(crdCard, SIZE - 2);

    //Exit Stage Right
    return 0;
}

void prpLuhn(char cc[], int n) {
    //Create a random cc in prep for Luhn checksum
    for (int i = 0; i < n; i++) {
        cc[i] = rndDgit();
    }
    //Put null terminator at the end
    for (int i = n; i <= n + 1; i++) {
        cc[i] = '\0';
    }
}

char rndDgit() {
    return rand() % 10 + 48;
}

void Luhn(char cc[], int n) {
    //Copy to a new char array
    char luhn[n];
    for (int i = 0; i < n; i++) {
        luhn[i] = cc[i];
    }

    //Double every second digit,
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            cc[i] = Double(cc[i]);
        }
    }
//    cout << "After double:" << endl << cc << endl;
    
    //Sum all digits, times 9, modulo 10 to get the check digit
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += cc[i] - '0';
    }
//    cout << "sum is:" << sum << endl;
    
    //Get the check digit
    luhn[n] = (sum * 9) % 10 + '0';
//    cout << "The check digit: " << luhn[n] << endl;
    
    //Pull null terminator at the end
    luhn[n + 1] = '\0';
    
    //Output the result
    cout << "The random number with Luhn Encoding, Output Here!" << endl;
    cout << luhn << endl << endl;
    //Check validation
    valid(luhn[n]);
}

char Double(char c) {
    if (c <= '4') {
        c = ((c - '0') * 2) + '0';
    } else {
        c = (c - '0') * 2 - 9 + '0';
    }
    return c;
}

void valid(char c) {
    if (c == '0') {
        cout << "The number is valid!";
    } else {
        cout << "The number is invalid!";
    }
    cout << endl;
}