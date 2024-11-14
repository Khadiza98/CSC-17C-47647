/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 5, 2024, 11:56 PM
 * Purpose: Create 2 types of recursive Power functions
 */
//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //Formatting
#include <cmath>     //pow()
#include <cassert>   // For assertions in testing
using namespace std; //STD Name-space where Library is compiled

//Function Prototypes
float powLinear(float, int); //Linear Recursive Power Function - O(n)
float powLog(float, int);    //Logarithmic Recursive Power Function - O(log n)

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Declare variables here
    float x = 2.0f;  // Base number
    int n = 10;      // Exponent
    
    //Compare recursive power function with built in power
    //function and display the results
    cout << "Standard Pow(" << x << "," << n
            << ")              = " << pow(x,n) << endl;
    cout << "Linear Recursive Pow(" << x << "," << n << ")      = " 
         << powLinear(x, n) << endl;
    cout << "Logarithmic Recursive Pow(" << x << "," << n << ") = " 
         << powLog(x, n) << endl;
    
    // Test cases to verify both functions
    float baseVal[] = {2.0f, -2.0f, 1.5f, 0.5f, -0.5f};  // Different bases
    int expVal[] = {0, 1, 2, 3, 4, 5, 10, 20};           // Range of exponents

    cout << "\n*****Testing power functions******" << endl;
    for (float x : baseVal) {
        for (int n : expVal) {
            float resultLinear = powLinear(x, n);
            float resultLogarithmic = powLog(x, n);
            
            // Display results
            cout << "x = " << x << ", n = " << n << endl;
            cout << "Linear Power Function:      " << resultLinear << endl;
            cout << "Logarithmic Power Function: " << resultLogarithmic << endl;

            // Verify results with the standard pow function
            float expected = pow(x, n);
            assert(abs(resultLinear - expected) < 1e-4);  // Ensuring precision
            assert(abs(resultLogarithmic - expected) < 1e-4);
        }
    }
    
    cout << "All test cases passed successfully!" << endl;
    
    // Exit the program
    return 0;
}

//*************************************************************
// Definition of O(n) recursive power function
// Multiplies x by itself n times in a linear recursive manner
//*************************************************************
float powLinear(float x, int n) {
    // Base Case
    if (n <= 0) return 1;
    // Recursive Case
    return x * powLinear(x, n - 1);
}

//********************************************************************
// Definition of O(log n) recursive power function using 
// exponentiation by squaring Splits the power into 
// even and odd cases to reduce recursive calls
//********************************************************************
float powLog(float x, int n) {
    // Base Case
    if (n == 0) return 1;
    // Recursive cases
    if (n % 2 == 0) { // If n is even
        float halfPower = powLog(x, n / 2);
        return halfPower * halfPower;
        
    } else { // If n is odd
        float halfPower = powLog(x, n / 2);
        return x * halfPower * halfPower;
    }
    
}

