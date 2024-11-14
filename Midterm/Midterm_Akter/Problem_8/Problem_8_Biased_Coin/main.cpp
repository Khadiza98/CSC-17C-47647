/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 12, 2024, 12:46 AM
 * Purpose: Given a biased coin analogy, if a bit vector is 40% full, 
 *          what are the odds that 5 bits randomly chosen all fall within 
 *          the filled section. Simulate the results and compare to calculations.
 */
//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   // For rand()
#include <ctime>     // For time()
#include <iomanip>   // Output formatting
using namespace std; //STD Name-space where Library is compiled

//Function Prototypes
void calcProb();

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    // Run probability calculation
    calcProb();  
    
    // Exit the program here
    return 0;
}

//******************************************************************************
// calcProb - Simulates random trials to calculate the probability that
// five randomly chosen bits fall within the first 40% of a 100-element range.
// Generates 1,000,000 sets of five random numbers from 1 to 100.
// Counts the number of times all five numbers are <= 40.
// Calculates probability as the ratio of successful trials to total trials.
//******************************************************************************
void calcProb() {
    int hits = 0;               // Successful outcomes count
    float prob = 0.0f;          // Calculated probability
    const int tries = 1000000;  // Total trials
    const int limit = 40;       // Threshold for "40% area"

    for (int i = 0; i < tries; ++i) {
        // Generate 5 random numbers from 1 to 100
        int r1 = rand() % 100 + 1;
        int r2 = rand() % 100 + 1;
        int r3 = rand() % 100 + 1;
        int r4 = rand() % 100 + 1;
        int r5 = rand() % 100 + 1;

        // Check if all are within the limit (<= 40)
        if (r1 <= limit && r2 <= limit && r3 <= limit && r4 <= limit &&
            r5 <= limit) {
            hits++;  // Count successful trial
        }
    }

    // Calculate probability by dividing hits by tries
    prob = static_cast<float>(hits) / tries;

    // Display result
    cout << fixed << setprecision(5);
    cout << "Simulated result: Probability of all five bits in 40% area:  "
         << prob << endl;
    cout << "Calculated result: Probability of all five bits in 40% area: "
            "0.01024"<< endl;
}