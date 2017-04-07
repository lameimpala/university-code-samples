#
# PROGRAM:    Assignment 1
# PROGRAMMER: Reid Wixom
# LOGON ID:   z1693990
# DATE DUE:   2/01/16
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11


assignment1: assignment1.o
	g++ $(CCFLAGS) -o assignment1 assignment1.o

# Rules to compile source code files to object code
assignment1.o: assignment1.cc
	g++ $(CCFLAGS) -c assignment1.cc 

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment1

