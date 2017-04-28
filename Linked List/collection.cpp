;// Authors: Justin James and Chase Breeden
// Date: 11-6-15
// Name: collection.cpp 
// Description: Houses the implementation of function prototypes from
//              the collection class located in collection.h

#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include "collection.h"
#include "CD.h"

using namespace std;

// no need to initilaize anything on creation
collection::collection() {
 
}

collection::~collection() {
  
}


void collection::menu_choice(int choice) {

    string file_name;
    string name, album_title, delete_album;

    //Calls function based on menu choice
    if (choice == 1) {
      cout << endl;
      cout << "Please enter file name of collection: ";
      cin >> file_name;
      read_from_file(file_name);
    }

    else if(choice == 2) {
      cout << endl;
      cout << "Please enter a file name to copy the collection to: ";
      cin >> file_name;
      write_to_file(file_name);
      
    }

    else if(choice == 3) {
      print();
    }

    else if(choice == 4) {
      cin.ignore();
      cout << endl;
      cout << "Please enter the artist's name: ";
      getline(cin, name);
      find_artist(name);
    }

    else if(choice == 5) {
      cin.ignore();
      cout << endl;
      cout << "Please enter the name of the album: ";
      getline(cin, album_title);
      find_album(album_title);
    }

    else {
      cin.ignore();
      cout << endl;
      cout << "Please enter the name of the person you would ";
      cout << "like to remove: ";
      getline(cin, name);
     
      album_delete(name);
      print();
    }
}

void collection::read_from_file(string file_name) {
    
    ifstream input;
   
    input.open(file_name.c_str());
    //Reads in information to variables
    if(input.is_open()) {

      while(input.good()){
	
	cd info;
	getline(input, info.artist);
	getline(input, info.title);
	input >> info.total_tracks;
	input >> info.year;
	input >> info.price;
	input.ignore();
	getline(input, info.genre);
	if (!input.eof()){
	 insert_sorted(info);
	}
      }
	
      
      cout << "CD Collection read in successfully." << endl;
    }
    
    else {
      cout << endl << "Unable to located file.";
      cout << "Please enter the correct file name." << endl;
    }

    input.close();
    
    cout << endl;

}

void collection::write_to_file(string file_name){
 
  ofstream output;
  output.open(file_name.c_str());
  //Writes variable information to file
  if(output.is_open()){
    
    for(it = collect_info.begin(); it != collect_info.end(); it++) {
      output <<  it->artist << endl;
      output <<  it->title << endl;
      output <<  it->total_tracks << endl;
      output <<  it->year << endl;
      output <<  it->price << endl;
      output << it->genre << endl;
    }
  }

  //Error message if file cannot be opened
  else{
    cout << "Unable to write to file.  Please try again." << endl;
    cout << endl;
    
    return;
  }
  
  output.close();
  
  cout << "CD Collection has successfully been written to: "\
       << file_name << endl;
  cout << endl;
  
}

void collection::album_delete(string artist_name) {

  char choice;

    it = collect_info.begin();
    
    // find album to delete
    while (it->artist  != artist_name && it != collect_info.end()) {
      it++;
    }

    if (it != collect_info.end()){
  
      cout << "Album Title: " << it->title << endl;
      cout << "Delete this album by " << artist_name << ": (y/n)" << endl;
      cin >> choice;
      
      // makes sure the user wants to delete this artist 
      if(choice == 'y'){
	collect_info.erase(it);
      }
    }
}

void collection::find_artist(string artist_name){

 
  it = collect_info.begin();

  // search for artist 
  while(it->artist != artist_name && it != collect_info.end()){
    it++;
  }

  if (it != collect_info.end()){
    // will print out all of the artist's info for each album if
    // there is more than one album in the list by the same artist
    do{
      cout << "Artist Name: " << it->artist << endl;
      cout << "Album Title: " << it->title << endl;
      cout << "Number of Tracks: "<< it->total_tracks << endl;
      cout << "Date Released: " << it->year << endl;
      cout << "Price of Album: " << it->price << endl;
      cout << "Album Genre: " << it->genre << endl;
      cout << endl;

      it++;

    }while(it->artist == artist_name);
  }
}
 
void collection::find_album(string album_title){
 
  it = collect_info.begin();

  // search for album
  while(it->title != album_title && it != collect_info.end()){
    it++;
 }

  if (it != collect_info.end()){
    cout << "Artist Name: " << it->artist << endl;
    cout << "Album Title: " << it->title << endl;
    cout << "Number of Tracks: "<< it->total_tracks << endl;
    cout << "Date Released: " << it->year << endl;
    cout << "Price of Album: " << it->price << endl;
    cout << "Album Genre: " << it->genre << endl;
    cout << endl;
  }
}


void collection::print(){
 
  cout << endl;
  cout << "Collection Database: " << endl;
  for(it = collect_info.begin(); it != collect_info.end(); it++) {
      cout << "Artist Name: " << it->artist << endl;
      cout << "Album Title: " << it->title << endl;
      cout << "Number of Tracks: "<< it->total_tracks << endl;
      cout << "Date Released: " << it->year << endl;
      cout << "Price of Album: " << it->price << endl;
      cout << "Album Genre: " << it->genre << endl;
      cout << endl;
  }

}


void collection::insert_sorted(cd info){

  it = collect_info.begin();
  while (it != collect_info.end() && info.artist > it->artist){
    it++;
  }
  
  collect_info.insert(it,info);

}



  



