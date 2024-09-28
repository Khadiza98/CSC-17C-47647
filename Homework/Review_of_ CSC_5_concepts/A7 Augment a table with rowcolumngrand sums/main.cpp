/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on August 31, 2024, 11:46 AM
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */
 
//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    cout << "Input a table and output the Augment row,col and total sums." << endl;
    cout <<"First input the number of rows and cols. <20 for each" << endl;
    cin >> row >> col;
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}
/*
*This function read the input table
*@Pram array where inputs will be stored, number of rows, number of Columns
*@Return None
*/
void read(int array2D[][COLMAX],int &row,int &col) {
    cout << "Now input the table." << endl;         //Display output
    for (int i = 0; i < row; i++) {                 //loop to fill the array table
        for (int j = 0; j < col; j++) {
            cin >> array2D[i][j];                   //Read in 2D array
        }
    }
} // End of read function

/*
*This function calculate sum for each row and column
*@Pram input numbers array, number of rows, number of Columns,
*and array (augment array) where summation values will be stored
*@Return None
*/
void sum(const int array[][COLMAX],int row,int col,int augArray[][COLMAX]) {
    //Declare local Variables and initialize by 0
    int sumRow = 0, sumCol = 0, i = 0, j = 0;
    //calculate sum of each row from the input array    
    for (i = 0; i < row; i++) {                  //Array loop number of rows
        sumRow = 0;                              // set row sum as zero
        for (j = 0; j < col; j++) {
            augArray[i][j] = array[i][j];        //Assign array value into the augArray
            sumRow += array[i][j];               //Sum rows of array
        }
        augArray[i][j] = sumRow;                 //Assign sum of rows into augArray
    }
    //calculate sum of the each column from augment array
    for (i = 0; i < col+1; i++) {               // Loop for number of column which increased already 1 by storing the summation of each row
        sumCol = 0;                             // set column sum as zero
        for (j = 0; j < row; j++) {             // loop through each row of augArray
            sumCol += augArray[j][i];           // calculate sum for each column
        }
        augArray[j][i] = sumCol;                // assign sum of column into augArray
    }
}

/*
*This function print the two dimensional array
*@Pram array that will print, number of rows, number of Columns, and space between two values
*@Return None
*/
void print(const int array[][COLMAX],int row,int col,int setwSize) {
    int i, j;                                      // loop counter variable
    for (i = 0; i < row; i++) {                // loop through the each row of two-dimensional array
        for (j = 0; j < col; j++) {            // loop through the each column of two-dimensional array
            cout << setw(setwSize) << array[i][j]; // Print the array value with spaces
        }
        cout << endl;                               
    }
}