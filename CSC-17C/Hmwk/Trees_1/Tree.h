/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on May 19, 2017
 * Purpose: Basic m-ary tree
 */

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cmath>

#include "Node.h"

class Tree {
private:
    Node *front;
    int child;
    int randNum();

public:
    Tree(int);
    void clean(Node *node);
    Node *newNode(int);
    void fill();
    void prntTree();

};

#endif /* TREE_H */

