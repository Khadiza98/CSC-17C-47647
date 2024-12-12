/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on December 08, 2024, 2:46 AM
 * Purpose: Take hyperbolic sin/cos recursive function, place the angle
 *          on a sine or cosine stack that represents a call to the sine or 
 *          cosine. When the program returns, examine the stack for how many 
 *          times the hyp sine was called and how many times hyp sine/cosine 
 *          was called vs. the value were trying to find. Put the results
 *          in a table. Range of values from -1 to 1 in .1 radian increments. 
 */
//System Libraries
#include <iostream>  // For input/output
#include <cmath>     // For math functions
#include <iomanip>   // For formatted output
using namespace std; // STD Name-space where Library is compiled

//Global Constants not Variables

//Function Prototypes
float h(float angR, int &hCallCount, int &gCallCount);
float g(float angR, int &hCallCount, int &gCallCount);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Declare variables here
    float startAng = -1.0f;   // Starting angle in radians
    float endAng = 1.001f;    // Ending angle in radians
    float step = 0.1f;        // Step size for angle increments

    cout << fixed << setprecision(1);

    // Print sinh(x) table header
    cout << "Table for sinh(x):\n";
    cout << setw(10) << "Angle"
         << setw(15) << "sinh(x)"
         << setw(15) << "h(x) Calls"
         << setw(15) << "g(x) Calls"
         << endl;

    // Generate sinh(x) table
    for (float angle = startAng; angle <= endAng; angle += step) {
        int hCallCount = 0, gCallCount = 0;
        // Calculate sinh(x) and count function calls
        float result = h(angle, hCallCount, gCallCount);
        // Print the results for the current angle
        cout << setw(10) << angle
             << setw(15) << sinh(angle)
             << setw(15) << hCallCount
             << setw(15) << gCallCount
             << endl;
    }

    // Print cosh(x) table header  
    cout << "\nTable for cosh(x):\n";
    cout << setw(10) << "Angle"
         << setw(15) << "cosh(x)"
         << setw(15) << "h(x) Calls"
         << setw(15) << "g(x) Calls"
         << endl;
    
    // Generate cosh(x) table
    for (float angle = startAng; angle <= endAng; angle += step) {
        int hCallCount = 0, gCallCount = 0;
        // Calculate cosh(x) and count function calls
        float result = g(angle, hCallCount, gCallCount);
        // Print the results for the current angle
        cout << setw(10) << angle
             << setw(15) << cosh(angle)
             << setw(15) << hCallCount
             << setw(15) << gCallCount
             << endl;
    }
    
    // Exit the program
    return 0;
}

//************************************************************
// Definition of h function. This calculates the hyperbolic
// sine of an angle using recursion.
// @param angR The input angle in radians.
// @param hCallCount Reference to the counter for calls to h().
// @param gCallCount Reference to the counter for calls to g().
// @return The computed value of sinh(angR).
//************************************************************
float h(float angR, int &hCallCount, int &gCallCount) {
    hCallCount++;  // Track h() calls
    float tol = 1e-6;
    if (angR > -tol && angR < tol) {
        return angR + angR * angR * angR / 6;
    }
    return 2 * h(angR / 2, hCallCount, gCallCount) *
           g(angR / 2, hCallCount, gCallCount);
}

//************************************************************
// Definition of g function. This calculates the hyperbolic
// cosine of an angle using recursion.
// @param angR The input angle in radians.
// @param hCallCount Reference to the counter for calls to h().
// @param gCallCount Reference to the counter for calls to g().
// @return The computed value of cosh(angR).
//************************************************************
float g(float angR, int &hCallCount, int &gCallCount) {
    gCallCount++;  // Track g() calls
    float tol = 1e-6;
    if (angR > -tol && angR < tol) {
        return 1 + angR * angR / 2;
    }
    float b = h(angR / 2, hCallCount, gCallCount);
    return 1 + 2 * b * b;
}
