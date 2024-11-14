/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 3, 2024, 11:56 PM
 * Purpose: Implement Set container in the mode problem 
 */

//Libraries
#include <iostream>//I/O
#include <set>// For using set
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
    multiset<int> mSet(array, array + arySize);  // Multi-set for frequency counting
    int maxFreq = 0;//To store the maximum frequency found in the array.
    set<int> mySet;// Set to store unique mode values
    // Iterate through each element in the multi-set to determine the highest frequency.
    for (int num : mSet) 
        maxFreq = max(maxFreq, (int)mSet.count(num)); 
    // Find all elements that match the maximum frequency 
    // and add them to the set of unique modes.
    for (int num : mSet)
        if (mSet.count(num) == maxFreq)
            mySet.insert(num);
    // Dynamically allocate an array to store the mode information
    int *modeAry = new int[mySet.size() + 2];
    modeAry[0] = mySet.size(); // Store the number of unique modes found.
    modeAry[1] = maxFreq; // Store the maximum frequency in the second position.
    // Copy each unique mode value from set to array, starting at index 2.
    int i = 2;
    for (int num : mySet) modeAry[i++] = num;
    
    return modeAry;// Return the dynamically allocated mode array.
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