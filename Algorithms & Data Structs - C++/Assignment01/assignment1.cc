/*********************************************************************
   PROGRAM:    CSCI 340 Assignment 1
   PROGRAMMER: Reid Wixom
   LOGON ID:   z1693990
   DUE DATE:   02/01/16
 
   FUNCTION:   This program utitlizes the C Standard Library to create vector,
   				and load it with random integers
*********************************************************************/  

#include <cstdlib>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

#define SEED 7 //sets the random seed
#define ITEM_W 6 //sets item width on standard output
#define NO_ITEMS 10 //sets number of items per each line of output
#define HIGH 1000 //defines maximum random value
#define LOW 1 //defines minimum random value

using namespace std;

/*
Function: 
void genRndNums( vector<int>& v, int vec_size, int seed )

Arguments: 
reference to a vector<int> object,
an integer refering to the size of the vector
a given integer used for random number seed

Returns: void

Notes: 
Fills the given vector with random integers
*/
void genRndNums( vector<int>& v, int vec_size, int seed ) {

	srand(SEED);
	vector<int>::iterator it;

	//Pushes random integers onto the vector passed into the function
	for(int i = 0; i < vec_size; i++){
		v.push_back(rand() % (HIGH - LOW + 1) + LOW);
	}

}

/*
Function: 
void printVec( const vector<int>& v, int vec_size )

Arguments: 
reference to a const vector<int>,
an integer refering to the size of the vector

Returns: void

Notes: 
Prints out the values in a given vector, conforming to the standard set
by the ITEM_W and NO_ITEMS constants
*/
void printVec( const vector<int>& v, int vec_size ){

	vector<int>::const_iterator it;
	int i = 1;

	//Prints out vector values, with conditionals to accomodate output parameters
	for(it = v.begin(); it != v.end(); it++){
		if(i % NO_ITEMS == 0){
				cout << setw(ITEM_W) << *it << endl;
			} else{
				cout << setw(ITEM_W) << *it;
			}
			i++;

	}

}

int main() {

    int size = 100;
    vector<int> v;
    genRndNums( v, size, SEED );
    sort(v.begin(), v.end());
    printVec(v, size);


    return 0;
}
