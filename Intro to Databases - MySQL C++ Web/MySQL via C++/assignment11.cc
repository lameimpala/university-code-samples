/*
# PROGRAM:    Assignment 11
# PROGRAMMER: Reid Wixom
# LOGON ID:   z1693990
# DATE DUE:   4/22/16
#
# Description: Interacts with a MySQL Database using c++
*/


#include <mysql.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <typeinfo>

using namespace std;

MYSQL *conn, mysql;
MYSQL_RES *res;
MYSQL_ROW row;

/*
Function: 
void get_boats()

Arguments: 
none

Returns:
void

Notes: 
Queries the MySQL database for information pertaining to boats, and prints it to the screen.
*/
void get_boats() {
	int query_state = mysql_query(conn, "SELECT FirstName, LastName, Address, SlipID, MarinaNum from MarinaSlip inner join Owner on MarinaSlip.OwnerNum = Owner.OwnerNum");
	if (query_state != 0) {
		cout << mysql_error(conn) << endl;
		return;
	}
	res = mysql_store_result(conn);

	cout << endl << setw(17) << "Marina" << setw(15) << "Name" << setw(20) << "Address" << setw(9) << "SlipID" << endl;
	cout << endl;
	while ((row=mysql_fetch_row(res)) != NULL) {
		string name;
		if (*row[4] == '1') {
			name = "Alexamara East";
		}
		else {
			name = "Alexamara Central";
		}
		cout << setw(17) << name << setw(15) << row[1] << setw(20) << row[2] << setw(9) << row[3] << endl;
	}
}

/*
Function: 
void get_maintenance()

Arguments: 
none

Returns:
void

Notes: 
Queries the MySQL database for information pertaining to Maintenance, and prints it to the screen.
*/
void get_maintenance() {
	int query_state = mysql_query(conn, "select BoatName, ServiceRequest.Description from MarinaSlip left join ServiceRequest on MarinaSlip.SlipID = ServiceRequest.SlipID order by BoatName");
	if (query_state != 0) {
		cout << mysql_error(conn) << endl;
	}
	res = mysql_store_result(conn);


	cout << endl << setw(15) << "Boat Name" << setw(80) << "Problem Description" << endl;
	cout << endl;
	while ((row=mysql_fetch_row(res)) != NULL) {
		if (row[1] == NULL) {
			cout << setw(15) << row[0] << setw(110) << "No Problems Have Been Reported For This Boat." <<  endl;
		}
		else {
			cout << setw(15) << row[0] << setw(110) << row[1] <<  endl;
		}
	}
}

/*
Function: 
void get_counts()

Arguments: 
none

Returns:
void

Notes: 
Queries the MySQL database for information pertaining to Service Counts, and prints it to the screen.
*/
void get_counts() {
	int query_state = mysql_query(conn, "select CategoryDescription, count(*) from ServiceCategory inner join ServiceRequest on ServiceRequest.CategoryNum = ServiceCategory.CategoryNum group by CategoryDescription");
	if (query_state != 0) {
		cout << mysql_error(conn) << endl;
	}
	res = mysql_store_result(conn);

	cout << endl << setw(50) << "Category" << setw(7) << "Count" << endl;
	cout << endl;
	while ((row=mysql_fetch_row(res)) != NULL) {
		cout << setw(50) << row[0] << setw(7) << row[1] <<  endl;
	}
}

/*
Function: 
int menu()

Arguments: 
none

Returns:
integer, choice of menu option

Notes: 
Prompts the user to select and option, and performs an action based on that choice
*/
int menu() {
	int choice;
	cout << endl << "Choose a Report" << endl <<
	"1. Boats" << endl <<
	"2. Maintenance" << endl <<
	"3. Service Counts" << endl <<
	"4. Exit" << endl;

	cin >> choice;
	cin.clear();
	switch (choice) {
		case 1: {
			get_boats();
			return 1;
		}
		case 2: {
			get_maintenance();
			return 2;
		}
		case 3: {
			get_counts();
			return 3;
		}
		case 4: {
			return 4;
		}
		default: {
			cout << endl << "Please enter a valid choice" << endl;
			return -1;
		}
	}
}


int main() {
	
	mysql_init(&mysql);

	int query_state;
	char *server = (char *)"courses";
	char *user = (char *)"z1693990";
	char *password = (char *)"1995Jan24";
	char *database = (char *)"z1693990";

	conn = mysql_real_connect(&mysql, server, user, password, database, 0, 0, 0);

	if (conn == NULL) {
		cout << endl << mysql_error(&mysql) << endl;
		return 0;
	}
	int x = 0;

	while ( x != 4) {
		x = menu();
	}
	
}
