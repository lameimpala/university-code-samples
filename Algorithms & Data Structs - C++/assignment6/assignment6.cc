
#include <iostream>
#include "assignment5.h"
#include "assignment6.h"

using namespace std;

/*
Function: 
Node* findMin(Node *ptr);

Arguments: 
pointer to Node

Returns:
pointer to Node

Notes: 
Finds the left-most node from a given node.
*/
Node* findMin(Node *ptr){
    while(ptr->left != nullptr){
        ptr = ptr->left;
    }
    return ptr;
}

/*
Function: 
bool isLeaf(Node *ptr)

Arguments: 
pointer to Node

Returns:
boolean

Notes: 
returns true if Node is leaf, false if not
*/
bool isLeaf(Node *ptr)
{
   if (ptr == nullptr)
       return false;
   else if (ptr->left == nullptr && ptr->right == nullptr)
       return true;
   return false;
}

/*
Function: 
void BST::insert( int value )

Arguments: 
integer value

Returns:
void

Notes: 
Public version of Insert. Calls private version of method
*/
void BST::insert( int value ){
        insert(root, value);
}

/*
Function: 
void BST::insert( Node* &ptr, int value )

Arguments: 
integer value, reference to a Node pointer

Returns:
void

Notes: 
private version of Insert. Inserts new values into the BST
*/
void BST::insert( Node* &ptr, int value ){

    if(ptr==nullptr){
        ptr = new Node;
        ptr->right = NULL;
        ptr->left = NULL;
        ptr->data = value;
    }
    else if(value < ptr->data){
        insert(ptr->left, value);
    }
    else{
        insert(ptr->right, value);
    }

}

/*
Function: 
bool BST::search(int value)

Arguments: 
integer value

Returns:
boolean

Notes: 
public version of Search, calls the private method.
*/
bool BST::search(int value){
    return search(this->root, value);
}

/*
Function: 
bool BST::search(Node* &ptr, int value)

Arguments: 
integer value, reference to a Node pointer

Returns:
boolean

Notes: 
private version of search method.  returns true if value is found with BST, uses recursion
*/
bool BST::search(Node* &ptr, int value){
    if(ptr == nullptr){
        return false;
    }
    else if (ptr->data == value) {
        return true;
    }
    else if (ptr->data > value){
        return search(ptr->left, value);
    }
    else {
        return search(ptr->right, value);
    }
}

/*
Function: 
int BST::sumLeftLeaves()

Arguments: 
none

Returns:
integer, sum of left leaves

Notes: 
public version of method, calls private version
*/
int BST::sumLeftLeaves(){
    return BST::sumLeftLeaves(this->root);
}

/*
Function: 
int BST::sumLeftLeaves(Node* &ptr)

Arguments: 
reference to a Node pointer

Returns:
integer, sum of left leaves

Notes: 
private version of method, finds the sum of all left leaves in the tree.
*/
int BST::sumLeftLeaves(Node* &ptr){
    int sum = 0;
    if(ptr != nullptr){
        if(isLeaf(ptr->left)){
            sum = sum + ptr->left->data;
        }
        else{
            sum = sum + sumLeftLeaves(ptr->left);
        }
        sum = sum + sumLeftLeaves(ptr->right);
    }
    return sum;
}

/*
Function: 
bool BST::remove(int value)

Arguments: 
integer value

Returns:
boolean

Notes: 
public version of remove method, calls private method.
*/
bool BST::remove(int value){
    return BST::remove(this->root, value);
}

/*
Function: 
bool BST::remove( Node* &ptr, int value)

Arguments: 
reference to a node pointer, integer value

Returns:
boolean

Notes: 
private version of remove method, returns true if removal is successful
*/
bool BST::remove( Node* &ptr, int value){
    if(ptr == nullptr){
        return false;
    } else if (ptr->data > value){
        return BST::remove(ptr->left, value);
    } else if ( ptr->data < value) {
        return BST::remove(ptr->right, value);
    } else {

        if (ptr->left == nullptr && ptr->right == nullptr) {
            delete ptr;
            ptr = nullptr;
        } 
        else if (ptr->left == nullptr) {
            Node *temp = ptr;
            ptr = ptr->right;
            delete temp;
        }
        else if (ptr->right == nullptr) {
            Node *temp = ptr;
            ptr = ptr->left;
            delete temp;
        }
        else {
            Node *temp = findMin(ptr->right);
            ptr->data = temp->data;
            return BST::remove(ptr->right, temp->data);
        }
        return true;
    }
}
