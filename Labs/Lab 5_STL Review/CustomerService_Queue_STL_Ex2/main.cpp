/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 17, 2024, 10:53 PM
 * Purpose: Simulate a customer service system using the queue container
 */

//System Libraries
#include <iostream> //Input/Output Library
#include <string>   //Needed for string
#include <queue>    //For queue container
using namespace std;//STD Name-space where Library is compiled

//User Libraries
#include "CustomerService.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    //Declare variables here
    CustomerService s1, s2;    // Create two customer service queues


    // Add some customers to service1
    s1.addCustomer("Sandy", 101);
    s1.addCustomer("Lisa", 102);
    s1.emplaceCustomer("Charlie", 103); // Use emplace to add Charlie
    s1.emplaceCustomer("Ava", 104);   // Use emplace to add Ava

    // Display queue details
    s1.displayQueue();
    s1.displayQueueSize();
    s1.checkQueueEmpty();

    // Serve customers from service1
    s1.showNextCustomer();
    s1.serveCustomer();
    s1.showNextCustomer();
    s1.serveCustomer();
    
    // Show front and back customers in service1
    s1.showNextCustomer();
    s1.showLastCustomer();

    // Display remaining customers in service1
    s1.displayQueueSize();
    s1.displayQueue();

    // Add some customers to service2
    s2.addCustomer("Eve", 201);
    s2.addCustomer("Frank", 202);
    s2.emplaceCustomer("Grace", 203);

    // Display customers in service2 before swap
    cout << "\n***********Before swapping***********" << endl;
    cout << "\nService1 queue:" << endl;
    s1.displayQueue();
    cout << "\nService2 queue:" << endl;
    s2.displayQueue();

    // Swap queues between service1 and service2
    s1.swapQueues(s2);

    // Display customers after swapping queues
    cout << "\n***********After swapping************" << endl;
    cout << "\nService1 queue:" << endl;
    s1.displayQueue();
    cout << "\nService2 queue:" << endl;
    s2.displayQueue();

    return 0;
}
