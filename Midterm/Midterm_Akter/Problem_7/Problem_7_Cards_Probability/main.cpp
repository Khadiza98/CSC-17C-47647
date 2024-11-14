/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 12, 2024, 12:46 AM
 * Purpose: Given 4 cards with 13 possible face values, calculate the 
 *          probability of 1 pair, 2 pair, 3 of a kind and 4 of a kind.
 *          Simulate the results and compare to calculations.
 */
//System Libraries
#include <iostream>     // For input/output 
#include <vector>       // For using vectors
#include <map>          // For using maps
#include <algorithm>    // For using random_shuffle
#include <cstdlib>      // For random number functions
#include <ctime>        // For time functions
#include <iomanip>      // For output formatting

using namespace std;    //STD Name-space where Library is compiled

// Function prototype
string analyzeHand(const vector<int>&);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    // Set random number seed using current time
    srand(static_cast<unsigned int>(time(0)));  

    // Declare variable and constant
    const int numSuits = 4, numRanks = 13, nSimulate = 1000000; 
    vector<int> deck;  // Vector to represent the deck
    int onePair = 0, twoPair = 0,
        threeOfKind = 0, fourOfKind = 0; // Variables to count each type of hand


    // Initialize deck with 52 cards (4 suits x 13 ranks)
    for (int rank = 0; rank < numRanks; ++rank) {
        for (int suit = 0; suit < numSuits; ++suit) {
            deck.push_back(rank);  // Add card rank to deck
        }
    }
    
    // Simulate drawing 4 cards and classifying hands
    for (int i = 0; i < nSimulate; ++i) {
        random_shuffle(deck.begin(), deck.end());  // Shuffle the deck

        // Draw the first 4 cards from the shuffled deck
        vector<int> hand(deck.begin(), deck.begin() + 4);

        // Classify the hand
        string handType = analyzeHand(hand);

        // Increment counters based on the hand type
        if (handType == "One Pair") onePair++;
        else if (handType == "Two Pair") twoPair++;
        else if (handType == "Three of a Kind") threeOfKind++;
        else if (handType == "Four of a Kind") fourOfKind++;
    }

    // Display the simulated probabilities
    cout << fixed << setprecision(6);  // Set decimal precision for output
    cout << "Simulated Probability Results (based on "<<nSimulate<<" draws):\n";
    cout << "One Pair: ≈ " << static_cast<float>(onePair) / nSimulate << endl;
    cout << "Two Pair: ≈ " << static_cast<float>(twoPair) / nSimulate << endl;
    cout << "Three of a Kind: ≈ " << static_cast<float>(threeOfKind) /
            nSimulate << endl;
    cout << "Four of a Kind: ≈ " << static_cast<float>(fourOfKind) / 
            nSimulate << endl;

    // Display calculated probabilities for comparison
    cout << "\nCalculated Probability Results:" << endl;
    cout << "One Pair: ≈ 0.304249" << endl;
    cout << "Two Pairs: ≈ 0.010372" << endl;
    cout << "Three of a Kind: ≈ 0.009219" << endl;
    cout << "Four of a Kind: ≈ 0.000048" << endl;

    return 0;  // End of the program
}

// Function to simulate drawing 4 cards and classify the hand
string analyzeHand(const vector<int>& hand) {
    map<int, int> rCount;  // Map to count occurrences of each card rank
    for (int rank : hand) {   // Iterate over the hand
        rCount[rank]++;     // Count each rank's occurrences
    }

    bool pair = false, twoPair = false, 
        threeOfKind = false, fourOfKind = false;  // Flags for hand types
    int pairs = 0;  // Counter for pairs

    // Check for four of a kind, three of a kind, and pairs
    for (const auto& entry : rCount) {
        if (entry.second == 4) fourOfKind = true;   // Four of a kind
        if (entry.second == 3) threeOfKind = true;  // Three of a kind
        if (entry.second == 2) pairs++;             // Count pairs
    }

    // Classify the hand based on the number of pairs
    if (pairs == 2) twoPair = true;
    else if (pairs == 1) pair = true;

    // Return the classification of the hand
    if (fourOfKind) return "Four of a Kind";
    if (threeOfKind) return "Three of a Kind";
    if (twoPair) return "Two Pair";
    if (pair) return "One Pair";

    return "Other";  // No special hand
}
