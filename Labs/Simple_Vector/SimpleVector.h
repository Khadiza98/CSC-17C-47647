/* 
 * File:   SimpleVector.h
 * Author: Khadiza Akter
 * Created on September 15, 2024, 1:48 PM
 * Purpose: SimpleVector class Specification
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <new>       // Needed for bad_alloc exception
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   //Adding 4 functions Push front/back, Pop front/back
   void pshFrnt(T);
   void pshBack(T);
   T popFrnt();
   T popBack();
};

//**********************************************
// Add or push an element to the front of array
//**********************************************
template <class T>
void SimpleVector<T>::pshFrnt(T val)
{
    T *newPtr = new T[arraySize + 1]; // Create a new array with one more element 
    *(newPtr + 0) = val;              // Push the new value to the front
    for (int i = 0; i < arraySize; i++) { // Copy old array elements to new array
        newPtr[i + 1] = aptr[i];
    }
    delete []aptr;              // Delete the old array
    aptr = newPtr;              // Now old array point to the new array
    arraySize++;                // update the array size
}

//**********************************************
// Add or push an element to the back of array
//**********************************************
template <class T>
void SimpleVector<T>::pshBack(T val) {
    T *newPtr = new T[arraySize + 1];// Create a new array with one more element 
    for (int i = 0; i < arraySize; i++) {// Copy old array elements to new array
        newPtr[i] = aptr[i];
    }
    *(newPtr + arraySize) = val;        // Add the new value at the back
    delete []aptr;              // Delete the old array
    aptr = newPtr;              // Now old array point to the new array
    arraySize++;                // update the array size
}
//*******************************************
// This popFrnt function removes an element 
// at the front of the array and return it.                      *
//*******************************************
template <class T>
T SimpleVector<T>::popFrnt(){
    T fValue = aptr[0];     // Store the front value
    T *newPtr = new T[arraySize - 1];// Create a new array with one less element 
    for (int i = 1; i < arraySize; i++) {// Copy old array elements to new array without first element
        newPtr[i - 1] = aptr[i];
    }
    delete []aptr;              // Delete the old array
    aptr = newPtr;              // Now old array point to the new array
    arraySize--;                // update the array size
    
   return fValue;               // Return removed front value
}
//*******************************************
// This popBack function removes an element 
// at the back of the array and return it.                      *
//*******************************************
template <class T>
T SimpleVector<T>::popBack()
{
   T bValue = aptr[arraySize-1];     // Store the last value
    T *newPtr = new T[arraySize - 1];// Create a new array with one less element 
    for (int i = 0; i < arraySize-1; i++) {// Copy old array elements to new array without last element
        newPtr[i] = aptr[i];
    }
    delete []aptr;              // Delete the old array
    aptr = newPtr;              // Now old array point to the new array
    arraySize--;                // update the array size
    
   return bValue;               // Return removed back value
}

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}
#endif



