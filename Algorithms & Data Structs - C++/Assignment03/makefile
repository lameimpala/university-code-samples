#
# PROGRAM:    Assignment 3
# PROGRAMMER: Reid Wixom
# LOGON ID:   z1693990
# DATE DUE:   2/15/16
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11
ASSIGNMENT=assignment03


$(ASSIGNMENT): $(ASSIGNMENT).o
	g++ $(CCFLAGS) -o $(ASSIGNMENT) $(ASSIGNMENT).o

# Rules to compile source code files to object code
$(ASSIGNMENT).o: $(ASSIGNMENT).cc
	g++ $(CCFLAGS) -c $(ASSIGNMENT).cc 

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o $(ASSIGNMENT)
