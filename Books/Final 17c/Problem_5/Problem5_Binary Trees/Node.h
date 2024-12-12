/* 
 * File:   Node.h
 * Author: Khadiza Akter
 * Created on December 11, 2024, 5:45 PM
 * Purpose: Node structure file specification
 */

#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
using namespace std;

// Binary Tree Node for Strings
struct Node {
    string data;   // The initials stored
    Node* left;    // Left child
    Node* right;   // Right child
    Node(const string& val) : data(val), left(nullptr), right(nullptr) {}
};

#endif /* NODE_H */

