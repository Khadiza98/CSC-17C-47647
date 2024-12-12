#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Data structure containing an array and a working array
struct Data {
    int size;
    short* sortit;
    short* working;
};

// Function Prototypes
Data* fill(int);               // Fill the array
void print(Data*, int);        // Print the array
void merge(Data*, int, int, int); // Merge two arrays
void mrgSort(Data*, int, int); // Merge sort recursion
void destroy(Data*);           // De-allocate
void selectTopP(Data*, int);   // Extract top p elements

// Main function
int main() {
    // Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    // Parameters
    const int SIZE = 10000000;  // Size of the array
    const int p = 10;          // Number of top elements to select

    // Allocate and fill the array
    Data* a = fill(SIZE);

    // Sort the array using merge sort
    int startTime = time(0);
    mrgSort(a, 0, a->size);
    int totalTime = time(0) - startTime;
    cout << "Merge Sort Completed in " << totalTime << " seconds." << endl;

    // Extract the top p elements
    //selectTopP(a, p);

    // Deallocate data
    destroy(a);

    return 0;
}

// Fill the array with random short integers
Data* fill(int n) {
    Data* data = new Data;
    data->size = n;
    data->sortit = new short[n];
    data->working = new short[n];
    for (int i = 0; i < n; i++) {
        data->sortit[i] = rand() % 1000000; // Random short integers 
    }
    return data;
}

// Merge sort function
void mrgSort(Data* a, int beg, int end) {
    int center = (beg + end) / 2; // Split the array
    if ((center - beg) > 1) mrgSort(a, beg, center);
    if ((end - center) > 1) mrgSort(a, center, end);
    merge(a, beg, center, end);
}

// Merge function
void merge(Data* a, int beg, int nlow, int nhigh) {
    int span = nhigh - beg;
    int cntl = beg, cnth = nlow;

    for (int i = 0; i < span; i++) {
        if (cntl == nlow) {
            a->working[i] = a->sortit[cnth++];
        }
        else if (cnth == nhigh) {
            a->working[i] = a->sortit[cntl++];
        }
        else if (a->sortit[cntl] < a->sortit[cnth]) {
            a->working[i] = a->sortit[cntl++];
        }
        else {
            a->working[i] = a->sortit[cnth++];
        }
    }

    for (int i = 0; i < span; i++) {
        a->sortit[beg + i] = a->working[i];
    }
}

// Extract and print the top p elements
void selectTopP(Data* a, int p) {
    cout << "Top " << p << " elements:" << endl;
    for (int i = 0; i < p; i++) {
        cout << a->sortit[a->size - 1 - i] << " "; // Largest elements at the end
    }
    cout << endl;
}

// Print the array
void print(Data* a, int perLine) {
    for (int i = 0; i < a->size; i++) {
        cout << a->sortit[i] << " ";
        if (i % perLine == (perLine - 1)) cout << endl;
    }
    cout << endl;
}

// Deallocate the arrays
void destroy(Data* a) {
    delete[] a->sortit;
    delete[] a->working;
    delete a;
}
