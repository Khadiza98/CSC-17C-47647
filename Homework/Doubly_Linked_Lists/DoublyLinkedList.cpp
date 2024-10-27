
/* 
 * File:   DoublyLinkedList.cpp
 * Author: Khadiza Akter
 * Created on October 22, 2024, 12:03 PM
 * Purpose: DoublyLinkedList class implementation
 */
#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;
// Function to insert a node in sorted order
void DoublyLinkedList::insertSorted(int value) {
    Node* newNode = new Node{value, nullptr, nullptr}; // Create a new node

    // If the list is empty, make the new node both head and tail
    if (!head) {
        head = tail = newNode;
        return;
    }

    // If the new node should be inserted at the front
    if (value <= head->data) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    // Traverse the list to find the correct insertion point
    Node* current = head;
    while (current->next && current->next->data < value) {
        current = current->next;
    }

    // Insert the new node at the correct position
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next) current->next->prev = newNode;
    else tail = newNode;  // If the new node is inserted at the end, update tail
    current->next = newNode;
}

// Function to bring a queried node to the front of the list
void DoublyLinkedList::bringToFront(int value) {
    Node* current = head;

    // If the list is empty, return
    if (!head) {
        cout << "List is empty. Cannot bring any node to front." << endl;
        return;
    }

    // If the node is already at the front, no need to move it
    if (head->data == value) {
        cout << "Node " << value << " is already at the front." << endl;
        return;
    }

    // Traverse the list to find the node
    while (current && current->data != value) {
        current = current->next;
    }

    // If the node is found, move it to the front
    if (current) {
        // If the node is the tail, update tail
        if (current == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }

        // Adjust the pointers to remove the node from its current position
        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;

        // Move the node to the front
        current->next = head;
        current->prev = nullptr;
        head->prev = current;
        head = current;

        // Output statement to indicate the move
        cout << "Node " << value << " has been moved to the front." << endl;
    } else {
        cout << "Node " << value << " not found in the list." << endl;
    }
}

// Function to display the list
void DoublyLinkedList::display() {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

