/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on April 30, 2017
 * Purpose: Lab 5 Bloom Filter using hash 
 */

//System Libraries
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
using namespace std;

//User Libraries
#include "GeneralHashFunctions.h"

//Global Constants

//Function Prototypes

//Execution Begins here!

int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE = 15;
    int choice;
    string ans;
    string test;
    int a, b, temp;
    bool include;
    int pfa;
    float k, m, n;
    char enter;
    map<int, int> hash;
    map<int, int>::iterator iter;
    set<string> key;
    set<string>::iterator it;
    set<string>::reverse_iterator rit;

    //Fill the map
    for (int i = 0; i < SIZE; i++) {
        hash[i] = 0;
    }

    //Output Menu
    do {
        system("clear");
        cout << "\n   Hash Menu" << endl;
        cout << "   1. Hash a string." << endl;
        cout << "   2. Test existence." << endl;
        cout << "   0. Quit." << endl;
        do {
            cout << "Enter your choice (0~2): ";
            cin >> choice;
            if (choice < 0 || choice > 2)
                cout << "Invalid input! Please enter a number between 0~2." << endl;
        } while (choice < 0 || choice > 2);
        system("clear");

        switch (choice) {
            case 1:
                //Output map
                cout << "\n   Hash Map: " << endl;
                for (iter = hash.begin(); iter != hash.end(); iter++) {
                    cout << setw(4) << fixed << iter->second;
                }
                cout << endl;
                for (iter = hash.begin(); iter != hash.end(); iter++) {
                    cout << setw(4) << fixed << iter->first;
                }
                cout << endl;

                //Ask user for hash
                cout << "\n\n   Enter a string: ";
                cin >> ans;
                system("clear");

                //Insert key string into a set
                key.insert(ans);

                //Hash by fnv and elf
                a = FNVHash(ans) % 15;
                b = ELFHash(ans) % 15;

                //Add hash result to map
                if (hash[a] == 0) hash[a] = 1;
                if (hash[b] == 0) hash[b] = 1;

                //Output map
                cout << "\n   Hash Map: " << endl;
                for (iter = hash.begin(); iter != hash.end(); iter++) {
                    cout << setw(4) << fixed << iter->second;
                }
                cout << endl;
                for (iter = hash.begin(); iter != hash.end(); iter++) {
                    cout << setw(4) << fixed << iter->first;
                }
                cout << endl;

                //Output the process
                cout << "\n\n   Enter a string: " << ans << endl;
                cout << "\n   fnv: " << a << endl;
                cout << "   elf: " << b << endl;
                cout << "\n   Your set: [";
                rit = key.rbegin();
                for (it = key.begin(); it != key.end(); it++) {
                    cout << *it;
                    if (*it != *rit) cout << ", ";
                }
                cout << "]" << endl;
                break;
            case 2:
                //Output map
                cout << "\n   Hash Map: " << endl;
                for (iter = hash.begin(); iter != hash.end(); iter++) {
                    cout << setw(4) << fixed << iter->second;
                }
                cout << endl;
                for (iter = hash.begin(); iter != hash.end(); iter++) {
                    cout << setw(4) << fixed << iter->first;
                }
                cout << endl;

                //Ask user for test
                cout << "\n\n   Test an element for membership: ";
                cin >> test;
                system("clear");

                //Output map
                cout << "\n   Hash Map: " << endl;
                for (iter = hash.begin(); iter != hash.end(); iter++) {
                    cout << setw(4) << fixed << iter->second;
                }
                cout << endl;
                for (iter = hash.begin(); iter != hash.end(); iter++) {
                    cout << setw(4) << fixed << iter->first;
                }
                cout << endl;

                //Test if include
                include = false;
                a = FNVHash(test) % 15;
                b = ELFHash(test) % 15;
                if (hash[a] == 1 && hash[b] == 1)
                    include = true;

                //Output test result;
                cout << "\n\n   Test an element for membership: " << test << endl;
                cout << "\n   fnv:" << a << endl;
                cout << "   elf:" << b << endl;
                cout << "\n   Is the element in the set? ";
                if (include) cout << "maybe!" << endl;
                else cout << "no!" << endl;

                //Calculate false positive
                k = 2;
                m = 15;
                n = key.size();
                pfa = 100 * pow((1 - exp(-k * n / m)), k);
                cout << "\n   Probability of a false positive: " << pfa << "%" << endl;
        }
        //Press enter to continue
        cout << "\n   Press enter to continue." << endl;
        if (choice == 1 || choice == 2) {
            cin.ignore();
            do {
                enter = getchar();
            } while (enter != '\n');
        }

    } while (choice != 0);
    //Enter 0 to quit
    system("clear");
    cout << "You quit the hash program." << endl;

    //Exit Stage right!
    return 0;
}