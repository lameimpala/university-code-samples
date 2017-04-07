#
# PROGRAM:    Assignment 6
# PROGRAMMER: Reid Wixom
# LOGON ID:   z1693990
# DATE DUE:   3/23/16
#

assignment6.exe: assignment6main.cc assignment6.h assignment6.cc assignment5.cc
	g++ -std=c++11 -Wall -g assignment5.cc assignment6.cc assignment6main.cc -o assignment6.exe

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment6.exe
