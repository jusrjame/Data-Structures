// Author: Justin James
// Date: 10-21-2015
// File Name: main.cpp
// Description: houses the driver for the user interface which calls functions
// from the phonebook class based off user input.

#include <iostream>
#include <fstream>
#include <string>
#include "Phonebook.h"

using namespace std;

int main()
{
    int choice;
    string file_name, first_name, last_name, phone_number;
    Phonebook contacts;

    // loops until user chooses to exit the program
    do{

       cout << "Welcome to the UTM phonebook! You may select one of the following options:" << endl
            << " 1: Add contact." << endl
            << " 2: Read a phonebook from a file." << endl
            << " 3: Write the phonebook to a file." << endl
            << " 4: Print the phonebook." << endl
            << " 5: Search for a user's phone number." << endl
            << " 6: Reverse lookup by phone number." << endl
            << " 7: Delete a user." << endl
            << " 8: Exit this program." << endl
            << endl;

       cout << "Please enter your choice now: ";
       cin >> choice;
       cout << endl;

       if(choice == 1){
            Entry *contact = new Entry;

            cout << "Enter new contact's first name: ";
            cin >> contact->first_name;

            cout << "Enter new contact's last name: ";
            cin >> contact->last_name;
            cin.ignore();

            cout << "Enter contact's phone number:";
            getline(cin, contact->phone_number);
            cout << endl;

            contacts.insert_sorted(contact);
       }
       else if(choice == 2){
            cout << "Enter file name to open: ";
            cin >> file_name;
            contacts.read_from_file(file_name);
       }
       else if(choice == 3){
            cout << "Enter the name of the file you would like to save to (xxxxxx.txt): " ;
            cin >> file_name;
            contacts.write_to_file(file_name);
       }
       else if(choice == 4){
            contacts.print();
       }
       else if(choice == 5){
            cout << "Enter contact's last name to look up number: (Case sensitive)";
            cin.ignore();
            getline(cin, last_name);
            cout << endl;

            contacts.lookup(last_name);
       }
       else if(choice == 6){
            cout << "Enter contact's phone number to look up info (ex. xxx-xxx-xxxx): ";
            cin.ignore();
            getline(cin, phone_number);
            cout << endl;

            contacts.reverse_lookup(phone_number);
       }
       else if(choice == 7){
            cout << "Enter the last name of the user you want to delete: (Case sensitive) ";
            cin >> last_name;
            contacts.delete_user(last_name);
            cout << endl;
       }
       else if(choice == 8){
            cout << "exiting program!" << endl;
       }
       else{
            cout << "not a valid choice, please choose again." << endl
            << endl;
       }

       // will clear the fail state of std cin
       // if user tries to input an incorrect type
       // .....because they will.
       if(cin.fail()){
            cin.clear();
            cin.ignore(100, '\n');
       }

    }while(choice != 8);

    return 0;
}
