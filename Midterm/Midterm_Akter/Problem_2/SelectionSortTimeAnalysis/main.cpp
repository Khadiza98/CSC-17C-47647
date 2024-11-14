/*
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Common searching and sorting algorithms
 */

 //System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void fillAry(int[], int);
void selSort(int[], int);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare all Variables Here
    const int SIZE = 150000;
    int array[SIZE];
    //Finish initializing the rest of the array
    fillAry(array, SIZE);
    int startTime = time(0);
    cout << startTime << endl;
    selSort(array, SIZE);
    int endTime = time(0);
    cout << endTime << endl;
    cout << "Time in integer: " << endTime - startTime;
}
void selSort(int a[], int n) {
    //Loop and declare variables
    int indx, min;
    for (int pos = 0; pos < n - 1; pos++) {
        //Find the smallest in the list, swap after finding
        min = a[pos]; indx = pos;
        for (int i = pos + 1; i < n; i++) {
            if (a[i] < min) {
                min = a[i];
                indx = i;
            }
        }
        //Perform the swap
        a[indx] = a[pos];
        a[pos] = min;
    }
}
void fillAry(int a[], int n) {
    for (int indx = 0; indx < n; indx++) {
        a[indx] = rand();
    }
}