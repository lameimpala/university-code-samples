/*********************************************************************
   PROGRAM:    CSCI 340 Assignment 9
   PROGRAMMER: Reid Wixom
   LOGON ID:   z1693990
   DUE DATE:   05/02/16
 
   FUNCTION:   Implements a graph and depth-first search in c++
*********************************************************************/ 

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "assignment9.h"

using namespace std;

string chain;

/*
Function: 
graph(const char* filename)

Arguments: 
constant pointer to char

Returns:
nothing

Notes: 
constructor for graph class, takes filename as argument
*/
graph::graph(const char* filename) {

	fstream inFile;
	inFile.open(filename);

	if(inFile.is_open()) {
		inFile >> size;
		adj_list = new vector< list<int> >;

		char a = 'A';

		labels = new vector< char >(size);
		adj_list = new vector< list<int> >(size);

		for (int j = 0; j <= size; j++) {
			(*labels)[j] = a;
			a++;
		}

		char buffer[256];
		inFile.getline(buffer, 256);
		inFile.getline(buffer, 256);
		char ch;
		int index = 0;
		int k = 0;

		
		for (int i = 0; i < size; i++) {
			cout << "Row: " << i << endl;
			inFile.getline(buffer, 256);
			while (index < size){
				ch = buffer[k];
				if (ch == '1') {
					(*adj_list)[i].push_back(index);
					index++;
				}
				else if (ch == '0') {
					index++;
				}
				k++;
			}
			k = 0;
			index = 0;
		}
	}
}

/*
~graph()graph::~graph()

Arguments: 
none

Returns:
nothing

Notes: 
destructor for graph class
*/
graph::~graph() {
	delete labels;
	delete adj_list;
}

/*
void print() const{

Arguments: 
none

Returns:
void

Notes: 
Prints out the vertices of a graph, and their connections
*/
void graph::print() const{

	cout << endl << "Number of Vertices in Graph: ";
	cout << size << endl;
	cout << endl << "-------Graph-------" << endl;

	for(int i = 0; i < size; i++) {
		cout << (*labels)[i] << ": ";
		for (list<int>::const_iterator it = ((*adj_list)[i]).begin(); it != ((*adj_list)[i]).end(); it++) {
			cout << (*labels)[*it] << ", ";
		}
		cout << endl;
	}
	cout << "-----End of Graph---" << endl;

}

/*
void depth_first(int v)

Arguments: 
integer v

Returns:
void

Notes: 
Performs a recursive depth search of a graph
*/
void graph::depth_first(int v) {

	visited[v] = true;

	cout << (*labels)[v] << " ";
	
	list<int>::iterator it;

	for (it = ((*adj_list)[v]).begin(); it != ((*adj_list)[v]).end(); it++) {

		if (!visited[*it]) {
			chain = chain + '(' + (*labels)[v] + ", ";
			chain = chain + (*labels)[*it] + ") ";
			depth_first(*it);
		}
	}
}

/*
void traverse()

Arguments: 
none

Returns:
void

Notes: 
Traverses the graph, and prints out the order of depth-first traversal
*/
void graph::traverse() {

	visited = new bool[size];

	cout << endl << "------- traverse of graph ------" << endl;

	for(int i = 0; i < size; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < size; i++) {

		if (!visited[i]) {
			depth_first(i);

		}
	}
	cout << endl;
	

	cout << chain;

	delete [] visited;

	cout << endl << "--------- end of traverse -------" << endl;
}




#define ASSIGNMENT9_TEST
#ifdef 	ASSIGNMENT9_TEST

int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "args: input-file-name\n";
        return 1;
    }

    graph g(argv[1]);

    g.print();
    
    g.traverse();

    return 0;
}

#endif
