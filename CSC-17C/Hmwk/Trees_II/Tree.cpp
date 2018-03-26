/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on May 26, 2017
 * Purpose:Trees_II: Binary tree with insertion, deletion, balance, and print in 3 traversals
 */

#include "Tree.h"

//Constructor

Tree::Tree() {
    root = NULL;
}

//Destructor

Tree::~Tree() {
    clean(root);
}

//Deletion

void Tree::clean(Node *node) {
    if (node != NULL) {
        clean(node->left);
        clean(node->right);
        delete node;
    }
}

int Tree::getHeight(Node* n) {
    if (n == NULL) return 0;
    return n->height;
}

//insertion

void Tree::insert(int key) {
    //create a new node for insertion
    Node *newNode = new Node;
    newNode->value = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    //insert with recursion
    insert(root, newNode);
}

//Private insertion

void Tree::insert(Node *&node, Node *&newNode) {
    if (node == NULL) {
        node = newNode;
    } else if (newNode->value <= node->value) {
        insert(node->left, newNode);
    } else {
        insert(node->right, newNode);
    }
    //Calculate the height
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    //Right case
    if (difference(node)<-1) {
        if (newNode->value >= node->right->value) {
            rotateRR(node);
        } else {
            rotateRL(node);
        }
    }
    if (difference(node) > 1) {
        if (newNode->value <= node->left->value) {
            rotateLL(node);
        } else {
            rotateLR(node);
        }
    }
}

int Tree::difference(Node *node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

void Tree::rotateRR(Node *&parent) {
    Node *node = parent->right;
    parent->right = node->left;
    node->left = parent;
    //Calculate the height
    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    parent = node;
}

void Tree::rotateLL(Node *&parent) {
    Node *node = parent->left;
    parent->left = node->right;
    node->right = parent;
    //Calculate the height
    parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    parent = node;
}

void Tree::rotateRL(Node *&z) {
    rotateLL(z->right);
    rotateRR(z);
}

void Tree::rotateLR(Node *&z) {
    rotateRR(z->left);
    rotateLL(z);
}

void Tree::delet(int n) {
    delet(root, n);
    //size --
}

void Tree::delet(Node *&node, int key) {
    if (node == NULL) return;
    if (key < node->value) {
        //Recursion on left
        delet(node->left, key);
    } else if (key > node->value) {
        //Recursion on right
        delet(node->right, key);
    } else {//Delete current node
        //Less than one child
        if ((node->left == NULL) || (node->right == NULL)) {
            //0 child
            if ((node->left == NULL) && (node->right == NULL)) {
                Node *temp = node;
                node = NULL;
                delete temp;
            } else {//1 child
                Node *temp = node->left ? node->left : node->right;
                Node *temp2 = node;
                node = temp;
                delete temp2;
            }
        } else {//2 children
            Node *temp = node->left;
            if (temp != NULL) {
                while (temp->right != NULL) {
                    temp = temp->right;
                }
            }
            node->value = temp->value;
            delet(node->left, node->value);
        }
    }
    if (node == NULL) return;
    //Calculate height
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    //Balance tree
    if (difference(node)<-1) {
        if (difference(node->right) < 0) {
            rotateRR(node);
        } else {
            rotateRL(node);
        }
    }
    if (difference(node) > 1) {
        if (difference(node->left) > 0) {
            rotateLL(node);
        } else {
            rotateLR(node);
        }
    }
}

void Tree::prntNode(Node *node) {
    cout << node->value << " ";
}

void Tree::preOrder(Node *node) {
    if (node != NULL) {
        prntNode(node);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void Tree::inOrder(Node *node) {
    if (node != NULL) {
        inOrder(node->left);
        prntNode(node);
        inOrder(node->right);
    }
}

void Tree::postOrder(Node *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        prntNode(node);
    }
}

void Tree::prePrnt() {
    preOrder(root);
}

void Tree::inPrnt() {
    inOrder(root);
}

void Tree::postPrnt() {
    postOrder(root);
}

int Tree::max(int a, int b) {
    return a >= b ? a : b;
}