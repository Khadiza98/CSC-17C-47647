/* 
 * File:   LinkedList.h
 * Author: Khadiza Akter
 * Created on October 25, 2024, 5:50 PM
 * Purpose: LinkedList class implementation
 */

#include <iostream>    // Input/Output Library
#include <cstdlib>     // For NULL pointer
using namespace std;   //STD Name-space where Library is compiled

#include "LinkedList.h"

void LinkedList::fillLst(int n) {
    // Create the first node with data 1
    front = new Link;
     front->data = 1;
    front->lnkNext = NULL;
    Link *temp = front;  // Temp pointer for traversal

   // Create subsequent nodes from 2 to n
    for (int i = 2; i <= n; ++i) {
        Link *nxtLink = new Link;   // Create a new link
        nxtLink->data = i;          // Assign data
        temp->lnkNext = nxtLink;    // Link it to the previous node
        temp = nxtLink;             // Move temp to the new link
    }
    temp->lnkNext = NULL;  // End the list with NULL
}
// Function to print the list
void LinkedList::prntLst() {
    Link *temp = front;  // Start from the front
    while (temp != NULL) {
        cout << temp->data << endl;  // Print the data
        temp = temp->lnkNext;        // Move to the next node
    }
}
// Function to push a new link to the front
void LinkedList::push_front(int value) {
    Link *newLink = new Link;  // Create a new link
    newLink->data = value;     // Set the data
    newLink->lnkNext = front;  // Link the new node to the current front
    front = newLink;           // Update front to point to the new node
}  
void LinkedList::push_back(int value) {
    Link *newLink = new Link;  // Create a new link
    newLink->data = value;     // Set the data
    newLink->lnkNext = NULL;   // This will be the last node, so set lnkNext to NULL

    if (front == NULL) {
      // If the list is empty, make the new link the front
        front = newLink;
    } else {
        // Traverse to the last node
        Link *temp = front;
        while (temp->lnkNext != NULL) {
            temp = temp->lnkNext;
        }
        // Set the last node's next to the new link
        temp->lnkNext = newLink;
    }
}
// Function to pop a link from the front
void LinkedList::pop_front() {
    if (front == NULL) return;  // Do nothing if the list is empty
    Link *temp = front;         // Store the current front
    front = front->lnkNext;     // Move front to the next node
    delete temp;                // Delete the old front
}

// Function to pop a link from the back
void LinkedList::pop_back() {
    if (front == NULL) return;  // Do nothing if the list is empty

    if (front->lnkNext == NULL) {
    // If there's only one element, delete the front
        delete front;
        front = NULL;
    } else {
        // Traverse to the second last node
        Link *prev = NULL;
        Link *temp = front;
        while (temp->lnkNext != NULL) {
            prev = temp;
            temp = temp->lnkNext;
        }
        prev->lnkNext = NULL;  // Set the second last node's next to NULL
        delete temp;           // Delete the last node
    }
}
