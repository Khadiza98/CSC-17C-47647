/* 
 * File:   CustomerService.cpp
 * Author: Khadiza Akter
 * Created on October 17, 2024, 12:05 PM
 * Purpose: CustomerService class implementation
 */

#include "CustomerService.h"

// Add a new customer to the queue
void CustomerService::addCustomer(const string& name, int id) {
    customerQueue.push(Customer(name, id));
    cout << "Added customer: " << name << " (ID: " << id << ") to the queue." << endl;
}
// Emplace a new customer at the back of the queue
void CustomerService::emplaceCustomer(const string& name, int id) {
    customerQueue.emplace(name, id);
    cout << "Emplaced customer: " << name << " (ID: " << id << ") to the queue." << endl;
}
// Serve the customer at the front of the queue
void CustomerService::serveCustomer() {
    if (!customerQueue.empty()) {
        Customer currentCustomer = customerQueue.front();
        cout << "Serving customer:      ";
        currentCustomer.display();
        customerQueue.pop();
    } else {
        cout << "No customers to serve. The queue is empty." << endl;
    }
}
// Display the customer at the front of the queue
void CustomerService::showNextCustomer() const {
    if (!customerQueue.empty()) {
        cout << "\nNext customer in line: ";
        customerQueue.front().display();
    } else {
        cout << "\nNo customers in the queue." << endl;
    }
}
// Display the customer at the back of the queue
void CustomerService::showLastCustomer() const {
    if (!customerQueue.empty()) {
        cout << "\nLast customer in the queue: ";
        customerQueue.back().display();
    } else {
        cout << "\nNo customers in the queue." << endl;
    }
}
// Get the size of the queue
void CustomerService::displayQueueSize() const {
    cout << "\nQueue size: " << customerQueue.size() << endl;
}

// Check if the queue is empty
void CustomerService::checkQueueEmpty() const {
   if (customerQueue.empty()) {
        cout << "The queue is empty." << endl;
   } else {
        cout << "The queue is not empty." << endl;
   }
}

// Swap this queue with another queue
void CustomerService::swapQueues(CustomerService& otherService) {
    cout << "\nSwapping queues..." << endl;
    customerQueue.swap(otherService.customerQueue);
}

// Display all customers in the queue
void CustomerService::displayQueue() const {
    queue<Customer> tempQueue = customerQueue;
    if (tempQueue.empty()) {
        cout << "\nThe queue is empty." << endl;
        return;
    }
    cout << "\nCustomers in the queue:" << endl;
    cout << "-------------------------------" << endl;
    while (!tempQueue.empty()) {
        tempQueue.front().display();
        tempQueue.pop();
    }
    cout << "-------------------------------" << endl;
}

