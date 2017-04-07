/*
    CSCI 480-2
    Assignment 2
    Reid Wixom    
    z1693990
    Due on March 2, 2017


    Purpose
    This program gets system information from system API calls.
    Part 3 explores forking processes.

    Execution
    ./hw2.exe
    
*/



#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


#define width 18
#define api_width 45
#define path_width 35

#define sys_file "/proc/sys/kernel/"

using namespace std;
 
int main(int argc, char* argv[]) {

/*  Part 1
*******************************************************************************
*/

    utsname unameData;
    string line;
    ifstream inFile;

    // set up array to facilitate getting values
    string valuesToFetch[4] = {
        "ostype",
        "hostname",
        "osrelease",
        "version"
    };

    // get system details from API
    uname(&unameData);

    // format header
    cout << endl << endl;
    cout << setw(width) << left << "Field" << setw(width) << left << "File Data" << setw(api_width ) << left << "API Data" << endl;

    // get system details from file
    for (int i = 0; i < 4; i++) {
        string filename = sys_file + valuesToFetch[i];
        inFile.open(filename);
        if (!inFile) {
            cout << "There was an error while attempting to open the file.";
        }
        else {
            getline(inFile, line);
            switch (i) {
                case 0: //ostype
                    cout << setw(width) << left << "OSType" << setw(width) << left << line << setw(api_width ) << left << unameData.sysname << endl;
                    break;
                case 1: //hostname
                    cout << setw(width) << left << "Hostname" << setw(width) << left << line << setw(api_width ) << left << unameData.nodename << endl;
                    break;
                case 2: //osrelease
                    cout << setw(width) << left << "OSRelease" << setw(width) << left << line << setw(api_width ) << left << unameData.release << endl;
                    break;
                case 3: //version
                    cout << setw(width) << left << "Version" << setw(width) << left << line << setw(api_width ) << left << unameData.version << endl;
                    break;
            }
            inFile.close();
        }
    }
    // print machine information, obtained only from the API
    cout << setw(width) << left << "Machine" << setw(width) << left << " " << setw(width) << left << unameData.machine << setw(api_width ) << endl;


/*  Part 2
*******************************************************************************
*/

    string enviro = getenv("PATH");
    int entries = 0;
    int bytes = 0;

    //  Format Header
    cout << endl << endl;
    cout << setw(path_width) << left << "Path" << setw(6) << right << "Bytes" << endl;

    // while we can still find the delimiter
    while (enviro.find(':') != string::npos) {
        size_t pos = enviro.find(":");
        string path = enviro.substr(0, pos);
        // increment counters
        bytes += path.length();
        entries++;
        // send to output
        cout << setw(path_width) << left << path << setw(6) << right << path.length() << endl;
        // erase the path that we've printed thus far
        enviro.erase(0, pos+1); 
    }
    // output totals
    cout << setw(19) << left << "Total" << setw(6) << right << bytes << " Bytes " << entries << " Entries" << endl << endl << endl; 


/*  Part 3
*******************************************************************************
*/
    // stringstream to hold pid's prior to shell execution
    stringstream pid_pool;
    // stringstream to hold output until ready to push to output
    stringstream builder;

    int middle_pid = fork();  //  create middle process
    int child_pid = fork();  //  create 2 children processes

    // clear the buffer
    cout << unitbuf;

    if (middle_pid > 0 && child_pid > 0) { // Original Process
            int pid = getpid();
            int parent_pid = getppid();
            builder << "Parent: My PID is " << parent_pid << "." << endl;
            builder << "My parent is " << parent_pid << "." << endl;
            builder << "My Children are " << middle_pid << " and " << child_pid << "." << endl << endl;
            cout << builder.str();
            // place all pids into stringstream to output to bash
            pid_pool << pid << "," << parent_pid << "," << middle_pid  << "," << child_pid;

            string command = "/bin/ps -f --ppid " + pid_pool.str();

            cout << "Parent: Issuing command: " << command << endl << endl;
            //  execute command on bash
            system(command.c_str());   
            cout << endl << endl;
            // wait for children
            waitpid(child_pid,0,0);             
            waitpid(middle_pid,0,0);

            cout << "Parent: All processes are finished." << endl;
            exit(0);
    }
    else if(child_pid > 0) { // Middle process
            int pid = getpid();
            int parent_pid = getppid();
            builder << "Middle: My PID is " << pid << "." << endl;
            builder << "My parent is " << parent_pid << "." << endl;
            builder << "My child is " << child_pid << "." << endl << endl;
            cout << builder.str();
            // clear the stringstream
            builder.str("");
            system("sleep 3");
            builder << "Middle: " << pid << " is awake."  << endl << endl;
            cout << builder.str();
            exit(0);
    }
    else if(child_pid == 0 ) {   // Child processes
            int pid = getpid();
            int parent_pid = getppid();
            builder << "Child: My PID is " << pid << "." << endl;
            builder << "My parent is " << parent_pid << "." << endl << endl;
            cout << builder.str();
            // clear the string stream
            builder.str("");
            system("sleep 3");
            builder << "Child: " << pid << " is awake." << endl << endl;
            cout << builder.str();
            exit(0);
    }
    else {  // Error
        cout << "There was an error while attempting to fork." << endl << endl;
        exit(-1);
    }



}
