/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 22, 2024, 12:46 AM
 * Purpose: Create a tree class, Functions to include would be insert, delete,
            balance, print with the 4 types of traversals. Show that it works
 *          by randomly filling the tree, and selectively deleting 
 *          elements and then traversing the tree.
 */
#include <iostream>  // Input/output
#include <algorithm> // Standard algorithms
#include <cstdlib>   // Utilities like rand()
#include <ctime>     // Time functions
using namespace std; // STD Name-space where Library is compiled

//User Libraries
#include "Tree.h"

//Function Prototypes
bool isTreeEmpty(Node *);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    Tree tree;
    int choice, item;

    // Randomly fill the tree
    cout << "Randomly inserting values into AVL Tree:" << endl;
    for (int i = 0; i < 2; i++) {
        int randomValue = rand() % 100 + 1;
        cout << randomValue << " ";
        tree.root = tree.insert(tree.root, randomValue);
    }
    cout << endl;

    // Menu-driven program
    do {
        cout << "\n----------------------------------------" << endl;
        cout << "========== Tree Implementation =========" << endl;
        cout << "----------------------------------------" << endl;
        cout << "1. Insert Element\n2. Delete Element\n3. Display Tree\n4. "
                "InOrder Traversal\n5. PreOrder Traversal\n"
                "6. PostOrder Traversal\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to be inserted: ";
            cin >> item;
            tree.root = tree.insert(tree.root, item);
            break;
        case 2:
            if (isTreeEmpty(tree.root)) break;
            cout << "Enter value to be deleted: ";
            cin >> item;
            tree.root = tree.deleteNode(tree.root, item);
            break;
        case 3:
            if (isTreeEmpty(tree.root)) break;
            cout << "Balanced AVL Tree:" << endl;
            tree.display(tree.root, 1);
            break;
        case 4:
            if (isTreeEmpty(tree.root)) break;
            cout << "InOrder Traversal:" << endl;
            tree.inorder(tree.root);
            cout << endl;
            break;
        case 5:
            if (isTreeEmpty(tree.root)) break;
            cout << "PreOrder Traversal:" << endl;
            tree.preorder(tree.root);
            cout << endl;
            break;
        case 6:
            if (isTreeEmpty(tree.root)) break;
            cout << "PostOrder Traversal:" << endl;
            tree.postorder(tree.root);
            cout << endl;
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);
    // Exit the program here!
    return 0;
}

// Helper function to check if the tree is empty
bool isTreeEmpty(Node *root) {
    if (!root) {
        cout << "Tree is Empty" << endl;
        return true; // Tree is empty
    }
    return false; // Tree is not empty
}