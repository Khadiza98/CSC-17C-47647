/* 
 * File:   PlusTab.cpp
 * Author: Khadiza Akter
 * Created on September 14, 2024, 6:29 PM
 * Purpose: PlusTab class Implementation
 */

#include "PlusTab.h"

//***************************************************************
// Definition of operator+ overloading for the PlusTab class.
// This function added together two PlusTab objects.
// It creates a new temporary PlusTab object containing
// sum of the two tables. @param a is the PlusTab object to add.
// @return temp PlusTab object containing sum of both tables.
//***************************************************************
PlusTab PlusTab::operator+(const PlusTab &a){
    PlusTab temp(szRow, szCol);                 // Create a temporary PlusTab object
    for(int row = 0; row < szRow; row++){       // Loop through each row
        for(int col = 0; col < szCol; col++){   // Loop through each column
            int sum = this->getData(row, col) + a.getData(row, col);  // Add corresponding elements
            temp.setData(row, col, sum);        // Store the result in the temporary PlusTab
        }
    }
    return temp;                                // Return temp PlusTab with sum
}


