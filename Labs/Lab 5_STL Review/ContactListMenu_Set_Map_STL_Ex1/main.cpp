/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on September 29, 2024, 12:26 PM
 * Purpose: This project will simulate a contact list menu using map and set associative
 *          container, where can store names and associated phone numbers.
 *          Store unique contacts using a Set, and use a Map to associate each
 *          contact name (as a key) with a phone number (as a value). Also, add
 *          new contacts, find a contact by name, and display all contacts.

 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <set>        // For using set container
#include <map>        // For using map container
#include <string>     // For using std::string
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
// Function to display all contacts
void displayContacts(const map<string, string>& contMap) {
    cout << "\nContact List:\n";
    if (contMap.empty()) {
        cout << "There is no contacts available.\n";
    } else {
        for (const auto& contact : contMap) {
            cout << contact.first << " : " << contact.second << "\n";  // Print name and phone number
        }
    }
}
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int choice = 0;                 // To hold the number of choice input
    string name = "", phone = "";   // To hold the name and phone number
    set<string> contactSet;         // Set to store unique contact names
    map<string, string> contactMap; // Map to related names with phone numbers

    do {
        cout << "\nContact List Menu:\n";
        cout << "1. Add a contact\n";
        cout << "2. Find a contact\n";
        cout << "3. Show all contacts\n";
        cout << "4. Exit!\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore();  // To discard characters from the input buffer.
                cout << "\nEnter contact name: ";
                getline(cin, name);

                // Check if the contact already exists
                if (contactSet.find(name) == contactSet.end()) {
                    cout << "Enter phone number: ";
                    getline(cin, phone);

                    // Add contact to both the set and map
                    contactSet.insert(name);
                    contactMap[name] = phone;

                    cout << "Contact added successfully.\n";
                } else {
                    cout << "Contact already exists.\n";
                }
                break;

            case 2:
                cin.ignore();  // To discard characters from the input buffer.
                cout << "Enter contact name to find: ";
                getline(cin, name);

                // Search for the contact in the map
                if (contactSet.find(name) != contactSet.end()) {
                    cout << "Phone number for " << name << " is: " << contactMap[name] << "\n";
                } else {
                    cout << "Contact not found.\n";
                }
                break;

            case 3:
                displayContacts(contactMap);  // Display all contacts
                break;

            case 4:
                cout << "Exiting the Contact List.\n";
                break;

            default:
                cout << "Invalid choice! Please select a valid option.\n";
        }
    } while (choice != 4);

    //Exit the program
    return 0;
}

