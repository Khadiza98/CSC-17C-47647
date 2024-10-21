/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 19, 2024, 12:09 PM
 * Purpose: Permutation of an assigned string with rotate function example
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <algorithm> // Needed for rotate()
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
//Function Prototypes
void permute(string, string); // permute function prototype here

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    //Declare variables here
    string str = "ABCD";
    permute(str, "");
    
    // Exit the program
    return 0;
}

//*****************************************************
// This function will print permutation of string str  
// using recursive approach and rotate function.
// out is used to store permutation one by one
//*****************************************************
void permute(string str, string out) {
    if (str.length() == 0) {
        cout << out << endl;
        return;
    }
    // move all characters one by one at the beginning of out
    for (int i= 0; i < str.length(); i++) {
        // remove first character from str and add to out.
        permute(str.substr(1), out+str[0]); 
        // rotate string in a way that second character move 
        // to the beginning
        rotate(str.begin(), str.begin()+1, str.end());
    }
}