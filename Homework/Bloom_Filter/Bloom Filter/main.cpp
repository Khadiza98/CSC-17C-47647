/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 20, 2024, 12:46 AM
 * Purpose: Create own bloom filter in netbeans, just like the example.
            Randomly choose names/randomly create names and pass through 
 *          the filter.How does the Prob of false positives compare
 *          with the calculated.
 */
#include <iostream>   // Input/Output Library
#include <vector>     // For utilize vector
#include <string>     // For utilize string
#include <cstdlib>    // For random name generation
#include <ctime>      // For random seed
#include <cmath>      // For pow(), exp()
#include <algorithm>  // For find()
using namespace std; //STD Name-space where Library is compiled

//User Libraries
//Global Constants not Variables
//Function Prototypes
unsigned int hashFunc1(const string &);
unsigned int hashFunc2(const string &);
string randomName(int);


// Bloom filter class
class BloomFilter {
    private:
        vector<bool> bitSet; // Bit array
        int bitSize;         // Size of bit array

    public:
        // Constructor
        BloomFilter(int size) : bitSize(size), bitSet(size, false) {}

        // Insert name into Bloom filter
        void insert(const string &name) {
            unsigned int h1 = hashFunc1(name) % bitSize;
            unsigned int h2 = hashFunc2(name) % bitSize;
            bitSet[h1] = true;
            bitSet[h2] = true;
        }

        // Check if name might exist
        bool contains(const string &name) const {
            unsigned int h1 = hashFunc1(name) % bitSize;
            unsigned int h2 = hashFunc2(name) % bitSize;
            return bitSet[h1] && bitSet[h2];
        }
};

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0))); // Random seed
    //Declare variables here
    BloomFilter bf(100); // Bloom filter with 100 bits
    string testNames[] = {"David", "Adley", "Khadiza", "Akter"};
    
   
    // Insert specific names
    for (const string &name : testNames) {
        bf.insert(name);
    }
    // Check inserted and non-inserted names in the bloom filter
    cout << "Testing specific names:\n";
    for (const string &name : testNames) {
        cout << name << " is in the Bloom filter? "
             << (bf.contains(name) ? "Yes" : "No") << "\n";
    }
    string search1 = "Eve";
    cout << search1 << " is in the Bloom filter? "
         << (bf.contains(search1) ? "Yes" : "No") << "\n";
    string search2 = "Motin";
    cout << search2 << " is in the Bloom filter? "
         << (bf.contains(search2) ? "Yes" : "No") << "\n";

    // Randomized test for false positives
    int falsePosCount = 0;
    int testCount = 1000;
    for (int i = 0; i < testCount; ++i) {
        string randName = randomName(5); // Generate random name
        if (bf.contains(randName)) {
            // Check if it's not actually inserted
            if (find(begin(testNames), end(testNames), randName) == end(testNames)) {
                falsePosCount++;
            }
        }
    }

    // Compute false positive rate
    float falsePosRate = static_cast<float>(falsePosCount) / testCount;
    cout << "False positive rate: " << falsePosRate << "\n";

    // Compare with theoretical rate
    int m = 100; // Bit size
    int k = 2;   // Hash functions
    int n = 4;   // Inserted items
    float theoreticalRate = pow(1 - exp(-k * static_cast<float>(n) / m), k);
    cout << "Theoretical false positive rate: " << theoreticalRate << "\n";
    // Exit the program here!
    return 0;
}
// Simple hash function 1
unsigned int hashFunc1(const string &str) {
    unsigned int h = 0;
    for (char ch : str) {
        h = 31 * h + ch; // Multiplier
    }
    return h;
}

// Simple hash function 2
unsigned int hashFunc2(const string &str) {
    unsigned int h = 5381;
    for (char ch : str) {
        h = ((h << 5) + h) + ch; // Hash * 33 + char
    }
    return h;
}
// Generate random names
string randomName(int length) {
    string name;
    for (int i = 0; i < length; ++i) {
        char randChar = 'a' + (rand() % 26); // Random lowercase
        name += randChar;
    }
    return name;
}