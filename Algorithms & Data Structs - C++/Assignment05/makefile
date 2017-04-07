#
# PROGRAM:    Assignment 5
# PROGRAMMER: Reid Wixom
# LOGON ID:   z1693990
# DATE DUE:   2/22/16
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11
ASSIGNMENT=assignment5


$(ASSIGNMENT): $(ASSIGNMENT).o
	g++ $(CCFLAGS) -o $(ASSIGNMENT) $(ASSIGNMENT).o

# Rules to compile source code files to object code
$(ASSIGNMENT).o: $(ASSIGNMENT).cc $(ASSIGNMENT).h
	g++ $(CCFLAGS) -c $(ASSIGNMENT).cc 

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o $(ASSIGNMENT)
