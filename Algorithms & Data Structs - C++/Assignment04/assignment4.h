/*********************************************************************
   PROGRAM:    CSCI 340 Assignment 4 Header
   PROGRAMMER: Reid Wixom
   LOGON ID:   z1693990
   DUE DATE:   02/22/16
 
   FUNCTION:   Contains the header file for the Queue class
*********************************************************************/
#ifndef ASSIGNMNET4_H
#define ASSIGNMENT4_H
#include <stack>

class Queue {
    private:
        std::stack<int> s1, s2;
    public:
        bool empty() const;
        int size() const;
        int front();
        int back();
        void push(const int& val);
        void pop();
};

#endif
