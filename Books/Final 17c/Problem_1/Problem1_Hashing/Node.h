/* 
 * File:   Node.h
 * Author: Khadiza Akter
 * Created on December 9, 2024, 10:27 AM
 * Purpose: Node file specification
 */

#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

// Node structure for the linked list
struct Node {
    string data;   // The initials stored in the node
    Node* next;    // Pointer to the next node

    // Constructor
    Node(const string& data) : data(data), next(nullptr) {}
};

#endif /* NODE_H */

