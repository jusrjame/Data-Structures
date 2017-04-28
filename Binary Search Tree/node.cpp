// Author: Justin James
// Date: 11-20-2015
// Filename: node.cpp
// Description: Contains the implementation of the public functions
//              of the node class

#include <iostream>
#include <string>
#include "node.h"
#include "BST.h"

using namespace std;

node::node(string key_value){
  key = key_value;
  data = 0;
  left = NULL;
  right = NULL;
}

