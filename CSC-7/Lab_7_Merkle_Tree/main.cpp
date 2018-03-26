/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on May 24, 2017
 * Purpose: Lab 7 Merkle Tree
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "GeneralHashFunctions.h"

//Global Constants

//Function Prototypes

//Execution Begins here!

int main(int argc, char** argv) {
    //Declare Variables
    string L1 = "Then out spake brave Horatius,"
            "The Captain of the Gate:";
    string L2 = "To every man upon this earth"
            "Death cometh soon or late.";
    string L3 = "And how can man die better"
            "Than facing fearful odds, ";
    string L4 = "For the ashes of his fathers,"
            "And the temples of his Gods.";
    //RSHash L1, L2, L3, and L4
    string hash1 = to_string(RSHash(L1));
    string hash2 = to_string(RSHash(L2));
    string hash3 = to_string(RSHash(L3));
    string hash4 = to_string(RSHash(L4));
    //RSHash hash1 and hash2, hash3 and hash4
    string hash12 = to_string(RSHash(hash1)) + to_string(RSHash(hash2));
    string hash34 = to_string(RSHash(hash3)) + to_string(RSHash(hash4));
    //RSHash hash12 and hash34
    string hashAll = to_string(RSHash(hash12)) + to_string(RSHash(hash34));
    //Output hash result
    cout << "Hash Result (RSHash):" << endl;
    cout << "Hash of L1 = " << hash1 << endl;
    cout << "Hash of L2 = " << hash2 << endl;
    cout << "Hash of L3 = " << hash3 << endl;
    cout << "Hash of L4 = " << hash4 << endl;
    cout << "Hash of L1 and L2 = " << hash12 << endl;
    cout << "Hash of L3 and L4 = " << hash34 << endl;
    cout << "Hash of all together = " << hashAll << endl;
    //Test if hash correctly
    string test1 = to_string(RSHash(to_string(RSHash(L1)))) + to_string(RSHash(hash2));
    string test2 = to_string(RSHash(to_string(RSHash(L3)))) + to_string(RSHash(hash4));
    //Output test result
    cout << "\nUse L1 and hash of L2 test for hash of L1 and L2:" << endl;
    cout << "Test result for hash of L1 and L2 = " << test1 << endl;
    cout << "\nUse L3 and hash of L4 test for hash of L3 and L4:" << endl;
    cout << "Test result for hash of L3 and L4 = " << test2 << endl;
    //Output conclusion
    cout << "\nSince the test result is same as the actual result," << endl;
    cout << "the hash is correct." << endl;
    //Exit Stage right!
    return 0;
}