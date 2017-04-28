// Author: Justin James
// Date: 11-20-2015
// Filename: node.h
// Description: a class declaration of type node that acts like a struct.

#ifndef NODE_H
#define NODE_H

class node{
 public:
  node *left;
  node *right;
  std::string key;
  int data;

 public:
  node(std::string key_value);
  // Desription: parameterized constructor which creates and node and sets the value
  //             within that node upon creation.
  // Params: std::string key - key to store in the new node
  // Return: none

};

#endif
