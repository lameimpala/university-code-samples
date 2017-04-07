/*********************************************************************
   PROGRAM:    CSCI 340 Assignment 5
   PROGRAMMER: Reid Wixom
   LOGON ID:   z1693990
   DUE DATE:   03/07/16
 
   FUNCTION:   Contains header file for binary tree class
*********************************************************************/ 

#ifndef ASSIGNMENT5
#define ASSIGNMENT5

//--------------------------
// You need to add definition of the Node class
//--------------------------

//definition
struct Node{
    int data;
    Node* left;
    Node* right;
};

class binTree {
    friend struct Node;
    public:
        binTree();
        virtual void insert( int );
        unsigned height() const;
        unsigned size() const;
        void inorder( void(*)(int) );
        void preorder( void(*)(int) );
        void postorder( void(*)(int) );                
                                
    protected:
        Node* root;
    private:
        void insert( Node*&, int );
        unsigned height( Node* ) const;
        unsigned size( Node* ) const;
	void inorder( Node*, void(*)(int) );
	void preorder( Node*, void(*)(int) );
	void postorder( Node*, void(*)(int) );
};

#endif
