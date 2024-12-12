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
int ob, ol,oe, oi, of, fs, fm, os, oef, oei, om;
// Function Prototypes
Data* fill(int);               // Fill the array
void print(Data*, int);        // Print the array
void merge(Data*, int, int, int); // Merge two arrays
void mrgSort(Data*, int, int); // Merge sort recursion
void destroy(Data*);           // Deallocate
void selectTopP(Data*, int);   // Extract top p elements

// Main function
int main() {
    // Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    // Parameters
    const int SIZE = 250000;  // Size of the array
    const int p = 1000;         // Number of top elements to select

    // Allocate and fill the array
    Data* a = fill(SIZE);

    // Sort the array using merge sort
    mrgSort(a, 0, a->size);
    cout << "total operations=" << ob+ol+oe+oi+of+fs+fm+os+oef+oei+om << endl;
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
        data->sortit[i] = rand() % 100000; // Random short integers (0 to 9999)
    }
    return data;
}

// Merge sort function
void mrgSort(Data* a, int beg, int end) {
    fs++; // count the function call
    os += 7; // add total number of operation 
    int center = (beg + end) / 2; // Split the array
    if ((center - beg) > 1) mrgSort(a, beg, center);
    if ((end - center) > 1) mrgSort(a, center, end);
    merge(a, beg, center, end);
}

// Merge function
void merge(Data* a, int beg, int nlow, int nhigh) {
    fm++;// increase each function call;
    ob += 5;
    int span = nhigh - beg;
    int cntl = beg, cnth = nlow;

    for (int i = 0; i < span; i++) {
        oi += 3;
        if (cntl == nlow) {
            of += 3;
            a->working[i] = a->sortit[cnth++];
        }
        else if (cnth == nhigh) {
            oe += 3;
            a->working[i] = a->sortit[cntl++];
        }
        else if (a->sortit[cntl] < a->sortit[cnth]) {
            ol += 3;
            a->working[i] = a->sortit[cntl++];
        }
        else {
            om += 3;
            a->working[i] = a->sortit[cnth++];
        }
    }
    oef += 1;
    for (int i = 0; i < span; i++) {
        oei += 5;
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
