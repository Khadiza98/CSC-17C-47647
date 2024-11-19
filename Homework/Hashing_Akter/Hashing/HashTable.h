/* 
 * File:   HashTable.h
 * Author: Khadiza Akter
 * Created on November 19, 2024, 11:28 AM
 * Purpose: Specification of HashTable class
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

// Hash table implementation with chaining for collision resolution
class HashTable {
public:
    // Insert a string into the hash table
    void insert(const string& key) {
        int hashValue = hashFunction(key); // Compute hash value
        table[hashValue].push_back(key);  // Add to the corresponding list
    }

    // Search for a string in the hash table
    bool search(const string& key) {
        int hashValue = hashFunction(key); // Compute hash value
        for (const auto& str : table[hashValue]) { // Check the linked list
            if (str == key)
                return true; // Found the target
        }
        return false; // Target not found
    }

private:
    static const int TABLE_SIZE = 10007; // Hash table size (prime number)
    vector<vector<string>> table = vector<vector<string>>(TABLE_SIZE);

    // Simple hash function: Combine characters into a hash value
    int hashFunction(const string& key) {
        int hashValue = 0;
        for (char ch : key) {
            hashValue = (hashValue * 31 + ch) % TABLE_SIZE; // Compute hash value
        }
        return hashValue;
    }
};

#endif /* HASHTABLE_H */

