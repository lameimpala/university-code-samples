#
# PROGRAM:    Assignment 11
# PROGRAMMER: Reid Wixom
# LOGON ID:   z1693990
# DATE DUE:   4/22/16
#

assignment11.exe: assignment11.cc
	g++ -g assignment11.cc -o assignment11.exe -L/usr/include/mysql -lmysqlclient -I/usr/include/mysql

# Pseudo-target to remove object code and executable files
clean:
	-rm assignment11.exe
