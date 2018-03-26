/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on May 19, 2017
 * Purpose: Basic m-ary tree
 */

#include "Tree.h"

Tree::Tree(int m) {
    front = NULL;
    child = m;
}

Node *Tree::newNode(int n) {
    Node *temp = new Node;
    temp->data = n;
    return temp;
}

void Tree::fill() {
    front = newNode(randNum());
    for (int i = 0; i < child; i++) {
        front->next.push_back(newNode(randNum()));
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < child; j++) {
            front->next[i]->next.push_back(newNode(randNum()));
        }
    }
}

void Tree::prntTree() {
    cout << front->data << endl;
    for (int i = 0; i < child; i++) {
        cout << front->next[i]->data << "  ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < child; j++) {
            cout << front->next[i]->next[j]->data << " ";
        }
        cout << " ";
    }
    cout << endl;
}

int Tree::randNum() {
    return rand() % 100;
}