/* 
 * File:   HashTable.cpp
 * Author: Khadiza Akter
 * Created on December 9, 2024, 10:27 AM
 * Purpose: HashTable class implementation
 */

#include "HashTable.h"
#include <iostream>  // For input/output
#include <string>    // For string operations
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time() seeding
#include <cmath>     // For exp() and pow()

using namespace std;

// Constructor
HashTable::HashTable(int size) : size(size) {
    table = new Node * [size];
    for (int i = 0; i < size; ++i) {
        table[i] = nullptr;  // Initialize all buckets to nullptr
    }
}

// Destructor
HashTable::~HashTable() {
    for (int i = 0; i < size; ++i) {
        Node* current = table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;  // Free each node
        }
    }
    delete[] table;  // Free the table array
}

// Map a character to a telephone keypad number
int HashTable::charToKeypadNumber(char c) {
    if (c >= 'A' && c <= 'C') return 2;
    if (c >= 'D' && c <= 'F') return 3;
    if (c >= 'G' && c <= 'I') return 4;
    if (c >= 'J' && c <= 'L') return 5;
    if (c >= 'M' && c <= 'O') return 6;
    if (c >= 'P' && c <= 'S') return 7;
    if (c >= 'T' && c <= 'V') return 8;
    if (c >= 'W' && c <= 'Z') return 9;
    return 0;  // Invalid character (shouldn't reach here)
}

// Hash function
int HashTable::hashFunction(const string& initials) {
    int hash = 0;
    for (char c : initials) {
        hash = hash * 10 + charToKeypadNumber(c);  // Convert each char to a number
    }
    return hash % size;  // Map to table size using modulo
}

// Insert a value into the hash table
void HashTable::insert(const string& initials) {
    int hashValue = hashFunction(initials);
    Node* newNode = new Node(initials);
    newNode->next = table[hashValue];  // Insert at the beginning of the linked list
    table[hashValue] = newNode;
}

// Collect statistics and compare with Poisson distribution
void HashTable::collectStatistics(int numInitials) {
    map<int, int> bucketSizeCounts;  // Use map for ordered output
    int maxCollisions = 0;           // Track the maximum number of collisions

    // Calculate bucket sizes
    for (int i = 0; i < size; ++i) {
        int bucketSize = 0;
        Node* current = table[i];
        while (current) {
            ++bucketSize;
            current = current->next;
        }
        ++bucketSizeCounts[bucketSize];  // Increment count of buckets with this size
        maxCollisions = max(maxCollisions, bucketSize);  // Update max collisions
    }

    // Output statistics in order
    cout << "Hash Table Statistics:\n";
    for (const auto& pair : bucketSizeCounts) {
        cout << "Buckets with " << pair.first << " elements: " << pair.second << "\n";
    }
    cout << "Maximum collisions in a single bucket: " << maxCollisions << "\n";

    // Poisson distribution comparison
    double lambda = static_cast<double>(numInitials) / size;  // Expected average elements per bucket
    cout << "\nExpected distribution (Poisson approximation):\n";
    for (int i = 0; i <= maxCollisions; ++i) {
        double probability = exp(-lambda) * pow(lambda, i) / tgamma(i + 1);
        cout << "Buckets with " << i << " elements (expected): "
            << size * probability << "\n";
    }
}

