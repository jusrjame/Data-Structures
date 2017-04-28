// Author: Justin James
// Date: 11-20-2016
// Filename: BST.cpp
// Description: Contains the implementation of the public and private functions
//             from the BinarySearchTree class.

#include <iostream>
#include <string>
#include <fstream>
#include "node.h"
#include "BST.h"

using namespace std;

BinarySearchTree::BinarySearchTree(){

  root = NULL;

}


BinarySearchTree::~BinarySearchTree(){

  destructor_helper(root);

}

void BinarySearchTree::destructor_helper(node *current){

  if (current!=NULL){
    // deletes children before deleting current.
    // no memory leak
    destructor_helper(current->left);
    destructor_helper(current->right);
    delete current;
  }

}

void BinarySearchTree::set(string new_key, int new_data){

  // empty list. new node is root 
  if ( root == NULL){
    root = new node(new_key);
    root->data = new_data;
  }
  else
    set_helper(root, new_key, new_data);

}

void BinarySearchTree::set_helper(node *current, string new_key, int new_data){
 
  if( new_key < current->key){
    // the new node is now currents left child
    if(current->left == NULL){
      current->left = new node(new_key);
      current->left->data = new_data;
    }
    else{
      // keep looking for insertion point 
      set_helper(current->left, new_key, new_data);
    }
 }
 else if(new_key > current->key) {
   // the new node is now currents right child
   if(current->right == NULL){
      current->right = new node(new_key);
      current->right->data = new_data;
    }
   // keep looking for insertion point 
    else{
      set_helper(current->right, new_key, new_data);
    }
 }
 else{
    current->key = new_key;
    current->data = new_data;
  }

}


int BinarySearchTree::find(string key){

  return find_helper(root, key);

}


int BinarySearchTree::find_helper(node *current, string find_key){

  if (current == NULL){
    return 0;
  }
  if (current->key == find_key){
    return current->data;
  }
  else{
    // search left
    if(find_key < current->key){
      return find_helper(current->left, find_key);
    } // search right
    else{
      return find_helper(current->right, find_key);
    }
  }

}


void BinarySearchTree::print(){

  if(root != NULL){
    print_helper(root);
  }
  else{
    cout << "list is empty" << endl << endl;
  }

}

void BinarySearchTree::print_helper(node *current){

  if(current->left != NULL){
    print_helper(current->left);
  }

  cout << "Key: " <<  current->key << endl 
       << "Data: " << current->data << endl <<endl;

  if(current->right != NULL){
    print_helper(current->right);
  }

}

void BinarySearchTree::min(){
 
 if(root != NULL){
    min_helper(root);
  }
  else{
    cout << "List is empty." << endl;
  }

}

void BinarySearchTree::min_helper(node *current){

  if(current->left != NULL){
    min_helper(current->left);
  }
  else{
    cout << "Smallest key: " << current->key << endl 
	 << "Data: " << current->data << endl << endl;
  }

}

void BinarySearchTree::max(){

  if(root != NULL){
    max_helper(root);
  }
  else{
    cout << "List is empty." << endl;
  }

}

void BinarySearchTree::max_helper(node *current){

  if(current->right != NULL){
    max_helper(current->right);
  }
  else{
    cout << "Largest key: " << current->key << endl 
	 << "Data: " << current->data << endl << endl;
  }

}


void BinarySearchTree::read_file(string file_name){
 
  string word;
  int in_data;

  ifstream in_file (file_name.c_str());

  // priming read
  in_file >> word;

  while(in_file){

    // excludes all punctuation marks
    for(unsigned int i = 0; i < word.size(); i++){

        if(ispunct(word[i])){
        word.erase(i--,1);
        }
    }
      // ignores all white space
      if(word != ""){
	//find is used to set the value of the key
	// being read into the tree. 
	// If key exist, get value, add 1 to value, overwrite 
	// if not in the tree, returns 0, add 1 to value, store.
	in_data = find(word) + 1;
	set(word, in_data);
      }

      in_file >> word;
  }

    cout << "Finished reading file" << endl;
    in_file.close();

}

void BinarySearchTree::save_file(std::string file_name){

  ofstream out_file;

  out_file.open(file_name.c_str());
  save_Helper(root, out_file);
  out_file.close();

  cout << "Done saving file. " << endl << endl;

}

void BinarySearchTree::save_Helper(node *current, ofstream &out_file){
 
 if (current == NULL){
    return;
  }
  else{
    // recursively saves the contents in ascending order
    save_Helper(current->left, out_file);
    out_file << current->key << " : " << current->data << endl;
    save_Helper(current->right, out_file);
  }

}

void BinarySearchTree::delete_node(std::string deleteKey){

    delete_helper(root,deleteKey);
    cout << endl;

}

void BinarySearchTree::delete_helper(node *current, std::string key){

  if(root != NULL){

    // remove root
    if (root->key == key){
      remove_root();
    }
    else{
      // look at the left child if there is a left child
      if(key < current->key && current->left != NULL){

	if(current->left->key == key){
	  remove_node_match(current, current->left, true);
	}
	else{
	  delete_helper(current->left, key);
	}

      }
      // look at the right child if there is right child
      else if(key > current->key && current->right != NULL){

	if(current->right->key == key){
	  remove_node_match(current, current->right, false);
	}
	else{
	  delete_helper(current->right, key);
	}

      }
      // key was not found
      else{
	cout << "Key was not found" << endl;
      }
    }
  }
  else{
    cout << "Tree is empty." << endl;
  }

}


void BinarySearchTree::remove_root(){

  node *del_ptr = root;

  // case 1: 0 children
  if(root->left == NULL && root->right == NULL){
    root = NULL;
    delete del_ptr;
  }
  // case 2: one child, right
  else if(root->left == NULL && root->right != NULL){
    root = root->right;
    delete del_ptr;
  }
  // case 3: one child, left
  else if(root->left != NULL && root->right == NULL){
    root = root->left;
    delete del_ptr;
  }
  // case 4: 2 children
  else{
    string new_key;
    int new_value;
   
    //stores the appropriate values in order to over write
    //the root being deleted with the new root
    smallest_in_right_subtree(new_key, new_value, root->right);
    delete_helper(root, new_key);

    root->key = new_key;
    root->data = new_value;
  }

}

void BinarySearchTree::remove_node_match(node *parent, node *match, bool left){
 
 // case 1: 0 children.
  if(match->left == NULL && match->right == NULL){
    if(left){
      parent->left = NULL;
    }
    else{
      parent->right = NULL;
    }
    delete match;
  }
  // case 2: one child, right.
  else if(match->left == NULL && match->right != NULL){
    if(left){
      parent->left = match->right;
    }
    else{
      parent->right = match->right;
    }
    match->right = NULL;
    delete match;
  }
  // case 3: one child, left
  else if(match->left != NULL && match->right == NULL){
    if(left){
      parent->left = match->left;
    }
    else{
      parent->right = match->left;
    }
    match->left = NULL;
    delete match;
  }
  // case 4: 2 children
  else{
    string replacement_key;
    int replacement_value;

    // populate variables with appropriate info
    smallest_in_right_subtree(replacement_key, replacement_value, match->right);
    // deletes the node after copying its key and value
    delete_helper(match, replacement_key);

    match->key = replacement_key;
    match->data = replacement_value;
  }

}

void BinarySearchTree::smallest_in_right_subtree(string &new_key, int &new_value, node *current){

   if(current->left != NULL){
     smallest_in_right_subtree(new_key, new_value, current->left);
  }
  else{
    new_key = current->key;
    new_value = current->data;
  }

}



