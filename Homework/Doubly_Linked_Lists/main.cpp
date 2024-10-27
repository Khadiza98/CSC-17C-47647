/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 22, 2024, 12:46 AM
 * Purpose: From a Singular Linked List, create a Doubly Linked List.
 *          Use this to create a Sorted Linked List.
 *          Use this to create a prioritized list by user. 
 *          Bring to front those links recently queried.
 */
//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "DoublyLinkedList.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Declare variables here
    DoublyLinkedList obj;
    int choice, value;

    // Insert nodes in sorted order
    cout << "Inserting nodes into the list in sorted order." << endl;
    obj.insertSorted(10);
    obj.insertSorted(15);
    obj.insertSorted(20);
    obj.insertSorted(5);
    obj.insertSorted(40);

    // Display the sorted list
    cout << "\nSorted Doubly Linked List:" << endl;
    obj.display();

    // Menu for user input
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Query and bring a node to the front" << endl;
        cout << "2. Display the list" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice(e.g.,1,2,3): ";
        cin >> choice;
       
        switch (choice) {
            case 1:
                cout << "Enter the value to query: ";
                // Input validation for value
                while (!(cin >> value)) {
                    cout << "Invalid input. Please enter an integer value: ";
                    cin.clear(); // Clear the error flag
                    cin.ignore(10000, '\n'); // Discard invalid input
                }

                obj.bringToFront(value);  // Query and bring the node to the front
                break;
            case 2:
                cout << "Current list: ";
                obj.display();  // Display the current list
                break;
            case 3:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "\nInvalid input. Please enter a number(e.g.,1,2,3): \n";
                break;
        } //End of switch
        
    } while (choice != 3);
    
    // Exit the program
    return 0;
}
