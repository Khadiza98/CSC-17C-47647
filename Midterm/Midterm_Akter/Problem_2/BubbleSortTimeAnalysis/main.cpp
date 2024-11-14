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
void bublSrt(int[], int);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare all Variables Here
    const int SIZE =120000;
    int array[SIZE], brray[SIZE];
    //Finish initializing the rest of the array
    fillAry(array, SIZE);
    int startTime = time(0);
    cout << startTime << endl;
    bublSrt(array, SIZE);
    int endTime = time(0);
    cout << endTime << endl;
    cout << "Time in integer: " << endTime - startTime;
}
void bublSrt(int a[], int n) {
    //Keep looping and comparing until no swaps are left
    bool swap;
    do {
        swap = false;
        //Check the list and Swap when necessary
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);
}
void fillAry(int a[], int n) {
    for (int indx = 0; indx < n; indx++) {
        a[indx] = rand();
    }
}