/* 
 * File: main.cpp
 * Author: Khadiza Akter
 * Created on September 1, 2024, 10:21 PM
 * Purpose: Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays.
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;


//User Libraries Here

//Global Constants
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce, pattern, match);
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}
/*
 * This function search for 1 occurrence in the array list
 * @Param sntnce,pattern store number of characters,and number of position
 * @Return pos is a index of found pattern 
 */
int  srch1(const char sntnce[],const char pattern[],int pos){
    int i = 0;          // used as a subscript to search array
    bool found = false; //used to indicate if value is found
    int lenS = strlen(sntnce);// used to store the length of sentence
    int lenP = strlen(pattern); // used to store the length of pattern
    string s = "";
    string p = "";
    for (i = 0; i < lenS; i++) { //loop to convert char array of sentence to string
        s = s + sntnce[i];
    }
    for (i = 0; i < lenP; i++) { //loop to convert char array of pattern to string
        p += pattern[i];
    }
    if ( (lenS >= lenP)) { 
        for (i = 0; (i < lenS && !found); i++) {
            if ( strcmp(p.c_str(), s.substr(i, lenP).c_str()) == 0) {
             pos = i;  
             found = true;
            }   
        } // End of for loop
    } // End of if
    return pos;
} // End of srch1 function
/*
 * This function search for all occurrence
 * @Param sntnce,pattern store number of characters,and match store # of int.
 * @Return none
 */
void srchAll(const char sentence[],const char pattern[], int match[]){
    int i = 0;                  // used as a subscript to search array
    int lenS = strlen(sentence);  // used to store the length of sentence
    int lenP = strlen(pattern); // used to store the length of pattern
    string s = "";              //used to hold string of char array sentence
    string p = "";              //used to hold string of char array pattern
    int count = 0;
    for(int k=0; k<80; k++) match[k] = -1;
    for (i = 0; i < lenS; i++) s = s + sentence[i]; //loop to convert sentence char array to string    
    for (i = 0; i < lenP; i++) p += pattern[i]; //loop to convert pattern char array to string  
    if ( (lenS >= lenP)) { 
        
        for (i = 0; i < lenS; i++) {
            if ( strcmp(p.c_str(), s.substr(i, lenP).c_str()) == 0) {
             match[count] = i;
             count++;
            } // End of if    
        } // End of for loop
    } // End of if
} // End of srchAll function

/*
 * This function print the character of array
 * @Param array store number of characters
 * @Return none
 */
void print(const char array[]) {
    for (int i = 0; i < strlen(array); i++) {
     cout <<  array[i];   
    }
    cout << endl;
}

/*
 * This function print the integer array
 * @Param array store number of characters
 * @Return none
 */
void print(const int match[]) {
    
   if (match[0]==-1) {
        cout << "None" << endl;
        return ;
    }
    else {
        int index = 0;
        while(match[index] >= 0) {
            cout << match[index] << endl;
      
            index++;
        }
    }    
} // End of print function 

