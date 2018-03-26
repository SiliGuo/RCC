/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on May 19, 2017
 * Purpose: Basic m-ary tree
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

#include "Tree.h"

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int> (time(0)));
    //Declare variables
    int child;
    //Prompt user for children numbers
    cout << "please enter the children numbers: ";
    cin >> child;
    Tree tree(child);
    //Fill the tree till third row
    tree.fill();
    //Output result
    cout << child << "-ary Tree:" << endl;
    tree.prntTree();
    //Exit stage
    return 0;
}

