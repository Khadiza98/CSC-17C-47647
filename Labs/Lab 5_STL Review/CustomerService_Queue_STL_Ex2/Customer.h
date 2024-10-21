/* 
 * File:   Customer.h
 * Author: Khadiza Akter
 * Created on October 17, 2024, 12:04 PM
 * Purpose: Customer class specification
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

// Customer class to represent a customer
class Customer {
    public:
        string name;
        int id;
        // Constructor
        Customer(string name, int id) : name(name), id(id) {}
        // Display customer details
        void display() const {
            cout << "Customer Name: " << setw(10) << left 
                 << name << " | ID: " << setw(4) << id << endl;
        }
};


#endif /* CUSTOMER_H */

