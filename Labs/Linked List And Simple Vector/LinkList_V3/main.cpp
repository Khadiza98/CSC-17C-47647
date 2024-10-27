/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 20, 2024, 12:46 AM
 * Purpose: Linked from first principles, Complete the function prototypes for 
 *          the linked list pop_front(), pop_back(), push_front(),push_back(),
 *          prntLst(),dstryLst().Then converted to class and extended.
 */

#include <iostream>    // Input/Output Library
#include <cstdlib>     // For NULL pointer
using namespace std;   //STD Name-space where Library is compiled

//User Libraries
#include "LinkedList.h"

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    //Declare variables
    LinkedList *list = new LinkedList;// Dynamically allocate a LinkedList object
    
    list->fillLst(5);
    
    // Print the list
    cout << "Original List:" << endl;
    list->prntLst();

    // Push to the front
    list->push_front(0);
    cout << "After push_front(0):" << endl;
    list->prntLst();

    // Push to the back
    list->push_back(6);
    cout << "After push_back(6):" << endl;
    list->prntLst();

    // Pop from the front
    list->pop_front();
    cout << "After pop_front():" << endl;
    list->prntLst();

    // Pop from the back
    list->pop_back();
    cout << "After pop_back():" << endl;
    list->prntLst();
    
    //Exit stage right
    return 0;
}
