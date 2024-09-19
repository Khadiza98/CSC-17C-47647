/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on August 31, 2024, 10:33 AM
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}
// This function take Input data and place even in one vector odd in the other
void read(vector<int> &evenarray, vector<int> &oddarray){
   
    int numInput;  // Number of input 
    int userInput; // Hold the user input  
    cout << "Input the number of integers to input." << endl;
    cin >> numInput;
    cout << "Input each number." <<endl;
    // Read the user input and push back into even or odd array
    for (int i = 0; i < numInput; i++) {
        cin >> userInput;
        if (userInput % 2 == 0) evenarray.push_back(userInput);
        else                    oddarray.push_back(userInput);
    }
    
}
// This function output the content of the vector  setw(10)
void prntVec(vector<int> evenarray, vector<int> oddarray, int setwSize){
    cout <<setw(setwSize)<<"Vector"<<setw(setwSize)
         <<"Even"<<setw(setwSize)<<"Odd"<<endl;
    if (evenarray.size() == oddarray.size()) {
        for (int i = 0; i < evenarray.size(); i++) {
            cout <<setw(setwSize+setwSize)<<evenarray[i]
                 <<setw(setwSize)<<oddarray[i]<<endl;
        }
    } else if(evenarray.size() > oddarray.size()) {
        for (int i = 0; i < evenarray.size(); i++) {
            cout <<setw(setwSize+setwSize)<<evenarray[i];
            if(i < oddarray.size()) 
               cout <<setw(setwSize)<<oddarray[i];
            else  cout <<setw(setwSize)<<"";
            cout << endl;
        } // End of for loop
    } else {
        for (int i = 0; i < oddarray.size(); i++) {
            if (i < evenarray.size()) 
                cout <<setw(setwSize+setwSize)<<evenarray[i];
            else    cout << setw(setwSize+setwSize) <<"";
            cout  <<setw(setwSize)<<oddarray[i] << endl;
        } // End of for loop
    }
    
}

// This function copy the vectors into the 2 dimensional array
void copy(vector<int> evenarray, vector<int> oddarray,int array[][COLMAX]){
    if (evenarray.size() == oddarray.size()) {
        for (int i = 0; i < evenarray.size(); i++) {
               array[i][0] = evenarray[i];
                array[i][1] = oddarray[i];
            
        }
    } else if(evenarray.size() > oddarray.size()) {
        for (int i = 0; i < evenarray.size(); i++) {
            array[i][0] = evenarray[i];
            if(i < oddarray.size()) array[i][1] = oddarray[i];
        }
    } else {
        for (int i = 0; i < oddarray.size(); i++) {
            if (i < evenarray.size()) array[i][0] = evenarray[i];
            array[i][1] = oddarray[i];
        }
    } 
}

// This function output the content of the array setw(10)
void prntAry(const int array[][COLMAX],int evenLen,int oddLen,int setwSize){
    cout <<setw(setwSize)<<"Array"<<setw(setwSize)
         <<"Even"<<setw(setwSize)<<"Odd"<<endl;
    if (evenLen == oddLen) {
        for (int i = 0; i < evenLen; i++) {
            cout <<setw(setwSize+setwSize)<<array[i][0]
                 <<setw(setwSize)<<array[i][1]<<endl;
        } // End of for loop
    } else if(evenLen > oddLen) {
        for (int i = 0; i < evenLen; i++) {
            cout <<setw(setwSize+setwSize)<<array[i][0];
            if(i < oddLen) cout <<setw(setwSize)<<array[i][1];
            else           cout <<setw(setwSize)<<"";
            cout << endl;
        } // End of for loop
    } else {
        for (int i = 0; i < oddLen; i++) {
            if (i < evenLen)
                cout <<setw(setwSize+setwSize)<<array[i][0];
            else cout << setw(setwSize+setwSize) <<"";
            cout  <<setw(setwSize)<<array[i][1] << endl;
        } // End of for loop
    }
    
}