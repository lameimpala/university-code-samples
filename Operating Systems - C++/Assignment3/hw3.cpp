/*

    Assignment 3
    Reid Wixom
    z1693990
    CSCI 480
    04/04/2017

    This program demonstrates the functionality of forking and piping
    by creating a "microshell" to read commands from the terminal and
    execute them.

*/
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define COMMAND_LIMIT 1024
#define ARGUMENT_LIMIT 1024

using namespace std;

/*
    Utility function used by `build_arg_list` to insert
    commands into a char* array by converting strings
    to c-style strings

    Params: 
        string     - command or argument to be converted to c-style string
        char* &    - reference to location of char* array where item is to be inserted
    Returns:
        void
*/
void insert_into_list(string command_param, char* &arg_idx) {
    if (!command_param.empty()) {
        arg_idx = new char[command_param.length()];
        strcpy(arg_idx, command_param.c_str());
    }
}

/*
    Transforms an input string into an array of arguments compatible with shell-execution

    Params: 
        string      - input string
        char**      - reference to a character array

    Returns:
        void
*/
void build_arg_list(string str, char ** arg_list) {
    string command_param;
    int idx = 0;
    // get rid of spaces
    while (str[0] == ' ') {
        str.erase(0, 1);
    }

    string::size_type start = 0;
    string::size_type end = str.find(' ');
    command_param = str.substr(start, end);
    insert_into_list(command_param, arg_list[idx]);

    while (end != string::npos) {
        ++idx;
        start = ++end;
        end = str.find(' ', end+1);
        if (end == string::npos) {
            // get any arguments at end of string
            command_param = str.substr(start, str.length());
            insert_into_list(command_param, arg_list[idx]);
        }
        // get any arguments in middle of string
        else {
            command_param = str.substr(start,(end-start));
            insert_into_list(command_param, arg_list[idx]);
        }
    }
}
/*
    Executes a given command and its arguments, performs various piping functions

    Params: 
        string      - command including arguments
        int [2]     - if piping, contains the pipe in and out ends
        int         - index of command, used in piping, currently only supports 2

    Returns:
        1, unless error
*/
int execute(string command, int pipefd[2] = NULL, int idx = -1) {
    pid_t pid;
    int status = 1;
    char *args[ARGUMENT_LIMIT];

    // convert command string to c-style arg-list
    build_arg_list(command, args);
    // run command and arguments
    pid = fork();
    if (pid == 0) {
        // Child process
        if (idx == 0) {
            close (pipefd[0]);
            close(1);

            dup(pipefd[1]);
            close (pipefd[1]);
        }
        else if (idx == 1) {
            close (pipefd[1]);
            close(0);

            dup (pipefd[0]);
            close (pipefd[0]);
        }


        if (execvp(args[0], args) == -1) {
            perror("Invalid Command.");
        }
        
        exit(127);
    }
    else if (pid < 0) {
        // Error forking
        perror("Fork Error");
    }
    else {
        // Parent Process, close pipe on end
        if (idx == 1) {
            close(pipefd[0]);
            close(pipefd[1]);
        }

        while (!WIFEXITED(status) && !WIFSIGNALED(status)); {
            waitpid(pid, &status, WUNTRACED);
        }
    }

    return 1;
}


/*
    Splits a string based on input delimeter. 

    Params: 
        string      - input string
        const char* - input delimeter

    Returns:
        vector <string> - set of strings, split by excluded delimeter
*/
vector<string> split(string s, const char* delimiter) {
    vector<string> internal;
    string command;
    string::size_type i = 0;
    string::size_type j = s.find(delimiter);

    internal.push_back(s.substr(i, j-i));
    while (j != string::npos) { 
        i = ++j;
        j = s.find(delimiter, j);
        if (j == string::npos) {
            command = s.substr(i+1, s.length());
            internal.push_back(s.substr(i+1, s.length()));
        }
        else {
            internal.push_back(s.substr(i+1,(j-i)-1));
        }    
    }
    return internal;
}

/*
    Waits for input, and stores an inputed line in &line

    Params: 
        string &line      - input string reference
    Returns:
        void
*/
void read_line(string &line) {
    while (line.empty()) {
        cout << "> ";
        getline(cin, line);
    }
}

int main(int argc, char *argv[]) {

    string line;
    string commands [COMMAND_LIMIT];

    vector<string> command_tokens;

    int pipefd[2];
    int command_count = 0;
    // while not quit
    int status = 1;
    while (status) {

        // wait for user input
        read_line(line);
        // split the input by the defined pipe value
        command_tokens = split(line, "||");
        command_count = command_tokens.size();

        if (command_count > 1) {
           if(pipe(pipefd) < 0) {
               perror("Pipe Error");
           }
        }
        
        for (
            vector<string>::iterator command = command_tokens.begin();
            command != command_tokens.end();
            ++command
        ) {
            if (*command == "quit" || *command == "q") {
                // end the loop
                status = 0;
            }
            else {
                int idx = command - command_tokens.begin();
                if (command_count > 1) {
                        execute(*command, pipefd, idx);
                }
                else {
                    execute(*command);
                }
            }
        }

        line.clear();
        cin.clear();
    }
    exit(127);
}
