/* 
 * File:   CustomerService.h
 * Author: Khadiza Akter
 * Created on October 17, 2024, 12:05 PM
 * Purpose: CustomerService class specification
 */

#ifndef CUSTOMERSERVICE_H
#define CUSTOMERSERVICE_H
#include <iostream> //Input/Output Library
#include <queue>    //For queue container
#include <string>   //Needed for string
#include <iomanip>  // For formatting output
using namespace std;//STD Name-space where Library is compiled

#include "Customer.h"

// CustomerService class to handle customer queue operations
class CustomerService {
    private:
        queue<Customer> customerQueue;

    public:
        
        void addCustomer(const string&, int);// Add a new customer to the queue
        void emplaceCustomer(const string&, int);// Emplace a new customer at the back of the queue
        void serveCustomer();// Serve the customer at the front of the queue      
        void showNextCustomer() const;// Display the customer at the front of the queue
        void showLastCustomer() const;// Display the customer at the back of the queue
        void displayQueueSize() const;// Get the size of the queue
        void checkQueueEmpty() const;// Check if the queue is empty
        void swapQueues(CustomerService&);// Swap this queue with another queue
        void displayQueue() const;// Display all customers in the queue
    
};

#endif /* CUSTOMERSERVICE_H */

