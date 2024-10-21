/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 8th, 2024
 * Purpose: This program shows how to use STL containers and algorithms to
 *      handle and organize data more easily. Instead of using regular arrays
 *      and sorting methods, it uses STL containers like list and pair, 
 *      along with algorithms like sort.
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time to set the random number seed
#include <algorithm> //For sort
#include <list>      //For list container
#include <utility>   //For pair container
#include <iomanip>   //For formatted output

using namespace std;

//Function Prototypes
void printArray(const list<pair<int, int>>& lst, int perLine);
void sort(list<pair<int, int>>& lst);

//Execution of Code Begins Here
int main() {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));

    //Declare all variables
    int size = 160;
    int perLine = 16;
    
    //Create a list of pairs: <data, index>
    list<pair<int, int>> dataList;
    
    //Initialize the list with random values
    for (int i = 0; i < size; ++i) {
        dataList.push_back(make_pair(rand() % 90 + 10, i)); // 2-digit random values with index
    }

    //Display before sorting
    cout << "Before Sorting:" << endl;
    printArray(dataList, perLine);

    //Sort the list by the first element of the pair (the data)
    sort(dataList);

    //Display after sorting
    cout << "After Sorting:" << endl;
    printArray(dataList, perLine);

    return 0;
}

//Function to print the array (in list form)
void printArray(const list<pair<int, int>>& lst, int perLine) {
    int count = 0;
    cout << fixed << setw(4);
    for (const auto& elem : lst) {
        cout << elem.first << " ";  // print the data
        if (++count % perLine == 0) cout << endl;
    }
    cout << endl;
}

//Function to sort the list of pairs by the data value (first element in pair)
void sort(list<pair<int, int>>& lst) {
    lst.sort([](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first; // Compare by the data value (not index)
    });
}
