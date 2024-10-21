/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 17, 2024, 10:15 PM
 * Purpose:  Summing, Finding the Max and Min of an integer list using STL
 *           containers and algorithms like sort, min, max, and accumulate.
 */

#include <iostream>    // Input-output library
#include <list>        // Needed for list container
#include <algorithm>   // for  min, max, accumulate
#include <numeric>     // for accumulate (to calculate sum)
#include <iterator>    // for advance
using namespace std;

//User Libraries Here
//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(list<int>&, int);
int  stat(const list<int>&, int&, int&);
void print(const list<int>&, int, int, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    // Declare Variables
    list<int> intList;  // Using list to hold the integers
    int sizeIn, sum, minVal, maxVal;

    // Input the size of the list you are sorting
    cout << "Read in a list of integers and find sum, min, max." << endl;
    cout << "Input the list size (<= 20): ";
    cin >> sizeIn;

    // Read in the list of integers
    cout << "Now read the List:" << endl;
    read(intList, sizeIn); // Populate the list

    // Find the sum, max, and min
    sum = stat(intList, maxVal, minVal); // Perform statistical analysis

    // Print the results
    print(intList, sum, maxVal, minVal); // Display the results

    return 0;
}

//***************************************************************
// Definition of read function. This function reads in the list of
// integers from the user.
//***************************************************************
void read(list<int>& intList, int sizeIn) {
    for (int i = 0; i < sizeIn; i++) {
        int value;
        cin >> value;
        intList.push_back(value);  // Add values to the list
    }
}

//***************************************************************
// Definition of stat function. This function finds the sum, max, 
// and min value of the list. It returns the sum of the elements.
//***************************************************************
int stat(const list<int>& intList, int& maxVal, int& minVal) {
    // Find max and min using STL algorithms
    maxVal = *max_element(intList.begin(), intList.end());
    minVal = *min_element(intList.begin(), intList.end());

    // Calculate sum using accumulate algorithm
    int sum = accumulate(intList.begin(), intList.end(), 0);
    
    return sum;
}

//***************************************************************
// Definition of print function. This function prints the list, sum, 
// max, and min values using iterator.
//***************************************************************
void print(const list<int>& intList, int sum, int maxVal, int minVal) {
    int index = 0;
    // Using an iterator to traverse through the list
    list<int>::const_iterator it;
    for (it = intList.begin(); it != intList.end(); it++) {
        cout << "a[" << index++ << "] = " << *it << endl;
    }
    cout << "\nMin  = " << minVal << endl;
    cout << "Max  = " << maxVal << endl;
    cout << "Sum  = " << sum << endl;
}
