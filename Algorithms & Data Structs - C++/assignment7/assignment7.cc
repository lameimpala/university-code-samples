/*********************************************************************
   PROGRAM:    CSCI 340 Assignment 7
   PROGRAMMER: Reid Wixom
   LOGON ID:   z1693990
   DUE DATE:   04/04/16
 
   FUNCTION:   Contains the implementation of a heap using arrays
*********************************************************************/ 

#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

/*
Function: 
void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int) )

Arguments: 
pointer reference to integer vector
integer for heap size
integer for index to array
comparison function pointer

Returns:
void

Notes: 
Heapifies an array, at a given index, assuming the index's subtrees are already heapified
*/
void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int) ) {

        int largest;
        int left_index = (2*r);
        int right_index = (2*r)+1;
       // int parent_index = r/2;

        if ((left_index <= heap_size) && compar(v[left_index], v[r])) {
            largest = left_index;
        } 
        else {
            largest = r;
        }
        if ((right_index <= heap_size) && compar(v[right_index], v[largest])) {
            largest = right_index;
        }
        if (largest != r) {
            swap(v[largest], v[r]);
            heapify(v, heap_size, largest, compar);
        }
}

/*
Function: 
void build_heap ( vector < int >& v, int heap_size, bool (*compar)(int, int) ) 

Arguments: 
pointer reference to integer vector
integer for heap size
comparison function pointer

Returns:
void

Notes: 
Builds a heap from a given array
*/
void build_heap ( vector < int >& v, int heap_size, bool (*compar)(int, int) ) {
    for (int i = heap_size; i >= 1; i--) {
        heapify(v, heap_size, i, compar);
    }
}

/*
Function: 
bool less_than ( int e1, int e2 )

Arguments: 
integer e1,
integer e2

Returns:
boolean

Notes: 
Returns true if e1 is less than e2, false otherwise
*/
bool less_than ( int e1, int e2 ) {
    return (e1 < e2);
}

/*
Function: 
bool greater_than ( int e1, int e2 )

Arguments: 
integer e1,
integer e2

Returns:
boolean

Notes: 
Returns true if e1 is greater than e2, false otherwise
*/
bool greater_than ( int e1, int e2 ) {
    return (e1 > e2);
}

/*
Function: 
int extract_heap ( vector < int >& v, int& heap_size, bool (*compar)(int, int) )

Arguments: 
pointer reference to integer vector
integer reference to heap size
comparison function pointer

Returns:
integer, the min or max of the heap

Notes: 
returns the minimum or max of a heap, and then heapifies the remainder
*/
int extract_heap ( vector < int >& v, int& heap_size, bool (*compar)(int, int) ) {
    int temp = v[1];
    v[1] = v[heap_size];
    heap_size--;
        heapify(v, heap_size, 1, compar);
    return temp;
}

/*
Function: 
void heap_sort ( vector < int >& v, int heap_size, bool (*compar)(int, int) ) 

Arguments: 
pointer reference to integer vector
integer for heap size
comparison function pointer

Returns:
void

Notes: 
sorts a given heap by repeatedly calling extract_heap
*/
void heap_sort ( vector < int >& v, int heap_size, bool (*compar)(int, int) ) {
    for (int i = heap_size; i >=2; i--) {
        v[i] = extract_heap(v, heap_size, compar);
    }
    reverse(v.begin()+1, v.end());
}

/*
Function: 
void print_vector ( vector < int >& v, int pos, int size ) 

Arguments: 
pointer reference to integer vector
integer for index to begin at
int for total size of heap

Returns:
void

Notes: 
Prints a given array out, with 8 to a line
*/
void print_vector ( vector < int >& v, int pos, int size ) {
    int j = 1;
    for(int i = pos; i <= size; i++) {
        cout << setw(5) << v[i];
        if ( j % 8 == 0) {
            cout << endl;
        }
        j++;
    }
    cout << endl;

}

int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake    
    int heap_size = 24;
    for (int i=1; i<=heap_size; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+heap_size+1 );
    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, heap_size );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, heap_size, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, heap_size );
    heap_sort( v, heap_size, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, heap_size );
    
    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, heap_size, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, heap_size );
    heap_sort( v, heap_size, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, heap_size );
                        
    return 0;
}
