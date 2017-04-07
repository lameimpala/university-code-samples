/*********************************************************************
   PROGRAM:    CSCI 340 Assignment 3
   PROGRAMMER: Reid Wixom
   LOGON ID:   z1693990
   DUE DATE:   02/15/16
 
   FUNCTION:   This program implements the Sieve of Eratosthenes in C++ using sets.
*********************************************************************/  

#include <cstdlib>
#include <set>
#include <iostream>
#include <iomanip>
#include <algorithm>

#define ITEM_W 6 //sets item width on standard output
#define NO_ITEMS 10 //sets number of items per each line of output

using namespace std; 

/*
Function: 
void sieve( set<int>& s, int n)

Arguments: 
reference to set s
integer for number of integers to be used in set

Returns: void

Notes: 
Fills the given set with integers and then leaves only the primes.
*/
void sieve( set<int>& s, int n) {

    for(int i = 0; i < n; i++){
        s.insert(i);
    }

    for(int i = 2; i < n; i++){
        set<int>::iterator iter = s.begin();

        while(iter != s.end()){
          //  cout << *iter % i;
            if((*iter % i == 0) && (*iter > i)) 
                s.erase(iter);
        iter++;
        }

    }

}

/*
Function: 
void print_primes( const set<int>& s) 

Arguments: 
reference to set s

Returns: void

Notes: 
Prints out the prime numbers as supplied by set s
*/
void print_primes( const set<int>& s) {
    set<int>::const_iterator it;
    int i = 1;
    //Prints out vector values, with conditionals to accomodate output parameters
    for(it = s.begin(); it != s.end(); it++){
        if(i % NO_ITEMS == 0){
                cout << setw(ITEM_W) << *it << endl;
            } else{
                cout << setw(ITEM_W) << *it;
            }
            i++;
    }
    cout << endl;
}

int main() {
    set<int> mySet;
    sieve(mySet, 500);
    print_primes(mySet);
    return 0;
}
