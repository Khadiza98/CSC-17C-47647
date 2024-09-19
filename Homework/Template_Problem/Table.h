/* 
 * File:   Table.h
 * Created on September 19, 2024, 9:00 AM
 * Purpose: Table Template Class Specification
 */

#ifndef TABLE_H
#define TABLE_H

template<class T>
class Table{
    protected:
        int szRow;
        int szCol;
        RowAray<T> **columns;
    public:
        Table(unsigned int,unsigned int);
        Table(const Table<T> &);
        virtual ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        T getData(int,int)const;
        void setData(int,int,T);
        Table<T> operator+(const Table<T> &);
};

template<class T>
Table<T>::Table(unsigned int rows,unsigned int cols){
    szRow = rows;  // Set the number of rows
    szCol = cols;  // Set the number of columns
    columns = new RowAray<T>*[szCol];  // Allocate array of RowAray pointers for columns
    for (int c = 0; c < szCol; c++) {  // Loop until each column
        columns[c] = new RowAray<T>(szRow);  // Initialize each column with a new RowAray of rows
    }
}

template<class T>
Table<T>::Table(const Table &a){
    szRow = a.szRow;    // Copy the number of rows
    szCol = a.szCol;    // Copy the number of columns
    columns = new RowAray<T>*[szCol]; // Allocate memory for an array of RowAray pointers
    for(int c = 0; c < szCol; c++) {// Loop over each column in the table
        columns[c] = new RowAray<T>(szRow); // Allocate memory for each column (RowAray) and set the number of rows
        for(int r = 0; r < szRow; r++) { // Loop over each row in the current column
            columns[c]->setData(r, a.columns[c]->getData(r)); // Set the data in the current row and column of the new table
        } // End of inner for loop 
    } // End of outer for loop
}

template<class T>
Table<T>::~Table(){
    
    for (int col = 0; col < szCol; col++) {  // Loop until each column
        delete columns[col];  // Delete each RowAray object
    }
    delete[] columns;  // Delete the array of column pointers
}

template<class T>
T Table<T>::getData(int row,int col)const{
    return columns[col]->getData(row);  // Get data from the specified row to the column
}

template<class T>
void Table<T>::setData(int row,int col,T val){
    columns[col]->setData(row, val); // Set the valued at the specified row and column

}

template<class T>
Table<T> Table<T>::operator+(const Table<T> &a){
    Table<T> tempObj(szRow, szCol);  // Create a temporary Table object for storing the result
    for (int r = 0; r < szRow; r++) {  // Loop through each row
        for (int c = 0; c < szCol; c++) {  // Loop through each column
            T sum = this->getData(r, c) + a.getData(r, c);  // Add corresponding elements
            tempObj.setData(r, c, sum);  // Set the sum in the temporary Table
        } // End of inner for loop
    } // End of outer for loop
    return tempObj;  // Return the resulting Table
}


#endif /* TABLE_H */

