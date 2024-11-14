/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 10, 2024, 12:46 AM
 * Purpose: Recursive function. Provide code and test sufficiently.
            Let g(2x) = 2g( x) / 1+g^2( x), −1≤x≤1, x∈R , ∂ x=0.1f
            with base conditions of ∣x∣<tol ,tol<106, g(x) = x−x^3 /6
 */

//System Libraries
#include <iostream>   // Input/Output Library
#include <cmath>      // For math functions like abs and pow
#include <iomanip>    // For output formatting
using namespace std;  // STD Name-space where Library is compiled

//User Libraries
//Global Constants not Variables
const float tol = 1e-6f; // Define tolerance

//Function Prototypes
float g(float);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Declare variables here
    float deltaX = 0.1f; // Step size for x
    float x = -1.0f;     // Start value for x
    
    // Set up output formatting for four decimal places
    cout << fixed << setprecision(6);
    
    // Test g(x) for values from -1 to 1 with increments of 0.1
    cout << "Testing g(x) from -1 to 1 with step of 0.1:" << endl;
    for (x = -1.0f; x <= 1.0f + deltaX / 2; x += deltaX) {
        cout << "g(" << x << ") = " << g(x) << endl;
    }
    //Exit the program here!
    return 0;
}

/**
 * Recursive function to compute g(x) based on the formula:
 * g(2x) = 2 * g(x) / (1 + g(x)^2)
 * with base case: g(x) = x - x^3 / 6 for |x| < tol
 * @param x Input value for function g
 * @return Result of g(x) calculation
 */
float g(float x) {
    // Base case: if |x| < tol, use 
    // approximation formula g(x) = x - x^3 / 6
    if (fabs(x) < tol) {
        return x - (pow(x, 3) / 6.0f);
    }
    
    // Recursive case: calculate g(x) using g(2x) formula
    float halfG = g(x / 2.0f);  // Recursive call for g(x / 2)
    return (2.0f * halfG) / (1.0f + pow(halfG, 2));  // Apply formula
}