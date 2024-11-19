/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 19, 2024, 11:16 AM
 * Purpose:Create 3 large arrays to search, where the size will be variable up
 *          until it reaches your machines limit.They should contain the same 
 *          information since going to compare 3 different algorithms. also 
 *          doing operational studies on them to determine their order.O(N), 
 *          O(log(N)), and O(1)? Search algorithms.Linear, Binary, Hash.......
 */

#include <iostream> //Input/Output Library
#include <string>
#include <algorithm>
#include <unordered_map>
#include <chrono>
#include <random>
using namespace std; //STD Name-space where Library is compiled

//User Libraries
#include "HashTable.h"
//Global Constants not Variables

//Function Prototypes
string generateRandomString();
bool linearSearch(string*, int, const string&);
bool binarySearch(string*, int, const string&);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Declare variable here!
    int size = 100000;      // Array sizes to test
    const int testCount = 1000; // Number of search operations (50-50 split)
    const double searchSplit = 0.5; // 50% targets exist, 50% do not

    // Print column headers for results
    // Step 1: Generate random data
    string* data = new string[size];
    for (int i = 0; i < size; ++i) {
        data[i] = generateRandomString(); // Fill array with random strings
    }

    // Step 2: Prepare test strings
    string* testStrings = new string[testCount];
    for (int i = 0; i < testCount * searchSplit; ++i) {
        testStrings[i] = data[i % size]; // Use strings from the data (existing targets)
    }
    for (int i = testCount * searchSplit; i < testCount; ++i) {
        testStrings[i] = generateRandomString(); // Generate new random strings (non-existing targets)
    }
    // Step 3: Perform Linear Search
    int start = time(0); // Start timer
    for (int i = 0; i < testCount; ++i) {
        linearSearch(data, size, testStrings[i]);
    }
    int end = time(0); // End timer
    int linearTime = end - start; // Compute duration
    cout << "Linear Search, Time (s) " << "," << linearTime << endl;
     
   // Step 4: Perform Binary Search (sort the array first)
    sort(data, data + size); // Sort array
    start = time(0); // Start timer
   for (int j = 0; j < 1000; j++) { // outer loop make it size 1000* 100000
        for (int i = 0; i < testCount; ++i) {
            binarySearch(data, size, testStrings[i]);
        }
   }
    end = time(0); // End timer
    int binaryTime = end - start; // Compute duration
    cout << "Binary Search, Time (s) " << "," << binaryTime << endl;

    // Step 5: Perform Hash Search (build hash table first)
    HashTable hashTable;
    for (int i = 0; i < size; ++i) {
        hashTable.insert(data[i]); // Insert data into hash table
    }
    start = time(0); // Start timer
    for (int j = 0; j < 1000; j++) {
        for (int i = 0; i < testCount; ++i) {
            hashTable.search(testStrings[i]);
        }
    }
    end = time(0); // End timer
    int hashTime = end - start; // Compute duration

    // Step 6: Print results for the current size
    cout << "HashTime Search, Time (s) " << "," << hashTime << endl;
    
    // Clean up dynamically allocated memory
    delete[] data;
    delete[] testStrings;
    return 0;
}


// Function to generate a random string of 20 characters
string generateRandomString() {
    const int length = 20; // String length
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABC"
    "DEFGHIJKLMNOPQRSTUVWXYZ"; // Allowed characters
    const int charsetSize = sizeof(charset) - 1;
    string result;

    static mt19937 rng(random_device{}()); // Random number generator
    std::uniform_int_distribution<> dist(0, charsetSize - 1);

    for (int i = 0; i < length; ++i) {
        result += charset[dist(rng)]; // Pick a random character
    }
    return result;
}
// Linear search: Check each element one by one
bool linearSearch(string* arr, int size, const string& target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target)
            return true; // Found the target
    }
    return false; // Target not found
}

// Binary search: Requires the array to be sorted
bool binarySearch(string* arr, int size, const string& target) {
    return binary_search(arr, arr + size, target); // Use C++ built-in binary search
}
