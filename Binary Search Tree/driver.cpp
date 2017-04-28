// Author: Justin James
// Date: 11-20-2015
// Filename: driver.cpp
// Description: A file which houses the driver for the program.
//              This driver enables the user to use interact with the
//              binary search tree.

#include <iostream>
#include <string>
#include <fstream>
#include "node.h"
#include "BST.h"

using namespace std;

int main(){

  BinarySearchTree tree;
  int choice, value;
  string file_name, key;

  do{
    cout << "Welcom to the best text analyzer ever. Please choose form the options below. Type 0 to exit. " << endl
	 << " 1. Read data froma file." << endl
	 << " 2. Store a key and its value in the tree. " << endl
	 << " 3. Search for a key's value. " << endl
	 << " 4. Print data. " << endl
	 << " 5. Print the smallest value. " << endl
	 << " 6. Print the lasrgest value. " << endl
	 << " 7. Save data to a file. " << endl
	 << " 8. Delete a key and value. " << endl << endl;
    cout << "Enter choice: ";
    cin >> choice;
    cout << endl;

    if(choice==1){
      cout << "Enter the filename to open: ";
      cin >> file_name;
      tree.read_file(file_name);
    }
    else if(choice==2){
       cout << "Enter the key and value to store:" << endl;
       cout << "Key: ";
       cin >> key;
       cout << "Value: ";
       cin >> value;

       tree.set(key, value);
       cout << endl;
    }
    else if(choice==3){
      cout << "Enter the key to find its value: ";
      cin >> key;
      if(tree.find(key) > 0){
	cout << endl
	     << key << "'s value is: " << tree.find(key) << endl << endl;
      }
      else{
	cout << " Key is not in the tree search again. " << endl << endl;
      }
    }
    else if(choice==4){
      tree.print();
    }
    else if(choice==5){
      tree.min();
    }
    else if(choice==6){
      tree.max();
    }
    else if(choice==7){
      cout << "Enter the filename to save to: ";
      cin >> file_name;
      tree.save_file(file_name);
    }
    else if(choice == 8) {
      cout << "enter the key to delete: ";
      cin >> key;
      tree.delete_node(key);
    }
    else if (choice == 0){
      cout << "Exiting program. " << endl;
    }
    else{
      cout << " Invlaid choice. Please chose again. " << endl << endl;
    }

  }while(choice != 0);

  return 0;

}
