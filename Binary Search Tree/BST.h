// Author: Justin James
// Date: 11-20-2015
// Filename: BST.h
// Description: Houses functions and member variables of the BinarySearchTree class

#ifndef BST_H
#define BST_H

class BinarySearchTree{
 private:

  node *root;

  void destructor_helper(node *current);
  // Desription: Helper function which is called automatically at the end of the program
  //             to delete contents of the tree
  // Params: node *current - a pointer to a node in the tree
  // Return: void

  void set_helper(node *current, std::string key, int data);
  // Desription: A recursive function to set a nodes's variables accordingly and puts it in the
  //             in the appropriate place within the tree
  // Params: node *current
  // Return: void

  void print_helper(node *current);
  // Desription: A recursive function which prints the content of the tree in ascending order
  // Params: node *current - a pointer the current node in the tree
  // Return: void

  void min_helper(node *current);
  // Desription: A recursive function which seeks out the smallest value in the tree and
  //             and prints that info to the screen
  // Params: node *current - pointer to the current node in the tree
  // Return: void

  void max_helper(node *current);
  // Desription: A recursive function which seeks out the largest value in the tree
  //             and prints that info to the screen
  // Params: node *current - pointer to the current node in the tree
  // Return:    void

  int find_helper(node *current, std::string find_value);
  // Desription: A recursive function which fins a specific key in the tree and
  //             and returns the value of that key
  // Params: node *current - a pointer to the current position in  the tree
  //         std::string fine_value - the value which the user wants to find
  // Return: int - the value of the specific key in question

  void save_Helper(node *current, std::ofstream &out_file);
  // Desription: A recursive function which stores the contents of the tree to a file
  //             specified by the user.
  // Params: node *current - pointer to the current node in the tree
  //         std::ofstream &out-file - reference to an out file stream
  // Return: void


  /** Function used for deletion  **/
  void delete_helper(node *current, std::string key);
  // Desription: A recursive function which calls other helper function in order to remove
  //             a node from the tree.
  // Params: node *current - pointer to the current location in the tree
  //         std::string key - the node's key to delete
  // Return: void

  void remove_root();
  // Desription: A recursive function which is called on by the delete_helper to remove
  //             the root of the tree
  // Params: none
  // Return: void

  void remove_node_match(node *parent, node *match, bool left);
  // Desription: A recursive function which removes a node of a tree that is not the root
  // Params: node *parent - a pointer the parent of the node to delete
  //         node *match - a pointer to the node to delete
  //         bool left - boolean statement to differentiate between the right and left child
  //         of a node.
  // Return: void

  void smallest_in_right_subtree(std::string &new_key, int &new_value, node *current);
  // Desription: a recursive function which helps the remove root function. This function
  //             finds the smallest value in the current nodes right tree, copies the values
  //             of that particular node into variables to be used in the calling function.
  // Params: std::string &new_key - a reference to a modifiable variable
  //         int &new_value - a reference to a modifiable variable
  //         node *current - pointer to the current position in the tree
  // Return: void


 public:

  BinarySearchTree();
  // Desription: Default constructor of the BST class. Sets the root pointer to NULL
  // Params: none
  // Return: none

  ~BinarySearchTree();
  // Desription: Default destructor of the BST class. Deallocates all memory for the tree
  // Params: none
  // Return: none

  void set(std::string key, int data);
  // Desription: Calles the set_helper function in order to set a nodes variables accordingly
  // Params: std::string key - the key to store in the tree
  //         int data - the data associated with that key
  // Return: void

  int find(std::string key);
  // Desription: Calles find_helper to find the specified key's value
  // Params: std::string key - key to find
  // Return: int - key's value

  void print();
  // Desription: Calls print_helper to print the contents of the tree to the screen
  // Params: none
  // Return: void

  void min();
  // Desription: Calls min_helper to find the smallest key in the tree
  // Params: none
  // Return: void

  void max();
  // Desription: Calls max_helper to find the largest key in the tree
  // Params: none
  // Return: void

  void read_file(std::string file_name);
  // Desription: read in a text file and stores the contents of that text file in the tree
  //             ignoring punctuation and whitespace
  // Params: std::string file_name - name of the file to read from
  // Return: void

  void save_file(std::string file_name);
  // Desription: calls save_helper to save the contents of the tree in the specified filename
  // Params: std::string file_name - name of the the file to write to
  // Return: void

   void delete_node(std::string key);
  // Desription: A function which calls delete_helper in order to delete a node from the tree
  // Params: std::string key - key to delete
  // Return: void

};

#endif
