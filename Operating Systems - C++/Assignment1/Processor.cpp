#include "Processor.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <unordered_set>
#include <math.h>

using namespace std;

/***************************************************************
Either using a supplied filename,
this function formatss a string containing system info.

Arguments: string filename

Returns:  a string formatted containing the output
		  a string formatted containing an error message

***************************************************************/

string Processor::getPartA(string filename) {
    string line;
    ifstream inFile;
    stringstream stringBuilder;
    int records, characters;

    inFile.open(filename);

    if (!inFile) {
        stringBuilder << "There was an error while attempting to open the file." << endl;
        return stringBuilder.str();
    }

    while (!inFile.eof()) {
       getline(inFile, line);
       characters = characters + line.length();
       records++;
    }

    inFile.close();

    //Build string to return to main
    stringBuilder << "Answers to Part A"  << endl;
    stringBuilder << "1. The data was obtained from the " << filename << " file." << endl;
    stringBuilder << "2. The number of records is " << records << "." << endl;
    stringBuilder << "3. The number of characters is " << characters << "." << endl;
    stringBuilder << "4. GREP and regular expressions were used to confirm these values." << endl;

    return stringBuilder.str();
}

/***************************************************************
Requires no parameters, this function returns a string
formatted with information pertaining to processors.

Arguments:  

Returns:  a formatted string containing information on the system's processors
		  a formatted string containing an error message

***************************************************************/
string Processor::getPartB() {
	int coreCount = 0;
	string cache, line;
	stringstream stringBuilder;
	unordered_set<int> physicalCores, sharedCache;
	ifstream inFile;

	inFile.open("/proc/cpuinfo");

	if (!inFile) {
		return "Error! The file failed to open.";
	}

	while (!inFile.eof()) {
		getline(inFile, line);
		if(!line.find("processor")) {
			coreCount++;
		}
		if (!line.find("physical id")) {
			size_t position = line.find(":") + 1;
			int id = stoi(line.substr(position));
			physicalCores.insert(id);
		}
		if(!line.find("core id")) {
			size_t position = line.find(":") + 1;
			int id = stoi(line.substr(position));
			sharedCache.insert(id);
		}
	}

	stringBuilder << endl << "Answers to Part B" << endl;
	stringBuilder << "1. The machine has " << coreCount << " total cores." << endl;
	stringBuilder << "2. The machine has " << physicalCores.size() << " physical processors." << endl;
	stringBuilder << "3. Physical ID's: ";

	for(auto it = physicalCores.begin(); it != physicalCores.end(); it++) {
		if (it != physicalCores.begin()) {
			stringBuilder << ", ";
		}
		stringBuilder << *(it);
	}

	stringBuilder << "." << endl;
	stringBuilder << "4. There are " << sharedCache.size() << " pools of L2 cache." << endl;

	return stringBuilder.str();
}
/***************************************************************
Requires no parameters, this function returns a formatted string
with information on the cache and address sizes, and FPU.

Arguments:  

Returns:  a formatted string containing the information
		  a formatted string containing an error message

***************************************************************/
string Processor::getPartC() {
	ifstream inFile;
	stringstream stringBuilder;
	string physicalSize, virtualSize, line, fpu, cachesize;
	int virtualBits, physicalBits, cachesizeBits;

	inFile.open("/proc/cpuinfo");

	if (!inFile) {
		return "Error! The file failed to open.";
	}

	while (!inFile.eof()) {
		getline(inFile, line);
		if (!line.find("address sizes")) {
			size_t pos1 = line.find(":")+1;
			physicalSize = line.substr(pos1, 8);
			physicalBits = stoi(physicalSize.substr(0, physicalSize.length()-5));
			size_t pos2 = pos1 + 18;
			virtualSize = line.substr(pos2, 8);
			virtualBits = stoi(virtualSize.substr(0, virtualSize.length()-5));
		}
		if (!line.find("fpu")) {
			size_t pos = line.find(":") + 1;
			string temp = line.substr(pos, 3);
			temp.compare("yes") ? fpu = "has" : "does not have";
		}
		if (!line.find("cache size")) {
			size_t pos = line.find(":") + 1;
			cachesize = line.substr(pos, 8);
			cachesizeBits = stoi(cachesize.substr(0, cachesize.length()-3));
			cachesizeBits = cachesizeBits * 1024;
		}
	}

	int ratio = pow(2, (virtualBits - physicalBits));

	stringBuilder << endl << "Answers for Part C" << endl;
	stringBuilder << "1. The physical address size is " << physicalSize << "." << endl;
	stringBuilder << "2. The virtual address size is " << virtualSize << "." << endl;
	stringBuilder << "3. The ratio of virtual to physical address space is " << ratio << "." << endl;
	stringBuilder << "4. This machine " << fpu << " a floating point unit." << endl;
	stringBuilder << "5. The cache size is " << cachesize << "." << endl;
	stringBuilder << "6. The cache size is " << cachesizeBits << " B." << endl;

	return stringBuilder.str();
}
/***************************************************************
Requires no parameters, this function returns a string
formatted with system uptime given in multiple formats

Arguments:  

Returns:  a formatted string displaying the system uptime
		  a formatted string containing an error message

***************************************************************/
string Processor::getPartD() {
	ifstream inFile;
	stringstream stringBuilder;
	string line, temp;
	int days, hours, minutes, uptime;
	float seconds;

	inFile.open("/proc/uptime");

	if (!inFile) {
		stringBuilder << "Error! Failed to get system uptime." << endl;
		return stringBuilder.str();
	}

	getline(inFile, line);
	istringstream iss(line);
	iss >> temp;
	uptime = stoi(temp);

	days = (((uptime / 60) / 60) / 24);
	seconds = uptime - (days*24*60*60);
	hours = ((seconds / 60) / 60);
	seconds = seconds - (hours*60*60);
	minutes = seconds / 60;
	seconds = seconds - (minutes*60);

	stringBuilder << endl << "Answers for Part D" << endl;
	stringBuilder << "1. The system has been running for " << uptime << " seconds." << endl;
	stringBuilder << "The system has been running for:" << endl;
	stringBuilder << "Days:       " << days << endl;
	stringBuilder << "Hours:       " << hours << endl;
	stringBuilder << "Minutes:     " << minutes << endl;
	stringBuilder << "Seconds:     " << seconds << endl;

	return stringBuilder.str();
}



