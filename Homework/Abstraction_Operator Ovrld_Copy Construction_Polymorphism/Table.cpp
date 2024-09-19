/* 
 * File:   Table.cpp
 * Author: Khadiza Akter
 * Created on September 14, 2024, 6:25 PM
 * Purpose: Table class Implementation
 */

#include "Table.h"

Table::Table(unsigned int rows,unsigned int cols){
    szRow=rows;
    szCol=cols;
    columns=new RowAray*[cols];
    for(int col=0;col<cols;col++){
        columns[col]=new RowAray(rows);
    }
}

//***************************************************************
// Definition of copy constructor for the Table class.
// This constructor takes a reference to another Table object 'a'
//***************************************************************
Table::Table(const Table &a){
    szRow = a.szRow;    // Copy the number of rows
    szCol = a.szCol;    // Copy the number of columns
    columns = new RowAray*[szCol]; // Allocate memory for an array of RowAray pointers
    for(int c = 0; c < szCol; c++) {// Loop over each column in the table
        columns[c] = new RowAray(szRow); // Allocate memory for each column (RowAray) and set the number of rows
        for(int r = 0; r < szRow; r++) { // Loop over each row in the current column
            columns[c]->setData(r, a.columns[c]->getData(r)); // Set the data in the current row and column of the new table
        }
    }
}

//***********************************************************
// Definition of destructor for the Table class.
// This destructor delete dynamically allocated memory 
// for the RowAray objects inside
//***********************************************************
Table::~Table(){
    for(int col = 0; col < szCol; col++){
        delete columns[col];    // Delete the memory for each RowAray
    }
    delete[] columns;           // Delete the memory for columns array
}

//***********************************************************
// Definition of getData function. This function get value
// from the RowAray in the specified column and row.
// @param number of row and col index
// @return data at the specified row and column
//***********************************************************
int Table::getData(int row,int col)const{

    return columns[col]->getData(row);
}

//***********************************************************
// Definition of setData function. This function sets value
// of the RowAray at the given column and row.
// @param number of row and col index, also new value to set
//***********************************************************
void Table::setData(int row,int col,int val){
    
    columns[col]->setData(row, val);
}


