#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function Prototypes
void fillAry(short[], int);          // Fill array with random short integers
void partialSelSort(short[], int, int); // Partial selection sort for first p elements
void printFirstElements(short[], int); // Print the first p elements

// Program Execution Begins Here
int main() {
    // Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    // Parameters
    const int SIZE = 100000;  // Size of the array
    int p = 100000;          // Number of elements to sort
    short array[SIZE];

    // Fill the array with random short integers
    fillAry(array, SIZE);

    // Sort the first p elements and measure execution time
    int startTime = time(0);
    partialSelSort(array, SIZE, p);
    int endTime = time(0);

    // Display execution time
    cout << "Partial Selection Sort for First " << p << " Elements Completed in "
        << endTime - startTime << " seconds." << endl;

    // Print the first p elements
    //printFirstElements(array, p);

    return 0;
}

// Fill the array with random short integers
void fillAry(short a[], int n) {
    for (int indx = 0; indx < n; indx++) {
        a[indx] = rand() % 100000; // Random short integers (0 to 99999)
    }
}

// Partial selection sort for first p elements
void partialSelSort(short a[], int n, int p) {
    for (int pos = 0; pos < p; pos++) { // Only sort the first p positions
        int minIndex = pos;
        for (int i = pos + 1; i < n; i++) { // Find the minimum in the remaining unsorted part
            if (a[i] < a[minIndex]) {
                minIndex = i;
            }
        }
        // Swap the minimum element with the current position
        if (minIndex != pos) {
            short temp = a[pos];
            a[pos] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

// Print the first p elements
void printFirstElements(short a[], int p) {
    cout << "First " << p << " elements in sorted order:" << endl;
    for (int i = 0; i < p; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
