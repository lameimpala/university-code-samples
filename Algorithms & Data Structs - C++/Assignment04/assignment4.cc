/*********************************************************************
   PROGRAM:    CSCI 340 Assignment 4
   PROGRAMMER: Reid Wixom
   LOGON ID:   z1693990
   DUE DATE:   02/22/16
 
   FUNCTION:   This program implements a queue class using stacks
*********************************************************************/  

#include "assignment4.h"
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

/*
Function: 
bool Queue::empty() const

Arguments: 
none

Returns: bool

Notes: 
Returns whether both stacks are empty or not
*/
bool Queue::empty() const{
    return s1.empty() && s2.empty();
}

/*
Function: 
int Queue::size() const

Arguments: 
none

Returns: int

Notes: 
Returns combined sizes of stacks
*/
int Queue::size() const{
    return s1.size()+s2.size();
}

/*
Function: 
int Queue::back()

Arguments: 
none

Returns: int

Notes: 
Returns the top of s1 stack
*/
int Queue::back(){
    return s1.top();
}

/*
Function: 
int Queue::front()

Arguments: 
none

Returns: int

Notes: 
Returns integer at front of queue
*/
int Queue::front(){
    if(s2.empty()){
        //copies s1 to s2
        for(size_t i = 0; i < s1.size()+1; i++){
            s2.push(s1.top());
            s1.pop();
        }
    }
    return s2.top();
    
}

/*
Function: 
void Queue::push(const int &value)

Arguments: 
reference to integer

Returns: void

Notes: 
Pushes a supplied value onto the queue
*/
void Queue::push(const int &value){
    s1.push(value);
}

/*
Function: 
void Queue::pop()

Arguments: 
none

Returns: void

Notes: 
Pops the oldest value from the queue
*/
void Queue::pop(){
        if(s2.empty()){
        //copies s1 to s2
        for(size_t i = 0; i < s1.size(); i++){
            s2.push(s1.top());
            s1.pop();
        }
    }
    s2.pop();
}


int main() {
    Queue q;
    string op;
    int val = 0;
 
   cout << "operation -- size front end" << endl;
   while ( !cin.eof() ) {
        cin >> op;
        if ( op == "push" ) {
            cin >> val;
            q.push( val );
            cout << op << " " << val << "    -- ";
        }
        else if ( op == "pop" ) {
            q.pop();
            cout << op << "       -- ";
        }
        else {
            cerr << "Error input: " << op << endl;
            return 1;
        }
        cout << setw(3) << q.size() << setw(5) << q.front() << setw(5) << q.back() << endl;
    }

    while ( !q.empty() )
        q.pop();
    cout << "End -- size of Queue is: " << q.size() << endl;

    return 0;
}
