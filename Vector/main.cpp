// Justin James
// 09/16/15
// main.cpp
// tests vector class for proper functionality

#include <iostream>
#include "Vectors.h"

using namespace std;

int main(){

  Vector vec;

  cout << "Vector has been created." << endl;

  // shows vec.size() works as intended  
  cout << "The size is: " << vec.size() << endl;

  // shoes vec.capacity works as intended
  cout << "The capacity is: " << vec.capacity() << endl;

  // puts 100 elements inside an array and prints it out to std output.
  for(int i = 0; i < 100; i++){
    vec.push_back(i);
    cout << vec[i] << " ";
  }

  cout << endl;

  cout << "The ending size is: " << vec.size() << endl;
  cout << "The ending capacity is: " << vec.capacity() << endl;

  // shows the overloaded operator works for reassigning values
  // as well as retrieval 
  cout << "vec[0]: " << vec[0] << endl;
  vec[0] = 789;
  cout << "vec[0]: " << vec[0] << endl;   

  return 0;
}
