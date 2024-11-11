/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 10, 2024, 9:38 PM
 * Purpose: Create a ShellSort
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Shell Sort function
void shellSort(int arr[], int n) {
    // Start with a large gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform a gapped insertion sort for this gap size
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            // Shift elements of arr[0..i-gap] that are greater than temp
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            // Place temp at its correct location
            arr[j] = temp;
        }
    }
}

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare all Variables Here
    const int SIZE = 5000;
    int a[SIZE];
    //fill array
    for (int indx = 0; indx < SIZE; indx++) {
        a[indx] = rand();
    }


    int st=time(0);
    for (int i = 0; i < 100000; i++) {
        shellSort(a, SIZE);
    }
    int end=time(0);
    cout << "time in sec: " << end - st;
        return 0;
}
