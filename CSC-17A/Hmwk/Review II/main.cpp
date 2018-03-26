/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on September 21, 2016, 4:23 PM
 * Purpose:  Review II: Create a truth table
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Function prototype
char boolean( bool );

//Execution Begin Here!

int main(int argc, char** argv) {
    //Declare variables and an array
    bool x = true, y = true;
    const unsigned int SIZE = 13;
    string truth[SIZE] = {"X", "Y", "!X", "!Y", "X&&Y", "X||Y", "X^Y", "X^Y^Y", "X^Y^X", "!(X||Y)", "!X&&!Y", "!(X&&Y)", "!X||!Y"};
    
    //Output the truth table in format
    cout << setw(45) << " " << "The Truth Table" << endl << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << left << setw(8) << truth[i];
    }
    cout << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    
    //Use for loop to output truth and false mark
    for (int i = 0; i < 4; i++) {
        if (i == 1) {
            y = false;
        } else if (i == 2) {
            x = false;
            y = true;
        } else {
            y = false;
        }
        
        cout << setw(8) << boolean(x);
        cout << setw(8) << boolean(y);
        cout << setw(8) << boolean(!x);
        cout << setw(8) << boolean(!y);
        cout << setw(8) << boolean(x && y);
        cout << setw(8) << boolean(x || y);
        cout << setw(8) << boolean(x ^ y);
        cout << setw(8) << boolean(x ^ y ^ y);
        cout << setw(8) << boolean(x ^ y ^ x);
        cout << setw(8) << boolean(!(x || y));
        cout << setw(8) << boolean(!x && !y);
        cout << setw(8) << boolean(!(x && y));
        cout << setw(8) << boolean(!x || !y);
        cout << endl;
    }

    //Exit stage right!
    return 0;
}

//Function implementation
char boolean(bool tf) {
    
    return tf ? 'T' : 'F';//By using conditional operator
}