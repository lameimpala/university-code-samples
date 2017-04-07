/*********************************************************************
   PROGRAM:    CSCI 340 Assignment 2
   PROGRAMMER: Reid Wixom
   LOGON ID:   z1693990
   DUE DATE:   02/08/16
 
   FUNCTION:   This program utilizes STL to create vectors and then test the 
                effectiveness of various searching methods.
*********************************************************************/  


#include <cstdlib>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

#define ITEM_W 6 //sets item width on standard output
#define NO_ITEMS 10 //sets number of items per each line of output
#define HIGH 10000 //defines maximum random value
#define LOW 1 //defines minimum random value

using namespace std; 

const int TOBE_SEARCHED = 5000;

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
    //
    srand(seed);
    vector<int>::iterator it;
    //Pushes random integers onto the vector passed into the function
    for(int i = 0; i < vec_size; i++){
        v.push_back(rand() % (HIGH - LOW + 1) + LOW);
    }
}

/*
Function: 
int linearSearch( const vector<int>& v, int x)

Arguments: 
const reference to an integer vector
an integer, X, to be searched for

Returns: return int, subscript of where X first appears in vector

Notes: 
Finds the first subscript of the vector that contains X, returns -1 if not found
*/
int linearSearch( const vector<int>& v, int x) {
    vector<int>::const_iterator it;
    it = find(v.begin(), v.end(), x); 
    if(*it == x){
        return distance(v.begin(), it);
    }
    else
        return -1;
}

/*
Function: 
int binarySearch( const vector<int>& v, int x)

Arguments: 
const reference to an integer vector
an integer, X, to be searched for

Returns: return int, subscript of where X first appears in vector

Notes: 
Finds the first subscript of the vector that contains X, returns -1 if not found
*/
int binarySearch( const vector<int>& v, int x) {
    pair<vector<int>::const_iterator, vector<int>::const_iterator> bounds;
    //sort(v.begin(). v.end());
    bounds = std::equal_range(v.begin(), v.end(), x);

    if(*bounds.first != *bounds.second){
        return *bounds.first;
    }
    else
        return -1;
}

/*
Function: 
int search( const vector<int>& container, const vector<int>& searchNums,
            int (*p)( const vector<int>&, int) )

Arguments: 
const reference to an integer vector, to be searched
const reference to an integer vector, containing integers to be searched for
a pointer to a search function

Returns: returns number of successful searches

Notes: 
Uses either the linear search or binary search methods and returns number of successful searches
*/
int search( const vector<int>& container, const vector<int>& searchNums,
            int (*p)( const vector<int>&, int) ){
            int sum = 0;

            for(vector<int>::const_iterator it = searchNums.begin(); it != searchNums.end(); ++it){
               if(p(container, *it) != -1){
                sum++;
               // cout << endl << sum;
               }
            }

    return sum;
}

/*
Function: 
void sortVec (vector<int>& v)

Arguments: 
const reference to an integer vector, to be sorted

Returns: void

Notes: 
Calls the STL sort method to sort the vector to be used for binary search
*/
void sortVec (vector<int>& v) {
    sort(v.begin(), v.end());
}

/*
Function: 
void printStat (int totalSucCnt, int vec_size) 

Arguments: 
integer for total number of successful searches
integer for size of vector

Returns: void

Notes: 
Determines percentage of successful searches
*/
void printStat (int totalSucCnt, int vec_size) {
    cout << (float)totalSucCnt/vec_size*100 << "%" << endl;
}

int main() {
    vector<int> container, tobeSearched;
    genRndNums(container, 10000, 7);
    genRndNums(tobeSearched, TOBE_SEARCHED, 5);

    cout << "\nConducting linear search ..." << endl;
    int linear_search_count = search( container, tobeSearched, linearSearch );
    printStat ( linear_search_count, TOBE_SEARCHED );

    cout << "\nConducting binary search on unsorted container ..." << endl;
    int binary_search_count = search( container, tobeSearched, binarySearch );
    printStat ( binary_search_count, TOBE_SEARCHED );

    sortVec( container );

    cout << "\nConducting binary search on sorted container ..." << endl;
    binary_search_count = search( container, tobeSearched, binarySearch );
    printStat ( binary_search_count, TOBE_SEARCHED );

    return 0;
}
