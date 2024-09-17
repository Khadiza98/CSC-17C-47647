/* 
 * File: main.cpp
 * Author: Khadiza Akter
 * Created on August 23, 2024, 4:12 PM
 * Purpose: A program that perform the summation of the series using a for-loop,
            then solve using the formula that derived from the summation series.
            Develop and display 2 approaches and compare.
 */

// System level libraries
#include <iostream> // input-output library

using namespace std;

// Execution starts from here!
int main(int argc, char** argv) {
    // Declare variables
    int c,              // To hold the constant input
        m,              // To hold the starting index input
        n,              // To hold the ending input value  
        sumByForLoop,   // To hold the result of sum using for loop 
        sumByFormula,   // To hold the result of sum using derived formula
        count;          // Counter variable
    // Ask for the C, m, and n input values
    cout << "Enter the value of constant C: ";
    cin >> c; 
    cout << "Enter the value of starting index m: ";
    cin >> m;
    cout << "Enter the value of ending index n: ";
    cin >> n;
    // input validation check
    do {    
        if (n < m) {
            cout << "Please enter the value of n is greater than or equal to m";
            cout << " to work derived formula: "; 
            cin >> n;
        }
    } while (m > n);
    
    
    // Solution 1: Sum the series using a for-loop
    for (count = m; count <= n; count++) {
        sumByForLoop += c;
    } // End of for loop
    
    // Solution 2: Sum the series using derived formula
    sumByFormula = c * (n - m + 1);
    
    // Display the result of solution 1 and 2
    cout << "Sum of series by for-loop: " << sumByForLoop  << endl;
    cout << "Sum of series by derived formula: " << sumByFormula  << endl;

    // Compare two solutions
    if (sumByForLoop == sumByFormula) {
        cout << "Both approaches give the same result." << endl;
    } else {
        cout << "Each approach gives different result" << endl;
    }
    
    //Exit the program
    return 0;
}


