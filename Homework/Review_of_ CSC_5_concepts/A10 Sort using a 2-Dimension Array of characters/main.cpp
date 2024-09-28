/*
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on September 1, 2024, 9:49 PM
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

 //System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX = 80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char[][COLMAX], int&);//Outputs row and columns detected from input
void sort(char[][COLMAX], int, int, const char[], const char[]);//Sort by row using strcmp();
void print(const char[][COLMAX], int, int);//Print the sorted 2-D array
int strcmp(char[], char[], const char[], const char[]);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW = 30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn, colDet, rowIn, rowDet;//Row, Col input and detected
    char replace[COLMAX], with[COLMAX];//New sort order

    //Input the new sort order then sort
    cout << "Modify the sort order by swapping these characters." << endl;
    cin >> replace;
    cout << "With the following characters" << endl;
    cin >> with;
    cout << "Read in a 2 dimensional array of characters and sort by Row" << endl;
    cout << "Input the number of rows <= 20" << endl;
    cin >> rowIn;
    cout << "Input the maximum number of columns <=20" << endl;
    cin >> colIn;

    //Now read in the array of characters and determine it's size
    rowDet = rowIn;
    cout << "Now input the array." << endl;
    colDet = read(array, rowDet);

    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if (rowDet == rowIn && colDet == colIn) {
        sort(array, rowIn, colIn, replace, with);
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

    //Exit
    return 0;
}
/*
 * This function read the user inputs for the two dimensional array
 * @Param array where stores the input data, reference value of the row size
 * @Return length of the column of input array
 */
int  read(char array2D[][COLMAX], int& rowSize) {

    string userinput;
    int rowIndex = 0;
    int column = 0;
    for (int i = 0; i < rowSize; i++) {             // loop through each row of the array
        cin >> userinput;                           // take the user input

        if (userinput.size() > 0 && userinput.size() < COLMAX) {
            strcpy(array2D[rowIndex], userinput.c_str());
            rowIndex++;
            if (userinput.size() > column) column = userinput.size();
        
        } // End of if condition
    } // End of for loop
    
    return column;                                // return the length of the columns
}

/*
 * This function sort the two dimensional array of character
 * @Param array where stores the input data, number of rows, number of columns
 * @Return none
 */
void sort(char array2D[][COLMAX], int row, int col, const char replace[], const char with[]) {

    char temp[80];

    for (int i = 0; i < row - 1; i++) {         // Loop until shorting the array

        for (int j = 0; j < row - 1 - i; j++) {

            //comparison two strings
           //if first string is greater than second one then swap them
            if (strcmp(array2D[j], array2D[j + 1],replace,with) > 0) {
                strcpy(temp, array2D[j]);
                strcpy(array2D[j], array2D[j + 1]);
                strcpy(array2D[j + 1], temp);
            } // End of if condition
        }
    } // End of for loop
}

/*
 * This function print the two dimensional array
 * @Param array where stored the data, number of rows, number of columns
 * @Return none
 */
void print(const char array[][COLMAX], int row, int col) {

    for (int i = 0; i < row; i++) cout << array[i] << endl;

} // End of print function

//This function replace the sort order according to Replace, and With character arrays
int strcmp(char arrayJ[], char arrayJ1[], const char replace[], const char with[]) {
    char temp[80];
    char temp1[80];
    strcpy(temp, arrayJ);
    strcpy(temp1, arrayJ1);
    for (int i = 0; i < strlen(temp); i++) {
        for (int j = 0; j < strlen(replace); j++) {
            if (temp[i] == replace[j]) {
                if (j <= strlen(with)) {
                    temp[i] = with[j];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < strlen(temp1); i++) {
        for (int j = 0; j < strlen(replace); j++) {
            if (temp1[i] == replace[j]) {
                if (j <= strlen(with)) {
                    temp1[i] = with[j];
                    break;
                }
            }
        }
    }
    for (int j = 0; j < strlen(temp) && j < strlen(temp1); j++) {
        if (temp[j] > temp1[j])  return 1;
    }
    return 0;
    
} // End of strcmp function
