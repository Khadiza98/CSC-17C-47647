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
int Ob, Od, Oi, Pos;

//Function Prototypes Here
void fillAry(int[], int);
void bublSrt(int[], int);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare all Variables Here
    const int SIZE = 400;
    int array[SIZE], brray[SIZE];
    //Finish initializing the rest of the array
    fillAry(array, SIZE);
    bublSrt(array, SIZE);
    cout << "Ob=" << Ob << endl;
    cout << "Od=" << Od << endl;
    cout << "Oi=" << Oi << endl;
    cout << "Pos=" << Pos << endl;
    cout << "tot=" << Ob + Od + Oi + Pos << endl;
}
void bublSrt(int a[], int n) {
    //Keep looping and comparing until no swaps are left
    bool swap;
    Ob++;
    do {
        Od += 3;
        swap = false;
        //Check the list and Swap when necessary
        for (int i = 0; i < n - 1; i++) {
            Oi += 6;
            if (a[i] > a[i + 1]) {
                Pos += 8;
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