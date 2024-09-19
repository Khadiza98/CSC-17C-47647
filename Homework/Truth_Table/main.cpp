/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on August 29, 2024, 1:47 am
 * Purpose:  To tell the Truth
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    bool x,y;
    

    //Display the Heading
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y "<<
          " !(X||Y) !X&&!Y"<<endl;
    
    while( cin >> x >> y) { //Loop to read input into the x,y variable
       
        if (x == 1 && y == 1){ //If condition is satisfied execute the statement
        //First Row
           x = true;
           y = true;
            cout<<(x?'T':'F')<<" "
                <<(y?'T':'F')<<"  "
                <<(!x?'T':'F')<<"  "
                <<(!y?'T':'F')<<"   "
                <<(x&&y?'T':'F')<<"    "
                <<(x||y?'T':'F')<<"   "
                <<(x^y?'T':'F')<<"    "
                <<(x^y^x?'T':'F')<<"     "
                <<(x^y^y?'T':'F')<<"       "
                <<(!(x&&y)?'T':'F')<<"      "
                <<((!x||!y)?'T':'F')<<"        "
                <<(!(x||y)?'T':'F')<<"      "
                <<((!x&&!y)?'T':'F')<<endl;
        }
        //Second Row
        if (x == 1 && y == 0){ //If condition is satisfied execute the statement
            x = true;
            y = false;
            cout<<(x?'T':'F')<<" "
                <<(y?'T':'F')<<"  "
                <<(!x?'T':'F')<<"  "
                <<(!y?'T':'F')<<"   "
                <<(x&&y?'T':'F')<<"    "
                <<(x||y?'T':'F')<<"   "
                <<(x^y?'T':'F')<<"    "
                <<(x^y^x?'T':'F')<<"     "
                <<(x^y^y?'T':'F')<<"       "
                <<(!(x&&y)?'T':'F')<<"      "
                <<((!x||!y)?'T':'F')<<"        "
                <<(!(x||y)?'T':'F')<<"      "
                <<((!x&&!y)?'T':'F')<<endl;
        }
        //Third Row
        if (x == 0 && y == 1){ //If condition is satisfied execute the statement
           x = false;
           y = true;
           cout<<(x?'T':'F')<<" "
               <<(y?'T':'F')<<"  "
                <<(!x?'T':'F')<<"  "
                <<(!y?'T':'F')<<"   "
                <<(x&&y?'T':'F')<<"    "
                <<(x||y?'T':'F')<<"   "
                <<(x^y?'T':'F')<<"    "
                <<(x^y^x?'T':'F')<<"     "
                <<(x^y^y?'T':'F')<<"       "
                <<(!(x&&y)?'T':'F')<<"      "
                <<((!x||!y)?'T':'F')<<"        "
                <<(!(x||y)?'T':'F')<<"      "
                <<((!x&&!y)?'T':'F')<<endl;
        }
        //Fourth Row
        if(x == 0 && y == 0) { //If condition is satisfied execute the statement
            x = false;
            y = false;
            cout<<(x?'T':'F')<<" "
                <<(y?'T':'F')<<"  "
                <<(!x?'T':'F')<<"  "
                <<(!y?'T':'F')<<"   "
                <<(x&&y?'T':'F')<<"    "
                <<(x||y?'T':'F')<<"   "
                <<(x^y?'T':'F')<<"    "
                <<(x^y^x?'T':'F')<<"     "
                <<(x^y^y?'T':'F')<<"       "
                <<(!(x&&y)?'T':'F')<<"      "
                <<((!x||!y)?'T':'F')<<"        "
                <<(!(x||y)?'T':'F')<<"      "
                <<((!x&&!y)?'T':'F')<<endl;
        }
    }
    
    cout << endl; //Print a new line
    
    //Exit
    return 0;
}