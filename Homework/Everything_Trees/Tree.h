/* 
 * File:   Tree.h
 * Author: Khadiza Akter
 * Created on November 23, 2024, 3:14 PM
 * Purpose: Specification of tree class
 */

#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <iostream>
using namespace std;
class Tree {
public:
        Node *root;

    Tree() { root = NULL; } // Constructor

    // AVL Tree methods
    int height(Node *);                // Get height of tree
    int diff(Node *);                  // Get balance factor
    Node *rr_rotation(Node *);         // Right-right rotation
    Node *ll_rotation(Node *);         // Left-left rotation
    Node *lr_rotation(Node *);         // Left-right rotation
    Node *rl_rotation(Node *);         // Right-left rotation
    Node *balance(Node *);             // Balance the tree
    Node *insert(Node *, int);         // Insert a node
    Node *deleteNode(Node *, int);     // Delete a node
    Node* maxValueNode(Node*);
    void display(Node *, int);         // Display tree structure
    void inorder(Node *);              // InOrder traversal
    void preorder(Node *);             // PreOrder traversal
    void postorder(Node *);            // PostOrder traversal
};

#endif /* TREE_H */

