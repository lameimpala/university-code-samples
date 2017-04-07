/****************************************************************
   Processor header

   Author:    Reid Wixom
   Z-number:  z1693990

   Description: Handles the file and input processing required by assignment 1

****************************************************************/
#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <string>

class Processor {
public:
	std::string getPartA(std::string filename);
	std::string getPartB();
	std::string getPartC();
	std::string getPartD();
};

#endif