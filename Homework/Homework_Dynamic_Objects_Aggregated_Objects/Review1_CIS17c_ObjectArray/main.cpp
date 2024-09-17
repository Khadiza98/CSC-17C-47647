/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Feb 23rd, 2022, 8:36 PM
 * Purpose:  Dynamic Object Arrays
 */
 
//User Libraries
#include <iostream>
using namespace std;

//User Libraries
class RowAray{
    private:
        int size;
        int *rowData;
        int mrkRand(int);
    public:
        RowAray(int);   //Student to Complete
        ~RowAray();     //Student to Complete
        int getSize(){return size;}
        int getData(int i){return rowData[i];}
};

int RowAray::mrkRand(int seed){
    //Xn+1 = (aXn + c) mod m
    //where X is the sequence of pseudo-random values
    //m, 0 < m  - modulus 
    //a, 0 < a < m  - multiplier
    //c, 0 ≤ c < m  - increment
    //x0, 0 ≤ x0 < m  - the seed or start value
    unsigned int a = 31051;      // Short Prime
    unsigned int c = 997;        // Another Prime
    unsigned int shrt = 1<<15-1; // Range of positive signed short
    unsigned int m = 1<<31-1;    // Range of positive signed int
    static int Xn = 30937;       // Short Prime
    static int cnt = 0;          // Initialize the seed
    if(cnt == 0 && seed <= shrt) Xn = seed;
    cnt++;
    Xn = (a * Xn + c) % m;
    return Xn;
}

// Definition of Constructor for RowAray class
RowAray::RowAray(int n){
    size = n;                                 // Set the size of the row
    rowData = new int[size];                  // Dynamically allocate memory for the rowData
    for(int r = 0; r < size; r++){            // Now loop through each element of the row
        rowData[r] = mrkRand(size) % 90 + 10; // Assign random values between (10-99) to each element
    } // End for loop
} // End of RowAray constructor

// Definition of Destructor for RowAray class
RowAray::~RowAray(){
    delete []rowData;                         // Free the dynamically allocated memory
} // End of RowAray Destructor

class Table{
    private:
        int szRow;
        int szCol;
        RowAray **records;
    public:
        Table(int,int);  //Student to Complete
        ~Table();        //Student to Complete
        int getSzRow(){return szRow;}
        int getSzCol(){return szCol;}
        int getData(int,int); //Student to Complete
};

// Definition of Constructor for Table class
Table::Table(int rows, int cols){
    szRow = rows;                       // Set the number of rows
    szCol = cols;                       // Set the number of columns
    records = new RowAray*[szRow];      // Dynamically allocate memory for array of pointers to RowAray objects
    for(int r = 0; r < szRow; r++){     // Loop through each row
        records[r] = new RowAray(szCol);// Dynamically allocate a new RowAray object for each row with szCol columns
    }
} // End of Table Constructor

// Definition of Destructor for Table class
Table::~Table(){
    for(int r = 0; r < szRow; r++){     // Loop through each row
        delete records[r];              // Delete each dynamically allocated RowAray object
    }
    delete []records;                   // Delete dynamically allocated array of RowAray pointers.
} // End of Destructor

// Definition of getData to get data from a specific cell
int Table::getData(int row, int col){
    return records[row]->getData(col);  // Return data at the specified row and column
}

class Triangle{
    private:
        int szRow;
        RowAray **records;
    public:
        Triangle(int);  //Student to Complete
        ~Triangle();    //Student to Complete
        int getSzRow(){return szRow;}
        int getData(int,int);  //Student to Complete
};

// Definition of Constructor for Triangle class
Triangle::Triangle(int rows){
    szRow = rows;                       // Set the number of rows
    records = new RowAray*[szRow];      // Dynamically allocate memory for array of pointers to RowAray objects
    for(int r = 0; r < szRow; r++){     // loop throuh each row
        records[r] = new RowAray(r + 1);// Dynamically allocate a new RowAray object with number of columns (i + 1)
    }
} // End of Constructor

// Definition of Destructor for Triangle class
Triangle::~Triangle(){
    for(int r = 0; r < szRow; r++){     // Loop through each row
        delete records[r];              // Delete each dynamically allocated RowAray object
    }
    delete []records;                   // Free up dynamically allocated array of RowAray pointers
} // End of destructor

// Definition of getData Function
int Triangle::getData(int row, int col){
    return records[row]->getData(col);  // Return data at the specified row and column
}


//Global Constants

//Function Prototype
void prntRow(RowAray *,int);
void prntTab(Table *);
void prntTri(Triangle *);

//Execution Begins Here!
int main(int argc, char** argv) {
   //Initialize the random seed
   srand(static_cast<unsigned int>(time(0)));
   
   //Declare Variables
   int rows,cols,perLine;
   
   //Read in Rows and Cols
   cout<<"Input Rows and Cols"<<endl;
   cin>>rows>>cols;
   perLine=cols/2;
   
   //Test out the RowAray
   RowAray row(cols);
    
   //Print the RowAray
   cout<<"The Row Array size = "<<row.getSize()
           <<" printed "<<perLine<<" per Line";

   prntRow(&row,perLine);
   
   //Test out the Table
   Table tab(rows,cols);
   
   //Print the Table
   cout<<"The table size is [row,col] = ["<<rows<<","<<cols<<"]";
   prntTab(&tab);
   
   // Test out the Triangular Table
   Triangle tri(rows);
   
   //Print the Triangular Table
   cout<<"The triangular table size is [row,row] = ["<<rows<<","<<rows<<"]";
   prntTri(&tri);

   //Exit Stage Right
   return 0;
}

void prntRow(RowAray *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->getSize();i++){
        cout<<a->getData(i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntTab(Table *a){
    cout<<endl;
    for(int row=0;row<a->getSzRow();row++){
        for(int col=0;col<a->getSzCol();col++){
            cout<<a->getData(row,col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntTri(Triangle *a){
    cout<<endl;
    for(int row=0;row<a->getSzRow();row++){
        for(int col=0;col<=row;col++){
            cout<<a->getData(row,col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
