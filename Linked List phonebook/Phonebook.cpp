// Author: Justin James
// Date: 10-21-15
// File Name: Phonebook.cpp
// Description: Houses the implementation and necessary comments for function
// prototypes from the Phonebook class, which is located inside the phonebook.h file.

#include <iostream>
#include <fstream>
#include <string>
#include "Phonebook.h"

using namespace std;

Phonebook::Phonebook(){
    size = 0;
    head = NULL;

}

Phonebook::~Phonebook(){
    destructor_helper(head);
}

void Phonebook::destructor_helper(Entry *current){
    if( current != NULL){
        // deletes from the the end in order to make sure
        // a memory does not happen
        destructor_helper(current->next);
        delete current;
    }
}

void Phonebook::push_front(Entry *contact){

   // push front is called for two instances
   // 1. empty list and 2. populated list.
   // conditionals here are to distinguish
   // between the two instances

   // Case 1.
   if(head != NULL ) {
        contact->next = head;
        head = contact;
        size++;
   }
   // Case 2.
   else{
        contact->next = NULL;
        head = contact;
        size++;
   }

}

void Phonebook::push_back(Entry *contact, Entry *insertion_point){

    // No need to search for the end of the list here.
    // Traversal of list is done in the calling function then
    // a pointer to that location is passed to this function.
    insertion_point->next = contact;
    contact->next = NULL;
    size++;

}

void Phonebook::read_from_file(string file_name){

    ifstream in_file;

    in_file.open(file_name.c_str());

    if(in_file.is_open()){

        // while good get info
        while(in_file.good()){
            Entry *contact = new Entry;
            in_file >> contact->first_name;
            in_file >> contact->last_name;
            in_file.ignore();
            getline(in_file, contact->phone_number);

            // was entering an empty struct into list
            // this remedied that problem.
            if(!in_file.eof()){
                insert_sorted(contact);
            }
        }
        cout << "Read complete." << endl;
    }
    else{
        cout << endl << "Error opening file, try again." << endl;
    }

    in_file.close();

    cout << endl;
}

void Phonebook::write_to_file(string file_name){

    ofstream out_file;
    out_file.open(file_name.c_str());

    // will not write an empty list
    if(out_file.is_open() && size !=0){
        Entry *write = head;

        while(out_file.good() && write != NULL){

            out_file << write->first_name << " " << write->last_name << endl
                     << write->phone_number << endl;

            write = write->next;
        }

        out_file.close();

        // confirmation message
        cout << "Write to " << file_name << " complete." << endl
             << endl;
    }
    else{
            // Error message
        cout << "Error writing to file. Try again." << endl
             << endl;
             out_file.close();
             return;
    }
}

void Phonebook::insert_sorted(Entry *contact){

    // case for empty list or *contact is new head
    if(head == NULL || contact->last_name <= head->last_name){
	push_front(contact);
    }
    // case for a populated list
    else{
        // the contact to be inserted will be inserted after *insertion
    	// based off of *compare's value
    	Entry *insertion, *compare;

        // Does not check head here because that condition has already been addressed
        // the first value to "compare" is the value after head.
        insertion = head;
        compare = head->next;

        // puts insertion and compare in proper places in order to prevent a memory leak
        // within the list
        while(compare != NULL && compare->last_name < contact->last_name ){
            insertion = compare;
            compare = compare->next;
        }

        // reached end of list, use push_back(contact, insertion).
        // insertion acts as a "tail" pointer here that is passed
        // to the push_back() function
        if(compare == NULL){
            push_back(contact, insertion);
        }
        // insertion point found between *insertion and *compare
        else{
            insertion->next = contact;
            contact->next = compare;
        }
    }
}


void Phonebook::lookup(string name){

    Entry *traveler;
    traveler = head;

    while(traveler != NULL && traveler->last_name != name){
        traveler = traveler->next;
    }

    if(traveler != NULL){
        cout << "Name: " << traveler->first_name << " " << traveler->last_name << endl
             << "Phone number: " << traveler->phone_number << endl
             << endl;
    }
    else{
        // error message
        cout << "Error finding contact. Try again." << endl
             << endl;
    }
}

void Phonebook::reverse_lookup(string number){

    Entry *traveler;
    traveler = head;

    while(traveler != NULL && traveler->phone_number != number){
        traveler = traveler->next;
    }

    if(head != NULL){
        cout << "Name: " << traveler->first_name << " " << traveler->last_name << endl
             << "Phone number: " << traveler->phone_number << endl
             << endl;
    }
    else{
        // error message
        cout << "Error finding contact. Try again." << endl
             << endl;
    }
}


void Phonebook::delete_user(string last_name){

    Entry *temp, *eraser;

    // case 1. populated list
    if(head != NULL){

        //1a. the contact in question is the head
        if(head->last_name == last_name){
            eraser = head;
            head = head->next;
           
	    cout << "Deleting: " << eraser->first_name << " " << eraser->last_name << endl
		 << endl;
	    delete eraser;
            size--;
        }
        // 1b. search and destroy
        else{
            temp = head;
            eraser = head->next;

            // stops when contact or end of list is found
            while(eraser != NULL  && eraser->last_name != last_name){
                temp = eraser;
                eraser = eraser->next;
            }

            // once the loop stops, these conditions test to see why the loop stopped
            // and either deletes the contact in question, or returns back to main()
            // with a an error message.
            if(eraser != NULL){
                temp->next = eraser->next;
		
		cout << "Deleting: " << eraser->first_name << " " << eraser->last_name << endl
		     << endl;
                delete eraser;
                size--;
            }
            else{
                cout << "Contact could not be found. No contact was removed." << endl
                     << endl;
            }
        }
    }
    // Case 2. Empty list. Cannot delete a contact from an empty list
    else{
        cout << "List is empty." << endl
             << endl;
    }
}

void Phonebook::print(){

    // will not print an empty list
    if(size == 0){
        cout << "List is empty." << endl
             << endl;
    }
    else
        print_helper(head);
}

void Phonebook::print_helper(Entry *contact){

    // if contact points at a valid struct, print out the info stored there
    if(contact != NULL){
        cout << contact->first_name << " " << contact->last_name << endl
             << contact->phone_number << endl
             << endl;

        print_helper(contact->next);
    }
}


