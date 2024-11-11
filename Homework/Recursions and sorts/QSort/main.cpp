/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 10, 2024, 9:38 PM
 * Purpose: Create a QSort
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function that chooses the pivot and organizes elements around it
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1;       // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {    // If current element is smaller than the pivot
            i++;                 // Increment index of the smaller element
            //swap(arr[i], arr[j]);
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //swap(arr[i + 1], arr[high]);
    int tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    return i + 1; // Return the partition point
}

// The main QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index

        quickSort(arr, low, pi - 1);  // Sort elements before partition
        quickSort(arr, pi + 1, high); // Sort elements after partition
    }
}

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare all Variables Here
    const int SIZE = 1000;
    int a[SIZE];
    //fill array
    for (int indx = 0; indx < SIZE; indx++) {
        a[indx] = rand();
    }
    /*cout << "Unsorted array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    */
    int st = time(0);
    for (int i = 0; i < 10000; i++) {
        quickSort(a, 0, SIZE - 1);
    }
    int end = time(0);
    cout << "time sec: " << end - st;
    /*cout << "Sorted array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    */
    return 0;
}


