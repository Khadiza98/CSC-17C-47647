/* 
 * File:   HashTable.h
 * Author: Khadiza Akter
 * Created on December 9, 2024, 10:27 AM
 * Purpose: HashTable class specification
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Node.h"
#include <string>    // For string operations
#include <map>       // For ordered output
using namespace std; //STD Name-space where Library is compiled

class HashTable {
private:
    Node** table;   // Array of pointers to linked lists
    int size;       // Size of the hash table

    // Helper functions
    int charToKeypadNumber(char c);
    int hashFunction(const string& initials);

public:
    // Constructor and Destructor
    HashTable(int size);
    ~HashTable();

    // Member functions
    void insert(const string& initials);
    void collectStatistics(int numInitials);
};

#endif /* HASHTABLE_H */

