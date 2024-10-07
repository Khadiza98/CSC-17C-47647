/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on September 22, 2024, 11:44 AM
 * Purpose: Calculate the slope and intercept of the first order equation 
            y=mx+b  ->  deg_c = m * deg_f + b. Input the file data, output
            the unknown slope and intercept.
 */
//System Libraries
#include <iostream>   // Input/Output Library
#include <iomanip>    // Needed for output formating
#include <fstream>    // Needed for read in file
#include <vector>     // Needed to work with vector


using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void calcSlopeInt(const vector<float>&, const vector<float>&, float&, float&);
bool readInFile(vector<float>&, vector<float>&);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    //Declare variables here
    float slope = 0.0f;        // To hold the calculated slope value
    float intercept = 0.0f;     // To hold the calculated intercept value
    vector<float> degF;         // Vector to hold Fahrenheit (x) values
    vector<float> degC;         // Vector to hold Celsius (y) values

    if (!readInFile(degF, degC))// Read data from file
        return 1;               // Exit if file fail to read in
    
    // Calculate slope and intercept
    calcSlopeInt(degF, degC, slope, intercept);
    
     // Output the results
    cout << fixed << setprecision(4);
    cout << "Calculated Slope (m) = " << slope << endl;
    cout << "Calculated Intercept (b) = " << intercept << endl;
    
    // Exit the program
    return 0;
}
//****************************************************************
// Definition of calcSlopeInt function. This function calculate 
// slope (m) and intercept (b) using least squares formula.
// Use 2 float array x for degF, y for degC, slope and 
// intercept as @param. All parameter pass by reference.
//****************************************************************
void calcSlopeInt(const vector<float>& degF, const vector<float>& degC, float &m, float &b) {
    int i;                              // loop counter variable
    int length = degF.size();           // Number of data points
    float sum_X = 0.0f, sum_Y = 0.0f, 
          sum_XY = 0.0f, sum_X2 = 0.0f; // To hold the summations
    
    // Loop to calculate the sums needed for the formulas
    i = 0;
    while (i < length){
        sum_X += degF[i];               // Sum of Fahrenheit values
        sum_Y += degC[i];               // Adding up Celsius values 
        sum_XY += degF[i] * degC[i];    // Adding up x * y
        sum_X2 += degF[i] * degF[i];    // Adding up x * x
        i++;                            // Update condition
    }
   
    m = (sum_X * sum_Y - length * sum_XY) /
        (sum_X * sum_X - length * sum_X2);// Compute slope(m)
    b = (sum_Y - m*sum_X) / length;      // Compute intercept (b)
    
}
//****************************************************************
// Definition of readInFile function. This function 
// read Fahrenheit and Celsius data from a file.
// Use 2 float array x for degF, y for degC @param.
// @return boo-lean value
//****************************************************************
bool readInFile(vector<float>& degF, vector<float>& degC) {
    float x = 0.0f,                        // To read in Fahrenheit value
          y = 0.0f;                        // To read in Celsius value
    ifstream inFile("degC_degF_Data.txt"); // open the file
    if (!inFile.is_open()) {               // check if file opened 
        cout << "Error opening file!\n";
        return false;                      // Return false if file fail to open
    }
    while (inFile >> x >> y) {             // Read file line by line
        degF.push_back(x);                 // Store x value into degF vector
        degC.push_back(y);                 // Store y value into degC vector
    }
    inFile.close();                        // Close the file
    return true;                           // Return true when read in file successful
}