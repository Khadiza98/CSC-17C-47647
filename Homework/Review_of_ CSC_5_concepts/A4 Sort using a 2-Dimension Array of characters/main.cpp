/*
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on September 3, 2024 on 10:05 PM
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

 //System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX = 80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char[][COLMAX], int&);//Outputs row and columns detected from input
void sort(char[][COLMAX], int, int);//Sort by row
void print(const char[][COLMAX], int, int);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW = 30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn, colDet, rowIn, rowDet;//Row, Col input and detected

    //Input the size of the array you are sorting
    cout << "Read in a 2 dimensional array of characters and sort by Row" << endl;
    cout << "Input the number of rows <= 20" << endl;
    cin >> rowIn;
    cout << "Input the maximum number of columns <=20" << endl;
    cin >> colIn;

    //Now read in the array of characters and determine it's size
    //if((rowIn > 0 && rowIn <=20) && (colIn > 0 && rowIn <=20))
    //{
    rowDet = rowIn;
    cout << "Now input the array." << endl;
    colDet = read(array, rowDet);

    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if (rowDet == rowIn && colDet == colIn) {
        sort(array, rowIn, colIn);
        cout << "The Sorted Array" << endl;
        print(array, rowIn, colIn);
    }
    else {
        if (rowDet != rowIn)
            cout << (rowDet < rowIn ? "Row Input size less than specified." :
                "Row Input size greater than specified.") << endl;
        if (colDet != colIn)
            cout << (colDet < colIn ? "Column Input size less than specified." :
                "Column Input size greater than specified.") << endl;
    }
    //}

    //Exit
    return 0;
}
/*
 * This function read the user inputs for the two dimensional array
 * @Param array where stores the input data, reference value of the row size
 * @Return length of the column of input array
 */
int  read(char array[][COLMAX], int& rowSize) {
    
    string input;
    int rowIndex = 0;
    int col = 0;
    for (int i = 0; i < rowSize; i++)               // loop through each row of the array
    {
        cin >> input;                               // take the user input
      
        if(input.length() > 0 && input.length() < COLMAX) {
            strcpy(array[rowIndex], input.c_str());
            rowIndex++;
            if (input.length() > col) {
                col = input.length();
            }
        }
        
    
    }
    return col;                                // return the length of the columns
}
/*
 * This function sort the two dimensional array of character
 * @Param array where stores the input data, number of rows, number of columns
 * @Return none
 */
void sort(char array[][COLMAX], int row, int col) {
   
    char temp[col];
   
    for(int i = 0; i < row - 1; i++) {
        
        for(int j = 0; j < row - 1 - i; j++) {
            
     //comparison two strings
    //if first string is greater than second one then swap them
           if ( strcmp(array[j], array[j+1]) > 0 ) {
               
                strcpy(temp, array[j]);
                strcpy(array[j], array[j+1]);
                strcpy(array[j+1], temp);
            }
        }
    }
}
/*
 * This function print the two dimensional array
 * @Param array where stored the data, number of rows, number of columns
 * @Return none
 */
void print(const char array[][COLMAX], int row, int col) {

    for (int i = 0; i < row; i++) {     
         
            cout << array[i] << endl;
    }
    
    
}