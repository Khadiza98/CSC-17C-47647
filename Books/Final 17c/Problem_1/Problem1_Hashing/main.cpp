/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on December 05, 2024, 12:46 AM
 * Purpose: We would like to use initials to locate an individual. For instance,
 *  MEL - 635 should locate the person Mark E. Lehr. Note: this is all upper case.
 *  Generate a hash function for the above using the numbers on your telephone.
 *  You know, each letter has a number associated with it, so examine your 
 *  telephone keypad. Generate 512 random 3 letter initials and take statistics 
 *  on a linked list array size 512 to hold this information. Report how many 
 *  have no elements, 1 element, 2 elements, etc... Also, what is the maximum
 *  number of collisions. Do both results agree with the hashing statistics
 *  distribution? Show the comparison and analysis?
 */
//System Libraries
#include <iostream>  // For input/output
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time() seeding
using namespace std;//STD Name-space where Library is compiled

//User Libraries
#include "HashTable.h"

// Function prototype
string genRandInit();

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    const int TABLE_SIZE = 512;  // Size of the hash table
    const int NUM_INITIALS = 512;  // Number of initials to generate

    // Create the hash table
    HashTable obj(TABLE_SIZE);

    // Generate and insert random initials into the hash table
    for (int i = 0; i < NUM_INITIALS; ++i) {
        string initials = genRandInit();
        obj.insert(initials);
    }

    // Collect and display statistics
    obj.collectStatistics(NUM_INITIALS);

    // Exit the program
    return 0;
}

//***********************************************************
// Definition of genRandInit function. This 
// generate random initials (3 uppercase letters)
// Input -> none; 
// Output -> return randomly generated initials
//***********************************************************
string genRandInit() {
    string initials;
    for (int i = 0; i < 3; ++i) {
        initials += 'A' + rand() % 26;  // Random uppercase letter
    }
    return initials;
}