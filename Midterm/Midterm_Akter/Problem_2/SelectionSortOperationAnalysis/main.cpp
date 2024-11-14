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
int Ob, Opos, Oi, Pos;

//Function Prototypes Here
void fillAry(int[], int);
void selSort(int[], int);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare all Variables Here
    const int SIZE = 500;
    int array[SIZE], brray[SIZE];
    //Finish initializing the rest of the array
    fillAry(array, SIZE);
    selSort(array, SIZE);
    cout << "Ob=" << Ob << endl;
    cout << "Od=" << Opos << endl;
    cout << "Oi=" << Oi << endl;
    cout << "Pos=" << Pos << endl;
    cout << "tot=" << Ob + Opos + Oi + Pos << endl;
}
void selSort(int a[], int n) {
    //Loop and declare variables
    int indx, min;
    Ob += 2;
    for (int pos = 0; pos < n - 1; pos++) {
        Opos += 13;
        //Find the smallest in the list, swap after finding
        min = a[pos]; indx = pos;
        for (int i = pos + 1; i < n; i++) {
            Oi += 4;
            if (a[i] < min) {
                Pos += 3;
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