 /*
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on September 1, 2024, 10:53 PM
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

 //System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
#include <cmath> // pow()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char[], unsigned short&);//Output true,unsigned or false
bool  reverse(unsigned short, signed short&);//Output true,short or false
short subtrct(signed short, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE = 80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short

    //Input or initialize values Here
    cout << "Reverse a number and subtract if possible." << endl;
    cout << "Input a number in the range of an unsigned short" << endl;
    cin >> digits;

    //Test if it is in the Range of an unsigned short
    if (!inRange(digits, unShort)) {
        cout << "No Conversion Possible" << endl;
        return 0;
    }

    //Reverse and see if it falls in the range of an signed short
    if (!reverse(unShort, snShort)) {
        cout << "No Conversion Possible" << endl;
        return 0;
    }

    //Now subtract if the result is not negative else don't subtract
    snShort = subtrct(snShort, 999);

    //Output the result
    cout << snShort << endl;

    //Exit
    return 0;
}
bool  inRange(const char digits[], unsigned short& unShort) {
    int len = strlen(digits);                                   //take the length of digits array
    int val = 0, p = 0;
    char c;
    const unsigned short UNSHRT_MAX = 65335;
    for (int i = len-1; i >= 0; i--)  {                         // loop through digits array for converting the number
        if (digits[i] >= '0' && digits[i] <= '9')  {            // check the digits in between 0 to 9
            val = val + pow(10, p)*(digits[i] - '0');           // Coverting each digits for its number value; example input is 12; then 10^0*2=2 
                                                                // and next iteration 10^1*1=10; summation of 2+10=12
            p = p + 1;                                          // increment power of 10 value
        }
        else            return false;                           // if not a digit then return false
    }
    if (val > UNSHRT_MAX || val < 0) {                           // if it is out of bound for unsigned int then return false
        return false;
    }
    else {                                                      
         unShort = val;                                         // set the value for unshort
         return true;
    }
   
} // End of inRange Function

bool  reverse(unsigned short unShort, signed short& snShort) {
    int index = 0, p = 0, val = 0, digit[80], diff =0;
    const signed short SHRT_MAX = 32767;        //Maximum range of signed short
    const signed short SHRT_MIN = -32768;       //Minimum range of signed short
    //reverse the digit
    while (unShort != 0) {
        digit[index] = unShort % 10;            // extract the last digit
        unShort = unShort / 10;                 // remove the last digit
        index++;
    } // End of loop
    if(index <=5) diff = 5-index;               // check the number of digit; if it is less than 5 then take difference of it
        
    for (int i = index - 1; i >= 0; i--) {      // loop through digit to convert the number
       val = val + pow(10, p+diff) * (digit[i]);            
       p = p + 1;
        
    }
    if (val > SHRT_MAX || val < SHRT_MIN) return false; // check the reverse number out of bound the signed short range
    else {
        snShort = val;                                  // if it is short range then set the value at snShort
        return true;                                    // returm true
    }
} // End of reverse function

short subtrct(signed short snShort, int subsNum) {
    if (snShort - subsNum >= 0)   // subtract the number from 999; if positive then return subtraction result
        return snShort - subsNum;
    else  return snShort;         // otherwise return the number without substraction

} // End of subtrct function
