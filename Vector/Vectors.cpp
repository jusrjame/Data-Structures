// Justin James
// 09/16/15
// Vector.cpp
// Holds the implementation of functions in the vector class.

#include <iostream>
#include "Vectors.h"

using namespace std;

Vector::Vector(){

  vec_capacity=0;
  vec_size=0;
  vec_ptr = new int[vec_capacity];
}

Vector::~Vector(){
  vec_ptr=0;
  vec_capacity=0;
  vec_ptr=NULL;
}

int Vector::size(){
  return vec_size;
}

int Vector::capacity(){
  return vec_capacity;
}

void Vector::push_back(int element){
  // if capacity is 0 then the reserve function will reserve a capacity of 10
  // thus making more room and re-sizing less in the beginning 
  if ( vec_capacity == 0){
    reserve(10);
  }
  // checks if the current size plus one isn't greater than the capacity
  if ( vec_size + 1 > vec_capacity){
    
    // creates a new array with a capacity of vec_capacity*2. Doubling the previous capacity
    int *temp_ptr = new int[vec_capacity*2];

    // copies data from vec_ptr[i] into temp_ptr which is double the capacity of vec_ptr.
    for(int i=0; i < vec_size; i++){
     temp_ptr[i] == vec_ptr[i];
    }
    
    vec_capacity = vec_capacity * 2;

    // deallocates old array
    delete[] vec_ptr;

    // points vec_ptr to new array
    vec_ptr = temp_ptr;
    
    // adds the integer to the end of array
    vec_ptr[vec_size] = element;
  }
  else 
    // adds the integer to the end of the array
    vec_ptr[vec_size] = element;

  vec_size++;
}

      
void Vector::reserve(int n){

  if(n > vec_capacity){
    vec_ptr = new int[vec_capacity + n];
    vec_capacity = vec_capacity + n;
  }
}

int& Vector::operator[](unsigned int index){
  return vec_ptr[index];
}
 




