
/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 6, 2024, 11:34 AM
 * Purpose: Practicing on next_permutation(), prev_permutaion(), sort()
 *          reverse() with list
 */
//System Libraries
#include <iostream>   //Input/Output Library
#include <list>       //For list container
#include <algorithm>  //Needed for next_permutation(), prev_permutaion()
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void nextPermutaion(list<int>&);
void prevPermutaion(list<int>&);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {    
    //Declare variables here
    list<int> mylist = {21,22,3,4};
    
    mylist.sort();   // Sort the array in ascending order
    nextPermutaion(mylist); // Call nextPermutaion function

    mylist.reverse();// Sort the array in descending order
    prevPermutaion(mylist); // call prevPermutaion function

    // Exit the program
    return 0;
    
}
void nextPermutaion(list<int>& myList) {
    cout << "The 4! possible next permutations with 4 elements:" << endl;
    int i = 1;
    do {
        for (int elem : myList) {
            cout << elem << " ";
        }
        cout << endl;
        
        i++;
        // Permutation stop until array is in descending order. if while condition is false 
        // at first time iteration, leave array in ascending regardless.
    } while (next_permutation(myList.begin(), myList.end()));
    cout << "After completing next_permutations, the list is: ";
    for (int elem : myList) {
        cout << elem << " ";
    }
    cout << endl;
}

void prevPermutaion(list<int>& myList) {
    cout << "\nThe 4! possible previous permutations with 4 elements:" << endl;
    int i = 1;
    do {
        for (int elem : myList) {
            cout << elem << " ";
        }
        cout << endl;
        i++;
     // Permutation stop until array is in ascending order. if while condition is false 
     // at first time iteration, leave array in descending regardless.
    } while (prev_permutation(myList.begin(), myList.end())); // Use list iterators
    cout << "After completing prev_permutations, the list is: ";
    for (int elem : myList) {
        cout << elem << " ";
    }
    cout << endl;
}