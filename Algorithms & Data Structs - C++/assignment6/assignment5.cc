/*********************************************************************
   PROGRAM:    CSCI 340 Assignment 5
   PROGRAMMER: Reid Wixom
   LOGON ID:   z1693990
   DUE DATE:   03/07/16
 
   FUNCTION:   Implements the binary tree class
*********************************************************************/ 

#include "assignment5.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

//------------------------------------------------
// Do not modify this section of code
//------------------------------------------------
const int MAX_SIZE = 1000;
const int MAX_COUNT = 20;
const int WIDTH = 5;
const int ROW_SIZE = 5;
int mcount = 0;
int rcount = 0;

void display(int d) {
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}
//--------------------------------------------
// End
//--------------------------------------------                        
/*
Function: 
void binTree::insert(int val)

Arguments: 
integer val

Returns:
void

Notes: 
Public version of Insert. Calls private version of method
*/
void binTree::insert(int val){
    if(root == nullptr){
        root = new Node;
        root->data = val;
        root->right = nullptr;
        root->left=nullptr;
    }
    else
        insert(root, val);
}

/*
Function: 
void binTree::insert(Node* &ptr, int value)

Arguments: 
Reference to a Node
Integer Value

Returns:
void

Notes: 
Inserts new items into Binary Tree, and preserves BST requirements
*/
void binTree::insert(Node* &ptr, int value){
    if(ptr==nullptr){
        ptr = new Node;
        ptr->data = value;
        ptr->left=nullptr;
        ptr->right=nullptr;
    }
    else if ( size(ptr->right) < size(ptr->left) )
        insert(ptr->right, value);
    else
        insert(ptr->left, value);
}

/*
Function: 
binTree::binTree()

Arguments: 
none

Returns:
nothing

Notes: 
default constructor for binTree class
*/
binTree::binTree(){
    root = 0;
}

/*
Function: 
unsigned binTree::height() const

Arguments: 
none

Returns:
unsigned integer

Notes: 
calls private version of height method
*/
unsigned binTree::height() const{
    return height(root);
}

/*
Function: 
unsigned binTree::height(Node *ptr) const

Arguments: 
Pointer to a Node

Returns:
unsigned integer

Notes: 
calculates the height of a Node, by using recursion
*/
unsigned binTree::height(Node *ptr) const{
    if(ptr==nullptr){
        return 0;
    }
    else{
        int l = height(ptr->left);
        int r = height(ptr->right);
        if(l > r || l == r){
            return l+1;
        }
        else
            return r+1;
}
}

/*
Function: 
unsigned binTree::size() const

Arguments: 
none

Returns:
unsigned integer

Notes: 
Calls private version of size method.
*/
unsigned binTree::size() const{
    return size(root);
}
/*
Function: 
unsigned binTree::size(Node *ptr) const{

Arguments: 
Pointer to a Node

Returns:
unsigned integer

Notes: 
Calculates the size of a tree from a given Node recursively.
*/
unsigned binTree::size(Node *ptr) const{
    if(ptr==nullptr){
        return 0;
    }
    else{
        int lsize = size(ptr->left);
        int rsize = size(ptr->right);
        return lsize+rsize+1;
    }
}

/*
Function: 
void binTree::inorder(void(*func)(int)){

Arguments: 
Pointer to a function

Returns:
void

Notes: 
Calls private version of inorder method
*/
void binTree::inorder(void(*func)(int)){
    inorder(root, func);
}
/*
Function: 
void binTree::inorder(Node *ptr, void(*func)(int))

Arguments:
Pointer to a Node
Pointer to a function

Returns:
void

Notes: 
Processes binary tree with in-order traversing, and applies an operation.
*/
void binTree::inorder(Node *ptr, void(*func)(int)){
    if(ptr!=nullptr){
        inorder(ptr->left, func);
        func(ptr->data);
        inorder(ptr->right, func);
    }
}
/*
Function: 
void binTree::preorder(void(*func)(int))

Arguments:
Pointer to a function

Returns:
void

Notes: 
Processes binary tree with pre-order traversing, and applies an operation.
*/
void binTree::preorder(void(*func)(int)){
    preorder(root, func);
}
/*
Function: 
void binTree::preorder(Node *ptr, void(*func)(int))

Arguments:
Pointer to a Node
Pointer to a function

Returns:
void

Notes: 
Processes binary tree with pre-order traversing, and applies an operation.
*/
void binTree::preorder(Node *ptr, void(*func)(int)){
        if(ptr!=nullptr){
            func(ptr->data);
            preorder(ptr->left, func);
            preorder(ptr->right, func);
} 
}
/*
Function: 
void binTree::postorder(void(*func)(int))

Arguments:
Pointer to a function

Returns:
void

Notes: 
Processes binary tree with post-order traversing, and applies an operation.
*/
void binTree::postorder(void(*func)(int)){
    postorder(root, func);
}
/*
Function: 
void binTree::postorder(Node *ptr, void(*func)(int))

Arguments:
Pointer to a Node
Pointer to a function

Returns:
void

Notes: 
Processes binary tree with post-order traversing, and applies an operation.
*/
void binTree::postorder(Node *ptr, void(*func)(int)){
        if(ptr!=nullptr){
            postorder(ptr->left, func);
            postorder(ptr->right, func);
            func(ptr->data);
} 
}



