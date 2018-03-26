/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on February 15, 2017
 * Purpose: Lab 6 Hashcash
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <map>
using namespace std;

//User Libraries
#include "GeneralHashFunctions.h"

//Global Constants

//Function Prototypes

//Execution Begins here!

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int> (time(0)));
    //Declare Variables
    map<int, unsigned int> range; //store numbers in corresponding range
    int randNum = rand(); //random number
    int hash = 11; //11 hash functions
    int power = 9; //highest power
    unsigned int res; //Hash result
    string name[] = {"RSHash", "JSHash", "PJWHash", "ELFHash", "BKDRHash",
        "SDBMHash", "DJBHash", "DEKHash", "BPHash", "FNVHash", "APHash"};
    int size = 1e7; //Test size
    //Initialize Variables
    for (int i = 1; i <= power; i++) {
        range[i] = 0;
    }
    //Initial random number
    cout << "The initial random number = " << randNum << endl;
    //Create a message
    string msg = "What a difference a day makes!";
    cout << "The base message = " << msg << endl;
    //Test all 11 hash functions
    cout << "\nHash Range Result: " << endl << endl;
    for (int i = 0; i < hash; i++) {
        //Clear map
        range.clear();
        //Record the start time
        int strTime = time(0);
        //        do {
        for (int k = 0; k < size; k++) {
            //Create a concatenation of the two by first converting the random
            //number to a string
            ostringstream convert; // stream used for the conversion
            convert << randNum++; // insert the textual representation of 'Number' in the characters in the stream
            string strRnd = convert.str();
            string newMsg = msg + strRnd;
            //Hash message
            switch (i) {

                case 0:
                    res = RSHash(newMsg);
                    break;
                case 1:
                    res = JSHash(newMsg);
                    break;
                case 2:
                    res = PJWHash(newMsg);
                    break;
                case 3:
                    res = ELFHash(newMsg);
                    break;
                case 4:
                    res = BKDRHash(newMsg);
                    break;
                case 5:
                    res = SDBMHash(newMsg);
                    break;
                case 6:
                    res = DJBHash(newMsg);
                    break;
                case 7:
                    res = DEKHash(newMsg);
                    break;
                case 8:
                    res = BPHash(newMsg);
                    break;
                case 9:
                    res = FNVHash(newMsg);
                    break;
                case 10:
                    res = APHash(newMsg);
            }
            //Test for range
            range[static_cast<int> (log10(res))]++;
        } //while (range[1] != 1);
        //Take the time it took
        int endTime = time(0);
        //Output result
        cout << "------- " << name[i] << " ----------" << endl;
        cout << "Range Result: " << endl;
        for (int j = power; j > 0; j--)
            cout << "10^" << j << "~10^" << j + 1 << ": " << range[j] << endl;
        cout << "Total time: " << endTime - strTime << " sec" << endl;
        cout << endl;
    }
    //Exit Stage right!
    return 0;
}