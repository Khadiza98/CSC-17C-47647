/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 14, 2024, 2:34 PM
 * Purpose:  This program create a table which Displays Permutation 
 *           and Combination Comparison.
 */
//System Libraries
#include <iostream> //Input/Output Library
#include <cmath>    // for log, exp
#include <iomanip>  // For logarithmic calculations
using namespace std;//STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
float logPnmWithRep(int, int);   // Permutation with replacement
float logPnmWithoutRep(int, int);// Permutation without replacement
float logComWithRep(int, int);   // Combination with replacement
float logComWithoutRep(int, int);// Combination without replacement
void compare(int, int, float &, float &, float &, float &);  // Function to compare and call other functions


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    // Declare variables here
    int nMin = 2, nMax = 26;
    float pWithR, pWithoutR, cWithR, cWithoutR;

    // Output the headers
    cout << "P      -> Permutation(Order Matters)" << endl;
    cout << "C      -> Combination(Order does not matter)" << endl;
    cout << "Rep    -> with replacement" << endl;
    cout << "no Rep -> no replacement" << endl;
    cout << "N      -> Number of total elements" << endl;
    cout << "M      -> Number of elements to take from the total" << endl<<endl;
    cout << "  N  M            P Rep       P no Rep            C Rep             "
            "C no Rep" << endl;
    cout << "                   N^M        N!/(N-M)!     (N+M-1)!/((N-1)!M!)"
            "   N!/((N-M)!M!)" << endl << endl;

    // Loop over all values of n from 2 to 26 and m from 0 to n
    for (int n = nMin; n <= nMax; n++) {
        for (int m = 0; m <= n; m++) {
            // Call compare function to calculate all values
            compare(n, m, pWithR, pWithoutR, cWithR, cWithoutR);

            // Output results
            cout << setw(3) << n << setw(3) << m 
                 << setw(15) << exp(pWithR)// Convert log back to normal value for output
                 << setw(15) << exp(pWithoutR)
                 << setw(18) << exp(cWithR)
                 << setw(18) << exp(cWithoutR)
                 << endl;
        } // End of inner loop
        cout << endl;
    } // End of outer loop
    
    // Exit the program
    return 0;
}

// Permutation with Replacement: log(N^M) = M*log(N)
float logPnmWithRep(int n, int m) {
    return m * log(n);
}

// Permutation without Replacement: log(N!/(N-M)!) = log(N!) - log((N-M)!)
float logPnmWithoutRep(int n, int m) {
    float logFactN = 0.0f, logFactNminusM = 0.0f;
    for (unsigned int i = 1; i <= n; ++i) logFactN += log(i);
    for (unsigned int i = 1; i <= (n - m); ++i) logFactNminusM += log(i);
    return logFactN - logFactNminusM;
}

// Combination with Replacement: log((N+M-1)!/((N-1)!M!))
float logComWithRep(int n, int m) {
    float logFactNplusMminus1 = 0.0f, logFactNminus1 = 0.0f, logFactM = 0.0f;
    for (unsigned int i = 1; i <= (n + m - 1); ++i) logFactNplusMminus1 += log(i);
    for (unsigned int i = 1; i <= (n - 1); ++i) logFactNminus1 += log(i);
    for (unsigned int i = 1; i <= m; ++i) logFactM += log(i);
    return logFactNplusMminus1 - logFactNminus1 - logFactM;
}

// Combination without Replacement: log(N!/((N-M)!M!))
float logComWithoutRep(int n, int m) {
    float logFactN = 0.0f, logFactNminusM = 0.0f, logFactM = 0.0f;
    for (unsigned int i = 1; i <= n; ++i) logFactN += log(i);
    for (unsigned int i = 1; i <= (n - m); ++i) logFactNminusM += log(i);
    for (unsigned int i = 1; i <= m; ++i) logFactM += log(i);
    return logFactN - logFactNminusM - logFactM;
}

// Compare function to call all calculation functions
void compare(int n, int m, float &prep, float &pnorep, float &crep, float &cnorep) {
    prep = logPnmWithRep(n, m);
    pnorep = logPnmWithoutRep(n, m);
    crep = logComWithRep(n, m);
    cnorep = logComWithoutRep(n, m);
}
