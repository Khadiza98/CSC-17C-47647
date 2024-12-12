/* 
 * File:   Tree.h
 * Author: Khadiza Akter
 * Created on December 11, 2024, 5:45 PM
 * Purpose: Tree class file specification
 */
#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// AVL Tree Class
class Tree {
private:
    Node* root;  // Root of the AVL Tree

    // Get the height of the node
    int height(Node* node) {
        return (node == nullptr) ? 0 : max(height(node->left), height(node->right)) + 1;
    }

    // Balance Factor Calculation
    int balanceFactor(Node* node) {
        return (node == nullptr) ? 0 : height(node->left) - height(node->right);
    }

    // Rotate Right (LL Case)
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        x->right = y;
        return x;
    }

    // Rotate Left (RR Case)
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    // Balance the Node
    Node* balance(Node* node) {
        int bf = balanceFactor(node);

        if (bf > 1) {
            if (balanceFactor(node->left) < 0)
                node->left = rotateLeft(node->left);  // Left-Right case
            return rotateRight(node);  // Left-Left case
        }
        if (bf < -1) {
            if (balanceFactor(node->right) > 0)
                node->right = rotateRight(node->right);  // Right-Left case
            return rotateLeft(node);  // Right-Right case
        }
        return node;
    }

    // Insert a value
    Node* insert(Node* node, const string& value) {
        if (node == nullptr) return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            return node;  // No duplicates allowed

        return balance(node);
    }

    // Search Value and Count Nodes Visited
    int search(Node* node, const string& value, int& nodesVisited) {
        if (node == nullptr) return -1;  // Not Found
        nodesVisited++;
        if (value == node->data)
            return nodesVisited;
        else if (value < node->data)
            return search(node->left, value, nodesVisited);
        else
            return search(node->right, value, nodesVisited);
    }

    // In-Order Traversal
    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

public:
    Tree() : root(nullptr) {}

    // Public Functions
    void insert(const string& value) {
        root = insert(root, value);
    }

    int search(const string& value) {
        int nodesVisited = 0;
        return search(root, value, nodesVisited);
    }

    void displayInOrder() {
        inOrderTraversal(root);
        cout << endl;
    }

    string getRoot() {
        return root ? root->data : "Tree is empty";
    }

    int getHeight() {
        return height(root);
    }
};

#endif  // TREE_H
