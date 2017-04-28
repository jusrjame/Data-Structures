// Justin James
// 09/16/15
// Vector.h
// Holds the vector class declaratation and function prototypes 

#ifndef VECTORS_H
#define VECTORS_H

#include <iostream>
using namespace std;

class Vector{
 public:

  Vector();
 /* Description:  Default constructor. Initializes and empty vector. */
 /* Pre-conditions: n/a */
 /* Post-consitions:  vec_ptr is NULL, vec_sise=0, and vec_capacity=0. */
 /* Parameters: none */
 /* Return value: none */
  
   ~Vector();
  /* Description: deconstructor */
  /* Pre-conditions: object created */
  /* Post-consitions: object destroyed */
  /* Parameters: none */
  /* Return value: none */

  int size();
 /* Description: Gets size of array. */
 /* Pre-conditions: object created */
 /* Post-consitions: n/a */
 /* Parameters: none */
 /* Return value: int */

   int capacity();
  /* Description: gets the capacity  */
  /* Pre-conditions: object created */
  /* Post-consitions: n/a */
  /* Parameters: none */
  /* Return value: int */

  void push_back(int element);
  /* Description: adds an interger into the array  */
  /* Pre-conditions: an element needs to be added to array */
  /* Post-consitions: element is added, array may be doubled in capacity, size++ */
  /* Parameters: int element, number to be added to array */
  /* Return value: none */

  void reserve(int n);
  /* Description: reserves space for array */
  /* Pre-conditions:  */
  /* Post-consitions: capacity is now capacity + n */
  /* Parameters: int n, number of spaced to reserve */
  /* Return value: none */

  int& operator[](unsigned int index);
 /* Description: overloads the [] to act like arrat indices */
 /* Pre-conditions: index must be a positive interger */
 /* Post-consitions: n/a */
 /* Parameters: unsinged int */
 /* Return value: int& */

 private:

  int *vec_ptr;
  int vec_size, vec_capacity;

};

#endif
