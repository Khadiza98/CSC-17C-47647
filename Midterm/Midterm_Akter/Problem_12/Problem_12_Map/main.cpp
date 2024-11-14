/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 2, 2024, 8:08 PM
 * Purpose: Implement Map container in the mode problem 
 */

//Libraries
#include <iostream>//I/O
#include <map> // For map STL
using namespace std;

//Function Prototypes
int *fillAry(int,int);
void prntAry(int *,int,int);
void prntMod(int *);
int *mode(const int *,int);

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize=15;
    int modNum=10;
    int *ary=fillAry(arySize,modNum);
    
    //Print the initial array
    prntAry(ary,arySize,10);
    
    //Calculate the mode array
    int *modeAry=mode(ary,arySize);
    
    //Print the modal information of the array
    prntMod(modeAry);
    
    //Delete allocated memory
    delete []ary;
    delete []modeAry;
    
    //Exit stage right
    return 0;
}

int *mode(const int *array, int arySize) {
    // Use map to store frequency of each element
    map<int, int> freqCount;
    for (int i = 0; i < arySize; i++) freqCount[array[i]]++;
    // Find max frequency
    int maxFreq = 0;
    for (const auto &val : freqCount) {
        if (val.second > maxFreq) {
            maxFreq = val.second;
        }
    }
    // Count the number of modes
    int nModes = 0;
    for (const auto &val : freqCount) {
        if (val.second == maxFreq) {
            nModes++;
        }
    }
    // Allocate the mode array
    int *modeAry = new int[nModes + 2];
    modeAry[0] = nModes;
    modeAry[1] = maxFreq;
    
    // Fill the mode array
    int indx = 2;
    for (const auto &val : freqCount) {
        if (val.second == maxFreq) {
            modeAry[indx++] = val.first;
        }
    }
    
    return modeAry;
}

void prntMod(int *ary){
    cout<<endl;
    cout<<"The number of modes = "<<
            ary[0]<<endl;
    cout<<"The max Frequency = "<<
            ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";
    for(int i=2;i<ary[0]+1;i++){
        cout<<ary[i]<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
}

void prntAry(int *array,int n,int perLine){
    //Output the array
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n, int modNum){
    //Allocate memory
    int *array=new int[n];
    //Fill the array with 2 digit numbers
    for(int i=0;i<n;i++){
        *(array+i)=i%modNum;
        //*(array+i)=rand()%modNum;
    }
    //Exit function
    return array;
}