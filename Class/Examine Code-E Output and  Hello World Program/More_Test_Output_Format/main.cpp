/* 
 * File: main.cpp
 * Author: Khadiza Akter
 * Date:  August 29, 2024, 11:48 AM
 * Purpose: In this program, utilizing the Input Output manipulators,
 *          to learn fundamental manipulators: like - fixed, setprecision,
 *          showpoint, setw(), and other formatting aspects in C++. Will be 
 *          given four integers as input. Output the numbers following
 *          the required Output format.
 * Version: A2
 */

//System Libraries - Post Here
#include <iostream>
//Library for our functions utilized in this question.
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    int aNum, bNum, cNum, dNum;
    
    //Initialize or input data here
    cin >> aNum;
    cin >> bNum;
    cin >> cNum;
    cin >> dNum;
    
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    
    //Set up output format and display outputs here
    cout << fixed << showpoint;
    cout << setw(9) << aNum << setw(10) << setprecision(1) << static_cast<double> (aNum)  
         << setw(10) << setprecision(2) << static_cast<double>(aNum) << endl;
    cout << setw(9) << bNum << setw(10) << setprecision(1) << static_cast<double> (bNum)  
         << setw(10) << setprecision(2) << static_cast<double>(bNum) << endl;
    cout << setw(9) << cNum << setw(10) << setprecision(1) << static_cast<double> (cNum)  
         << setw(10) << setprecision(2) << static_cast<double>(cNum) << endl;
    cout << setw(9) << dNum << setw(10) << setprecision(1) << static_cast<double> (dNum)  
         << setw(10) << setprecision(2) << static_cast<double>(dNum);
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}
