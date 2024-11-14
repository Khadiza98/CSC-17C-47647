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
int Ob, Oi, Pos;
//Function Prototypes Here
void prntAry(const int[], int, int);
void fillAry(int[], int, int, int);
int  binSrch(int a[], int n, int val);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare all Variables Here
    const int SIZE = 100000;
    int array[SIZE];
    int lowRng = 100, highRng = 200;
    int perLine = 10;

    //Finish initializing the rest of the array
    fillAry(array, SIZE, highRng, lowRng);
    //Print the values in the array
    //prntAry(array, SIZE, perLine);
    int value = rand() % (highRng - lowRng + 1) + lowRng;
    int startTime = time(0);
    cout << startTime << endl;
    for (int k = 0; k < 45000000; k++) {
        int i = binSrch(array, SIZE, value);
        //cout << i << endl << "  "<<value ;
    }
    int endTime = time(0);
    cout << endTime << endl;
    cout << "Time in integer: " << endTime - startTime;

}
void fillAry(int a[], int n, int hr, int lr) {
    for (int indx = 0; indx < n; indx++) {
        a[indx] = rand();
    }
}
void prntAry(const int a[], int n, int perLine) {
    //Print the values in the array
    cout << endl << "The Array Values" << endl;
    for (int indx = 0; indx < n; indx++) {
        cout << a[indx] << " ";
        if (indx % perLine == (perLine - 1))cout << endl;
    }
    cout << endl;
}

int  binSrch(int a[], int n, int val) {
    //Initialize end points which are indexes
    int lowEnd = 0;
    int highEnd = n - 1;

    //Loop until value found not indexes
    do {
        int middle = (highEnd + lowEnd) / 2;
        if (val == a[middle])return middle;
        else if (val > a[middle])lowEnd = middle + 1;
        else highEnd = middle - 1;
    } while (lowEnd <= highEnd);

    //Not found
    return -1;
}
