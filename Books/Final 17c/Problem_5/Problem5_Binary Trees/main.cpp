/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on December 10, 2024, 3:46 AM
 * Purpose: Take problem 1 and put each of 3 letters in a sorted binary tree. 
 *          Compare number of nodes to identify a match with the hash vs. the
 *          tree. Use the AVL technique to balance the tree.
 */

// System Libraries
#include <iostream>  // Input/Output Library
#include <string>    // For workin with string
#include <cstdlib>   // For rand()
#include <ctime>     // For time()
#include <vector>    // For vector utility
using namespace std; // STD Name-space where Library is compiled

// User Libraries
#include "Tree.h"
#include "HashTable.h"

// Function Prototypes
string generateRandomInitials();

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    // Set random number seed once here
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    // Declare variables here
    const int TABLE_SIZE = 512;
    const int NUM_INITIALS = 512;
    vector<string> initials;
    
    HashTable hashTable(TABLE_SIZE);
    Tree avlTree;

    // Insert Random Initials
    for (int i = 0; i < NUM_INITIALS; ++i) {
        string init = generateRandomInitials();
        initials.push_back(init);
        hashTable.insert(init);  // Insert into Hash Table
        avlTree.insert(init);    // Insert into AVL Tree
    }

    // Search Comparison
    cout << "Search Results (Comparing Nodes Visited):\n";
    cout << "Key    | Hash Table Nodes | AVL Tree Nodes\n\n";

    for (int i = 0; i < 10; ++i) {
        string target = initials[rand() % NUM_INITIALS];
        int hashNodesVisited = hashTable.search(target);
        int avlNodesVisited = avlTree.search(target);
        cout << target << "    |         " << hashNodesVisited 
             << "        |        " << avlNodesVisited << "\n";
    }

    // Exit the program!
    return 0;
}

// Generate Random Initials
string generateRandomInitials() {
    string initials;
    for (int i = 0; i < 3; ++i) {
        initials += 'A' + rand() % 26;  // Random Letters A-Z
    }
    return initials;
}