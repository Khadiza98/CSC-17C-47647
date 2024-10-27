/* 
 * File:   LinkedList.h
 * Author: Khadiza Akter
 * Created on October 25, 2024, 5:50 PM
 * Purpose: LinkedList class specification
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// LinkedList class to manage the linked list operations
class LinkedList {
    private:
        // Structure for a single node in the list
        struct Link {//STD Name-space where Library is compiled
            int data;      // Data stored in the link
            Link *lnkNext; // Pointer to the next link in the list
        };

        Link *front; // Pointer to the front of the list (head node)

    public:
        // Constructor: Initialize the list with NULL front
        LinkedList() {
            front = NULL; 
        }
        // Destructor: Destroy the list to free allocated memory
        ~LinkedList() {
            while (front != NULL) {
                Link *temp = front;  // Temp pointer to the current front
                front = front->lnkNext;  // Move front to the next node
                delete temp;              // Delete the old front node
            }
        }
        void fillLst(int); // Function to fill the list with 'n' elements
        void prntLst();// Function to print the list
        void push_front(int);// Function to push a new link to the front
        void push_back(int);// Function to push a new link to the back
        void pop_front();// Function to pop a link from the front
        void pop_back();// Function to pop a link from the back

};
#endif /* LINKEDLIST_H */

