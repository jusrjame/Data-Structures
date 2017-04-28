// Authors: Justin James and Chase Breeden
// Date: 11-6-15
// Name: collection.h
// Description: Houses the member variables and prototypes for the collection class

#ifndef COLLECTION_H
#define COLLECTION_H
#include <list>
#include "CD.h"

using namespace std;

class collection {

     private:
  list<cd> collect_info;
  list<cd>::iterator it;
  

    public:
        collection();
        /* Description:
         *    Default constructor.
         *
         * Post-conditions:
         *    N/A
         */

        ~collection();
        /*  Description:
         *    Destructor.  Deallocates any dynamic memory
         *
         * Postconditions:
         *    head has been deallocated.
         */

        void read_from_file(string file_name);
        /* Description:
         *    Opens initial file requested by using file_name and reads 
         *    file into a struct. The struct is then pushed to the list.
         *    
         *
         * Parameters:
         *    file_name - The name of the file to be opened.
         *
         * Postconditions:
         *    Initial file has been opened and contents have been read into
         *    artist, title, total_tracks, year, price, and genre. 
         */

        void write_to_file(string file_name);
        /* Description:
         *    Creates output file by using file_name and writes
         *    collection to file.
         *
         * Parameters:
         *    file_name - The name of the file to be opened/created.
         *
         * Postconditions:
         *    File has been opened/created and the contents of the struct
         *    have been printed to the file.
         */

        void insert_sorted(cd info);
        /* Description:
         *    Sorts the list alphabetically by last name in the list.
         *
         * Parameters:
         *    info - cd object that contains the contents of the struct.
         *
         * Postconditions:
         *    List has been sorted and arranged by the Artist name.
         *    
         */

        void find_artist(string artist_name);
        /* Description:
         *    Enables user to lookup an artist's discography by searching
         *    through collection by the artist's name.
         *
         * Parameters:
         *    artist_name - The name of the artist to be searched for.
         *
         * Postconditions:
         *      The information has been located and printed to
         *      the terminal.
         */

        void find_album(string album_name);
        /* Description:
         *    Enables the user to search for an artist by
         *    entering the name of an album.
         *
         * Parameters:
         *    album_name - The album name used to search for the person.
         *
         * Postconditions:
         *    The information has been located and printed to
         *    the terminal.
         */

        void print();
        /* Description:
         *    Calls the print helper method.
         *
         *
         * Parameters:
         *    N/A
         *
         * Postconditions:
         *    The print helper function has been called
         *    with the pointer to print out collection contents.
         */

        void album_delete(string artist_name);
        /* Description:
         *    Deletes the desired information by searching
         *    for the artist.
         *
         * Parameters:
         *    artist_name - The name of artist to be deleted.
         *    album_name - The name of the album to be deleted.
	 *	
         * Postconditions:
         *    The desired information has been deleted and removed
         *    from the contents of the cd collection.
         */


        void menu_choice(int choice);
        /* Description:
         *    Interacts with the driver in main to call perform
         *    the requested actions.
         *
         * Parameters:
         *    choice - The choice inputted by the user.
         *
         * Postconditions:
         *    The requested action has been performed by
         *    calling the correlating method.
         */


};

 
#endif // COLLECTION_H
