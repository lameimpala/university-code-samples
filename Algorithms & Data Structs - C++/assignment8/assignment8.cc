/*********************************************************************
   PROGRAM:    CSCI 340 Assignment 8
   PROGRAMMER: Reid Wixom
   LOGON ID:   z1693990
   DUE DATE:   04/18/16
 
   Description:   Contains implementaion of HT class defined in assignment8.h
*********************************************************************/ 

#include "assignment8.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/*
Function: 
void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int) )

Arguments: 
pointer reference to integer vector
integer for heap size
integer for index to array
comparison function pointer

Returns:
void

Notes: 
Heapifies an array, at a given index, assuming the index's subtrees are already heapified
*/
HT::HT(int size = 11) {
    hTable = new vector<Entry>(size);
    table_size = size;
    item_count = 0;
}

/*
Function: 
void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int) )

Arguments: 
pointer reference to integer vector
integer for heap size
integer for index to array
comparison function pointer

Returns:
void

Notes: 
Heapifies an array, at a given index, assuming the index's subtrees are already heapified
*/
HT::~HT() {
    delete hTable;
}

/*
Function: 
void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int) )

Arguments: 
pointer reference to integer vector
integer for heap size
integer for index to array
comparison function pointer

Returns:
void

Notes: 
Heapifies an array, at a given index, assuming the index's subtrees are already heapified
*/
bool HT::insert(const Entry &e) {
    int index = hashing(e.key);
 
    if(search(e.key) != -1) {
            cout << endl << "Error, the key is in the table already." << endl;
            return false;
        }
    if (item_count == table_size) {
        cout << endl << "Error, the table is full.";
        return false;
    }
    int t_index = index;
    for (int i = 1; i <= table_size; i++) {
        if (((*hTable)[t_index].key == "---") || ((*hTable)[t_index].key == "+++")) {
            (*hTable)[t_index] = e;
            item_count++;
            return true;
        }
        t_index = (index+i) % table_size;
    }
    return false;
    
}

/*
Function: 
void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int) )

Arguments: 
pointer reference to integer vector
integer for heap size
integer for index to array
comparison function pointer

Returns:
void

Notes: 
Heapifies an array, at a given index, assuming the index's subtrees are already heapified
*/
int HT::search(const string &key) {
    int index = hashing(key);
    int t_index = index;
    for (int i = 1; i <= table_size; i++) {
        if ((*hTable)[t_index].key == key) {
            return t_index;
        }
        t_index = (index+i) % table_size;
    }
    return -1;
}

/*
Function: 
void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int) )

Arguments: 
pointer reference to integer vector
integer for heap size
integer for index to array
comparison function pointer

Returns:
void

Notes: 
Heapifies an array, at a given index, assuming the index's subtrees are already heapified
*/
bool HT::remove(const string &item) {
    int index = search(item);
    if (index == -1) {
        return false;
    }

    (*hTable)[index].key = "+++";
    (*hTable)[index].description = ' ';
    item_count--;
    return true;
}

/*
Function: 
void HT::print();

Arguments: 
none

Returns:
void

Notes: 
Prints the contents of the hash table
*/
void HT::print() {
    cout << endl << "----Hash Table----" << endl;
    for (int i = 0; i < table_size; i++) {
        if (((*hTable)[i].key != "---") && ((*hTable)[i].key != "+++")) {
            cout << setw(2) << i << ": " << (*hTable)[i].key << ' ' << (*hTable)[i].description << endl;
        }
    }
    cout << "------------" << endl;
}

///////////////////
// Global Functions
///////////////////

/*
Function: 
Entry* get_entry (const string &line)

Arguments: 
constant reference to string, line of input

Returns:
Pointer to an entry object

Notes: 
Creates a new entry with data supplied by an input string
*/
Entry* get_entry (const string &line) {

    Entry* t_entry = new Entry;
    t_entry->key = line.substr(2, 3);
    t_entry->description = line.substr(6, line.length()-6);
    return t_entry;

}

/*
Function: 
string get_key (const string &line);

Arguments: 
constant reference to string, line of input

Returns:
string

Notes: 
Parses a given string to return the key value
*/
string get_key (const string &line) {
    return line.substr(2, line.length()-2);
}


/////////////////
// Main Functions
/////////////////

// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
int HT::hashing(const string& key) {
   return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}

int main(int argc, char** argv ) {
    if ( argc < 2 ) {
        cerr << "argument: file-name\n";
        return 1;
    }

    HT ht;
    ifstream infile(argv[1], ios::in);
    string line;
    infile >> line;    
    while ( !infile.eof() ) {
        if ( line[0] == 'A' ) { 
            Entry* e = get_entry( line );
            ht.insert( *e );
            delete e;
        }
        else {
            string key = get_key(line);
            if ( line[0] == 'D' ) {
                cout << "Removing " << key << "...\n";
                bool removed = ht.remove( key );
                if ( removed )
                    cout << key << " is removed successfully...\n\n";
                else
                    cout << key << " does not exist, no key is removed...\n\n";
            }
            else if ( line[0] == 'S' ) {
                int found = ht.search( key );
                if ( found < 0 ) 
                    cout << key << " does not exit in the hash table ..." << endl << endl;
                else
                   cout << key << " is found at table position " << found << endl << endl;
            }
            else if ( line[0] == 'P' ) {
                cout << "\nDisplaying the table: " << endl;
                ht.print();
            }
            else
                cerr << "wrong input: " << line << endl;
        }
        infile >> line;
 
    }

    infile.close();
    return 0;
}
