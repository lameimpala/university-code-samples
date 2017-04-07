/*
    CSCI 480-2
    Assignment 1
    Reid Wixom    
    z1693990
    Due on February 14, 2017


    Purpose
    This program utilizes a class named 'Processor' which handles
    querying system files to answer questions.

    Execution
    ./hw1.exe [filename]
    [filename] points to /cpu/cpuinfo by default
    
*/
#include <string>
#include <iostream>
#include "Processor.h"

using namespace std;
 
int main(int argc, char* argv[]) {
    Processor P;
    string defaultPath = "/proc/cpuinfo";

    cout << P.getPartA((argv[1]) ? argv[1] : defaultPath);
    cout << P.getPartB();
    cout << P.getPartC();
    cout << P.getPartD();
}
