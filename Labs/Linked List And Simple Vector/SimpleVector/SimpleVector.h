/* 
 * File:   SimpleVector.h
 * Author: Khadiza Akter
 * Created on October 22, 2024, 5:04 PM
 * Purpose: SimpleVector class specification
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <cstdlib> // For exit function

using namespace std;

template <class T>
class SimpleVector {
private:
    // Node structure for the linked list
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head;      // Head pointer to the linked list
    int arraySize;   // Number of elements in the linked list
    int capacity;    // Total capacity (doubles or shrinks as needed)

    void resize(int newSize); // Handles dynamic resizing

public:
    // Default constructor
    SimpleVector() : head(nullptr), arraySize(0), capacity(1) {}

    // Constructor with initial size
    SimpleVector(int);

    // Copy constructor
    SimpleVector(const SimpleVector&);

    // Destructor
    ~SimpleVector();

    // Accessor for size
    int size() const { return arraySize; }

    // Function to add an element (push_back)
    void push_back(T);

    // Function to remove an element (pop_back)
    void pop_back();

    // Overloaded [] operator
    T& operator[](const int&);

    // Helper function to handle index bounds
    void subError() const;
};

//**************************
// Constructor with size
//**************************
template <class T>
SimpleVector<T>::SimpleVector(int s) : head(nullptr), arraySize(0), capacity(s) {
    for (int i = 0; i < s; i++) {
        push_back(T()); // Initialize with default values
    }
}

//*******************************
// Copy Constructor
//*******************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector& obj) {
    head = nullptr;
    arraySize = 0;
    capacity = obj.capacity;

    Node* temp = obj.head;
    while (temp) {
        push_back(temp->data);
        temp = temp->next;
    }
}

//*************************
// Destructor
//*************************
template <class T>
SimpleVector<T>::~SimpleVector() {
    Node* current = head;
    while (current) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

//*************************
// Resize function
//*************************
template <class T>
void SimpleVector<T>::resize(int newSize) {
    if (newSize < 1) newSize = 1; // Ensure minimum capacity of 1
    capacity = newSize;
}

//****************************
// Push back with resizing
//****************************
template <class T>
void SimpleVector<T>::push_back(T value) {
    if (arraySize == capacity) {
        resize(capacity * 2); // Double capacity if limit reached
    }

    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    arraySize++;
}

//****************************
// Pop back with resizing
//****************************
template <class T>
void SimpleVector<T>::pop_back() {
    if (arraySize == 0) return; // No elements to remove

    Node* temp = head;
    if (arraySize == 1) { // Single element case
        delete head;
        head = nullptr;
    } else {
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    arraySize--;

    // Shrink capacity if usage falls below 1/4
    if (arraySize < capacity / 4 && capacity > 1) {
        resize(capacity / 2);
    }
}

//****************************
// Subscript operator
//****************************
template <class T>
T& SimpleVector<T>::operator[](const int& index) {
    if (index < 0 || index >= arraySize) subError();

    Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}

//****************************
// Error handling
//****************************
template <class T>
void SimpleVector<T>::subError() const {
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

#endif // SIMPLEVECTOR_H
