/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on May 19, 2017
 * Purpose: Basic m-ary tree
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    vector<Node *> next;
};


#endif /* NODE_H */

