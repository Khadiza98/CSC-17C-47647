/* 
 * File:   HashTable.h
 * Author: Khadiza Akter
 * Created on December 11, 2024, 5:40 PM
 * Purpose: HashTable class specification
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
using namespace std;

// Hash Table Class
class HashTable {
private:
    unordered_map<int, list<string>> table;
    int size;

    // Map Characters to Keypad Numbers
    int charToKeypadNumber(char c) {
        if (c >= 'A' && c <= 'C') return 2;
        if (c >= 'D' && c <= 'F') return 3;
        if (c >= 'G' && c <= 'I') return 4;
        if (c >= 'J' && c <= 'L') return 5;
        if (c >= 'M' && c <= 'O') return 6;
        if (c >= 'P' && c <= 'S') return 7;
        if (c >= 'T' && c <= 'V') return 8;
        if (c >= 'W' && c <= 'Z') return 9;
        return 0;
    }

    // Compute Hash Value
    int hashFunction(const string& initials) {
        int hash = 0;
        for (char c : initials) {
            hash = hash * 10 + charToKeypadNumber(c);
        }
        return hash % size;
    }

public:
    HashTable(int size) : size(size) {}

    void insert(const string& initials) {
        int hashValue = hashFunction(initials);
        table[hashValue].push_back(initials);
    }

    int search(const string& initials) {
        int hashValue = hashFunction(initials);
        int comparisons = 0;
        for (const auto& val : table[hashValue]) {
            comparisons++;
            if (val == initials) return comparisons;
        }
        return comparisons;  // Not Found
    }
};


#endif /* HASHTABLE_H */

