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
    //Declare variables
    int ary[10];
    int count = 0;
    bool have;
    int nBits = 800;
    int nHash = 100;
    int nTest = 100;
    int hash = 2;
    int bitVec[nBits];

    //Initialize bitVec
    for (int i = 0; i < nBits; i++) {
        bitVec[i] = 0;
    }

    string key[] = {"James", "John", "Robert", "Michael", "William", "David", "Richard", "Charles", "Joseph", "Thomas",
        "Christopher", "Daniel", "Paul", "Mark", "Donald", "George", "Kenneth", "Steven", "Edward", "Brian",
        "Ronald", "Anthony", "Kevin", "Jason", "Matthew", "Gary", "Timothy", "Jose", "Larry", "Jeffrey",
        "Frank", "Scott", "Eric", "Stephen", "Andrew", "Raymond", "Gregory", "Joshua", "Jerry", "Dennis",
        "Walter", "Patrick", "Peter", "Harold", "Douglas", "Henry", "Carl", "Arthur", "Ryan", "Gorge",
        "Joe", "Juan", "Jack", "Albert", "Jonathan", "Justin", "Terry", "Gerald", "Keith", "Samuel",
        "Willie", "Ralph", "Lawrence", "Nicholas", "Roy", "Benjamin", "Bruce", "Brandon", "Adam", "Harry",
        "Fred", "Wayne", "Aaron", "Randy", "Howard", "Eugene", "Carlos", "Russell", "Bobby", "Victor",
        "Martin", "Ernest", "Phillip", "Todd", "Jesse", "Craig", "Alan", "Shawn", "Clarence", "Sean",
        "Philip", "Chris", "Johnny", "Earl", "Jimmy", "Antonio", "Danny", "Bryan", "Tony", "Luis"};

    string test[] = {"Mary", "Patricia", "Linda", "Barbara", "Elizabeth", "Jennifer", "Maria", "Susan", "Margaret", "Dorothy",
        "Lisa", "Nancy", "Karen", "Helen", "Sandra", "Donna", "Carol", "Ruth", "Sharon", "Michelle",
        "Laura", "Sarah", "Kimberly", "Deborah", "Jessica", "Shirley", "Cynthia", "Angela", "Melissa", "Brenda",
        "Amy", "Anna", "Rebecca", "Virginia", "Kathleen", "Pamela", "Martha", "Debra", "Amanda", "Stephanie",
        "Carolyn", "Christine", "Marie", "Janet", "Catherine", "Frances", "Ann", "Joyce", "Diane", "Alice",
        "Julie", "Heather", "Teresa", "Doris", "Gloria", "Evelyn", "Jean", "Cheryl", "Mildred", "Katherine",
        "Joan", "Ashley", "Judith", "Rose", "Janice", "Kelly", "Nicole", "Judy", "Christina", "Kathy",
        "Theresa", "Beverly", "Denise", "Tammy", "Irene", "Jane", "Lori", "Rachel", "Marilyn", "Andrea",
        "Kathryn", "Louise", "Sara", "Anne", "Jacqueline", "Wanda", "Bonnie", "Julia", "Ruby", "Lois",
        "Tina", "Phyllis", "Norma", "Paula", "Diana", "Annie", "Lillian", "Emily", "Robin", "Peggy"};

    //Test 1
    //Hash 100 elements using 11 ways
    for (int i = 0; i < nHash; i++) {
        ary[0] = RSHash(key[i]) % nBits;
        ary[1] = JSHash(key[i]) % nBits;
        for (int j = 0; j < 2; j++)
            if (bitVec[ary[j]] == 0) bitVec[ary[j]] = 1;
    }

    //Test another 100 elements
    for (int i = 0; i < nTest; i++) {
        ary[0] = RSHash(test[i]) % nBits;
        ary[1] = JSHash(test[i]) % nBits;


        have = true;
        for (int j = 0; j < hash; j++) {
            if (bitVec[ary[j]] != 1) {
                have = false;
                break;
            }
        }
        if (have) count++;
    }
    cout << "Hash Function fpa Test:" << endl;
    cout << "\n   First test:" << endl;
    cout << "   Total Bits =    " << nBits << endl;
    cout << "   Hash Num =      " << nHash << endl;
    cout << "   Test Num =      " << nTest << endl;
    cout << "   Hash Func Num =   " << hash << endl;
    cout << "   Count Num =       " << count << endl;

    //Calculate false positive
    cout << "   Probability of a false positive: " << count << "%" << endl;

    //Test 2
    count = 0;
    nBits = 750;
    nHash = 100;
    hash = 10;
    int bitVect[nBits];
    for (int i = 0; i < nBits; i++)
        bitVect[i] = 0;

    //Hash 100 elements using 10 ways
    for (int i = 0; i < nHash; i++) {
        ary[0] = RSHash(key[i]) % nBits;
        ary[1] = JSHash(key[i]) % nBits;
        ary[2] = PJWHash(key[i]) % nBits;
        ary[3] = ELFHash(key[i]) % nBits;
        ary[4] = BKDRHash(key[i]) % nBits;
        ary[5] = SDBMHash(key[i]) % nBits;
        ary[6] = DJBHash(key[i]) % nBits;
        ary[7] = DEKHash(key[i]) % nBits;
        ary[8] = FNVHash(key[i]) % nBits;
        ary[9] = BPHash(key[i]) % nBits;
        for (int j = 0; j < 10; j++)
            if (bitVect[ary[j]] == 0) bitVect[ary[j]] = 1;
    }

    //Test another 100 elements
    for (int i = 0; i < nTest; i++) {
        ary[0] = RSHash(test[i]) % nBits;
        ary[1] = JSHash(test[i]) % nBits;
        ary[2] = PJWHash(test[i]) % nBits;
        ary[3] = ELFHash(test[i]) % nBits;
        ary[4] = BKDRHash(test[i]) % nBits;
        ary[5] = SDBMHash(test[i]) % nBits;
        ary[6] = DJBHash(test[i]) % nBits;
        ary[7] = DEKHash(test[i]) % nBits;
        ary[8] = FNVHash(test[i]) % nBits;
        ary[9] = BPHash(test[i]) % nBits;


        have = true;
        for (int j = 0; j < hash; j++) {
            if (bitVect[ary[j]] != 1) {
                have = false;
                break;
            }
        }
        if (have) count++;
    }
    cout << "\n   Second test: " << endl;
    cout << "   Total Bits =    " << nBits << endl;
    cout << "   Hash Num =      " << nHash << endl;
    cout << "   Test Num =      " << nTest << endl;
    cout << "   Hash Func Num =   " << hash << endl;
    cout << "   Count Num =       " << count << endl;

    //Calculate false positive
    cout << "   Probability of a false positive: " << count << "%" << endl;

    //Exit Stage right!
    return 0;
}