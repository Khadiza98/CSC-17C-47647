/* 
 * File:   DoublyLinkedList.cpp
 * Author: Khadiza Akter
 * Created on October 22, 2024, 12:03 PM
 * Purpose: DoublyLinkedList class specification
 */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"

// Doubly Linked List class
class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;

    public:
        // Constructor to initialize the head and tail pointers
        DoublyLinkedList() {
            head = nullptr; 
            tail = nullptr;
        }
        void insertSorted(int); // Function to insert a node in sorted order
        void bringToFront(int); // Function to bring a queried node to the front of the list
        void display();         // Function to display the list    
};

#endif /* DOUBLYLINKEDLIST_H */

