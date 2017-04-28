// Authors: Justin James and Chase Breeden
// Date: 11-6-15
// Name: main.cpp
// Description: Houses the user interface where the user enters a choice
//              that choice determines what happend within this program.

#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include "collection.h"
#include "CD.h"
using namespace std;

int main()
{
    int choice = 0;
    collection option;

    //Program will end if 7 is selected
    do {
      cout << "Welcome to the CD Collection Information Database!" << endl;
      cout << "You may select one of the following options:" << endl;
      cout << "1 Read a cd collection from a file" << endl;
      cout << "2 Write the cd collection to a file" << endl;
      cout << "3 Print the cd collection information" << endl;        
      cout << "4 Search for an artist's discography" << endl;
      cout << "5 Search for an album" << endl;
      cout << "6 Remove an artist from the database" << endl;
      cout << "7 Exit this program" << endl;
      cout << "Please enter your choice now: ";
      cin >> choice;

      if(choice!= 7){
      option.menu_choice(choice);
      }
   
    } while(choice != 7);
   
    return 0;
}
