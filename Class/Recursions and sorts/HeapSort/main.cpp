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

// Function to heapify a subtree rooted at node i
void heapify(int arr[], int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);  // Swap root with largest child
        heapify(arr, n, largest);    // Recursively heapify the affected subtree
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array into a max-heap)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max-heapify on the reduced heap
        heapify(arr, i, 0);
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
   
    int st = time(0);
    for (int i = 0; i < 15000; i++) {
        heapSort(a, SIZE);
    }
    int end = time(0);
    cout << "total time sec: " << end - st;

   
    return 0;
}
