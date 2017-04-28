// Author: Justin Jamesxs
// Date: 10-21-15
// File Name: Phonebook.h
// Description: Houses the phonebook class which includes the class' member
// variables and function prototypes. Contains a strut called Entry which
// holds pertinent info that is stored within the phonebook class.

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

using namespace std;

struct Entry{
    Entry *next;
    string first_name, last_name, phone_number;
};

class Phonebook
{
    public:

        Phonebook();
	// Description: default constructor, sets size = 0 and head = NULL
	//              when phonebook object is created.
	// Param: None
	// Return: None

        ~Phonebook();
	//  Description: Recursively traverses the list and deletes each element
	// Param: None
	// Return: None

        void push_front(Entry *contact);
	// Description: will make Entry *contact the new head of the list
	//              the implementation is different depending on if the
	//              list is empty or currently populated
	// Param: Entry *contact - pointer to an Entry struct
	// Return: void

        void push_back(Entry *contact, Entry *insertion_point);
	// Description: adds the new struct to the end of this list.
	//              Traversing the list to find the end is already
	//              done from the insert_sorted function and the
	//              pointer to this location is passed to this function
	//              in order to add Entry *contact to the correct position
	// Param: Entry *contact, Entry *insertion_point - pointer to an entry
	//        struct and a pointer to the end of the list 
	// Return: void

        void read_from_file(string file_name);
	// Description: Reads contact's fist name, last name and phone number
        //              from a file and stores this info inside of a struct.
	//              Insert_sorted() is then called on the struct that houses
	//              the info
	//  Param: string file_name - the name of the file to read from
	//  Return: void

        void write_to_file(string file_name);
	// Description: The user will designate a file name to write their sorted list to.
	//              Once that step happens this function  will open the file,
	//              check for precaution, the write the information in the same
	//              format in which it was read.
	// Param: string file_name - name of the file to write to
	// Return: void

        void insert_sorted(Entry *contact);
	// Description: After a struct is filled with the info read from
	//              or enter by the user, insert_sorted() adds the contact
	//              to the list in alphabetical order based on the last name.
	//              This function calls push_back and push_front if certain
	//              conditions are met in order add the contact to the list.
	//              Examples of these conditions are: empty list, contact
	//              is new head of list or contact is at the end of the list
	// Param: Entry *contact - pointer to a struct
	// Return: void

        void lookup(string last_name);
	// Description: traverses the list in search of the contacts
	//              information to display.  Once the last name of the
	//              user is found, the contacts information is printed out
	//              to the console.
	// Param: string last_name - last name of the contact the user wants the info for
	// Return: void

        void reverse_lookup(string number);
	// Description: traverses the list in search of the contacts
	//              information to display.  Once the phone number of the
	//              user is found, the contacts information is printed out
	//              to the console.
	// Param: string number - the phone number of the contact the user wants info for
	// Return: void

        void delete_user(string last_name);
	// Description: traverses the list until the last name passed into
	//              the function matches the last name of a contact
	//              in the list. the implementation of this function depends
	//              on where the contact is located within the list. Once found
	//              delete is called on that contact, thus removing the contact
	//              from the list
	// Param: string last_name - the last name of the contact the user wants to delete
	// Return: void

        void print();
	// Description: Calls print helper to print the contents of the list
	//              to std output in the console. Will not print an empty list.
	// Param: None
	// Return: void


    private:

        int size;
        Entry *head;

        void print_helper(Entry *current);
	//Description: Helper function for standard print function. Uses recursion
	//             to traverse list and print contents of each struct until
	//             current == NULL.
	// Param: pointer to a struct named Entry (Entry *contact)
	// Return: void

        void destructor_helper(Entry *contact);
	// Description: Helper function for the destructor. Traverses the list, deleting
	//              each contact until the end of the list is reached.
	// Param: Entry *contact - a pointer to the head of the list
	// Return: void

};

#endif // PHONEBOOK_H
