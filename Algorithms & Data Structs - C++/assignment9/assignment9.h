/*********************************************************************
   PROGRAM:    CSCI 340 Assignment 9
   PROGRAMMER: Reid Wixom
   LOGON ID:   z1693990
   DUE DATE:   05/02/16
 
   FUNCTION:   Contains header file for graph class
*********************************************************************/ 


#ifndef ASSIGNMENT9_H
#define ASSIGNMENT9_H
#include <vector>
#include <list>

class graph {
    private:
        int size;
        std::vector< std::list<int> > *adj_list;
        std::vector< char > *labels;
        void depth_first( int );
        bool *visited;
    public:
        graph( const char* filename );
        ~graph();
        int get_size() const;
        void traverse( );
        void print ( ) const;
};

#endif 
