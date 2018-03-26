/* 
 * File:   Tree.h
 * Author: admin
 *
 * Created on December 1, 2015, 9:16 AM
 */

#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

class Tree {
private:

    struct Node {
        int value;
        struct Node *left;
        struct Node *right;
        int height;
    };
    Node *root;
    void insert(Node *&, Node *&);
    void delet(Node *&, int);
    int difference(Node *);
    void clean(Node *);
    int getHeight(Node *);
    int max(int, int);
    //function for printing
    void preOrder(Node *);
    void inOrder(Node *);
    void postOrder(Node *);
    void prntNode(Node *);
    //rotate functions
    void rotateRR(Node *&);
    void rotateLL(Node *&);
    void rotateRL(Node *&);
    void rotateLR(Node *&);
public:
    Tree();
    ~Tree();
    void insert(int);
    void delet(int);
    void prePrnt();
    void inPrnt();
    void postPrnt();
};
#endif /* TREE_H */