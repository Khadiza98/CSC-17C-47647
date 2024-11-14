/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 12, 2024, 12:46 AM
 * Purpose: Mutual Recursive functions. Let C (2x) = 1/ 2C (x )S ( x) ∩ S(2x) =
            C 2( x)S 2( x)C2 (x )−S2 (x ), ∣x∣≤atan (1), x∈R , ∂ x=0.1f
            with base conditions of ∣x∣<tol , tol<106, 
            C ( x)=1/ x+x/ 6, S ( x)=1+x2 /2
 */
//System Libraries
#include <iostream>   //Input/Output Library
#include <cmath>
#include <iomanip>
#include <cassert>    // For assertions in testing
using namespace std;  //STD Name-space where Library is compiled
//User Libraries

//Global Constants not Variables
const float tol = 1e-6f;  // Tolerance for base conditions

//Function Prototypes
float C(float x);
float S(float x);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    float deltaX = 0.1f;
    float x = -atan(1);  // Start at -π/4

    cout << fixed << setprecision(4);
    cout << "Testing C(x) and S(x) from -π/4 to π/4 with step of 0.1:" << endl;
    
    // Test C(x) and S(x) from -atan(1) to atan(1) in increments of 0.1
    for (x = -atan(1); x <= atan(1) + deltaX / 2; x += deltaX) {
        cout << "C(" << x << ") = " << C(x) << ", S(" << x << ") = " << S(x) << endl;

       // Verify the base cases when |x| < tol by comparing to expected values
        if (fabs(x) < tol) {
            float expectedC = 1.0f / x + x / 6.0f;
            float expectedS = 1.0f + (x * x) / 2.0f;
            assert(fabs(C(x) - expectedC) < 1e-4);
            assert(fabs(S(x) - expectedS) < 1e-4);
        }
    }
    
    cout << "All test cases passed successfully!" << endl;
    return 0;
}

//*******************************************************
// Recursive function to compute C(x)
// @param x Value for which C(x) is computed
// @return Computed value of C(x)
//*******************************************************
float C(float x) {
    // Base condition: when |x| < tol, use direct formula
    if (fabs(x) < tol) {
        return 1.0f / x + x / 6.0f;
    }
    // Recursive relation for C(2x)
    return 0.5f * C(x / 2.0f) * S(x / 2.0f);
}

//*******************************************************
// Recursive function to compute S(x)
// @param x Value for which S(x) is computed
// @return Computed value of S(x)
//*******************************************************
float S(float x) {
    // Base condition: when |x| < tol, use direct formula
    if (fabs(x) < tol) {
        return 1.0f + (x * x) / 2.0f;
    }
    // Recursive relation for S(2x)
    float Cx = C(x / 2.0f);
    float Sx = S(x / 2.0f);
    return (Cx * Cx * Sx * Sx) / (Cx * Cx - Sx * Sx);
}