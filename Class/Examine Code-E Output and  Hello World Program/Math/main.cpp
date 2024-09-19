/* 
 * File: main.cpp
 * Author: Khadiza Akter
 * Created on August 29, 2024, 9:45 am
 * Purpose: Testing output formatting.
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    int aNum = 0;
    int bNum = 0;
    int cNum = 0;
   
    //Initialize or input data here
    cin >> aNum;
    cin >> bNum;
    cin >> cNum;
    
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here and display
    cout << "A + B is: " << (aNum + bNum) << endl;
    cout << "B + A - C is: " << (bNum + aNum - cNum) << endl;
    cout << "(A + B) * C is: " << ((aNum + bNum) * cNum) << endl;
    cout << "(A / B) * C is: " << ((aNum / bNum) * cNum) << endl;
    cout << "(A * C) / B is: " << ((aNum * cNum) / bNum) << endl;
    cout << "A % B is: " << (aNum % bNum) << endl;

    
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}
