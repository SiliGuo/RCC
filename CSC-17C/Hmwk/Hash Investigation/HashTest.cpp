/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on May 9, 2017
 * Purpose: Hash Investigation; find first collision and the maximum collision
 */

//System Libraries
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <set>
#include <map>
using namespace std;

//User Libraries
#include "GeneralHashFunctions.h"

//Global Constants

//Function Prototypes

//Execution Begins here!

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int> (time(0)));

    //Declare Variables
    string key = "Test key: "; //Original key
    string testKey; //The key put in hash
    vector<int> numVec; //Store hash results in vector
    set<int> numSet; //Store hash results in set
    map<int, int> freq; //Store the frequency of collision of hashing result
    map<int, int>::iterator iter; //Iterator for map
    bool col; //Have collision?
    int firstCol; //The position that first collision happens
    int maxCol; //Total collisions in the test
    int size; //Test numbers
    int res; //Hold hash result
    int randNum;
    string hashName[11] = {"RSHash", "JSHash", "PJWHash", "ELFHash", "BKDRHash",
        "SDBMHash", "DJBHash", "DEKHash", "BPHash", "FNVHash", "APHash"};

    //Test for all 11 hashes
    cout << "Hash Investigation: " << endl << endl;
    for (int count = 0; count < 11; count++) {

        //Output hash names
        cout << hashName[count] << ": " << endl;

        //Start loop as size = 10, 100, and 1000
        for (int i = 2; i < 5; i++) {
            //Initialize value
            size = pow(10, i);
            col = false;
            firstCol = 0;
            maxCol = 0;
            numVec.clear();
            numSet.clear();
            freq.clear();

            //Create a random number
            randNum = rand();

            for (int j = 0; j < size; j++) {
                //Initialize test key
                ostringstream convert;
                convert << randNum++;
                string strRnd = convert.str();
                testKey = key + strRnd;

                //Hash
                switch (count) {
                    case 0:
                        res = RSHash(testKey) % size;
                        break;
                    case 1:
                        res = JSHash(testKey) % size;
                        break;
                    case 2:
                        res = PJWHash(testKey) % size;
                        break;
                    case 3:
                        res = ELFHash(testKey) % size;
                        break;
                    case 4:
                        res = BKDRHash(testKey) % size;
                        break;
                    case 5:
                        res = SDBMHash(testKey) % size;
                        break;
                    case 6:
                        res = DJBHash(testKey) % size;
                        break;
                    case 7:
                        res = DEKHash(testKey) % size;
                        break;
                    case 8:
                        res = BPHash(testKey) % size;
                        break;
                    case 9:
                        res = FNVHash(testKey) % size;
                        break;
                    case 10:
                        res = APHash(testKey) % size;
                }


                //Store result in vector
                numVec.push_back(res);
                //Store result in set, and count frequency
                if (numSet.insert(res).second)//new value
                    freq[res] = 1;
                else//existed value
                    freq[res]++;

                //Find first collision position 
                if ((!col) && (numVec.size() != numSet.size())) {
                    firstCol = j;
                    col = true;
                }
            }

            //Find maximum collision number
            for (iter = freq.begin(); iter != freq.end(); iter++) {
                if (iter->second > maxCol) maxCol = iter->second;
            }

            //        //For test
            //        for (iter = freq.begin(); iter != freq.end(); iter++) {
            //            cout << iter->first << " "; 
            //        }
            //        cout << endl;
            //        for (iter = freq.begin(); iter != freq.end(); iter++) {
            //            cout << iter->second << " "; 
            //        }
            //        cout << endl;

            //Output result
            //        cout << "RSHash:" << endl;
            cout << "Size = " << size << endl;
            cout << "Max Collision Number = " << maxCol << endl;
            cout << "First collision at position " << firstCol << endl;
            if (size == 10000) cout << "-------------------------------------" << endl;
            cout << endl;
        }
    }

    //Exit Stage right!
    return 0;
}