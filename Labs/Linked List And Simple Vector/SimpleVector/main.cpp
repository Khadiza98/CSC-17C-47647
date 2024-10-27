/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 22, 2024, 5:04 PM
 * Purpose:  To Test and Modify the Simple Vector to 2x or 1/4x when hitting
 *           the array size limit. Also, instead of using an Array in 
 *           SimpleVector, use the Linked List.
 */

//System Libraries
#include <iostream>
#include <cstdlib> // Needed for rand()
using namespace std;

//User Libraries
#include "SimpleVector.h"

//Global Constants

//Function prototypes
void fillVec(SimpleVector<char> &);  // Fills the vector with random characters
void prntVec(SimpleVector<char> &, int); // Prints the vector in rows

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char size = 100;  // Initial size of the vector
    SimpleVector<char> sv(size);  // Create a SimpleVector of chars with initial size

    //Fill the Vector with random uppercase letters
    fillVec(sv);
    cout << "Printing the elements of Vector......\n";
    //Print the Vector, 10 characters per line
    prntVec(sv, 10);
    
    cout << "Coping and Printing the elements of Vector......\n";
    //Copy the Vector
    SimpleVector<char> copysv(sv);
    //Print the Vector
    prntVec(copysv,10);

    //Test dynamic resizing by adding more elements
    cout << "Adding more elements to test resizing..." << endl;
    for (int i = 0; i < 20; i++) {  // Add 20 more elements
        sv.push_back(rand() % 26 + 65);  // Random uppercase letters
    }

    //Print the Vector again after adding new elements
    prntVec(sv, 10);

    //Test removing elements to trigger shrinking
    cout << "Removing elements to test shrinking..." << endl;
    for (int i = 0; i < 15; i++) {  // Remove 15 elements
        sv.pop_back();
    }

    //Print the Vector again after removing elements
    prntVec(sv, 10);

    return 0;
}

//*********************************************************
// Function to print the vector elements, "perLine"       *
// elements per line                                      *
//*********************************************************
void prntVec(SimpleVector<char> &sv, int perLine) {
    cout << endl;
    for (int i = 0; i < sv.size(); i++) {
        cout << sv[i] << " ";  // Access each element using the overloaded [] operator
        if (i % perLine == (perLine - 1)) cout << endl;  // New line after "perLine" elements
    }
    cout << endl;
}

//************************************************************
// Function to fill the SimpleVector with random uppercase   *
// letters.                                                  *
//************************************************************
void fillVec(SimpleVector<char> &sv) {
    for (int i = 0; i < sv.size(); i++) {
        sv[i] = rand() % 26 + 65;  // Random uppercase letter (ASCII A=65 to Z=90)
    }
}
